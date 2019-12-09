#include "GameRequestHandler.h"
#include <iostream>
GameRequestHandler::GameRequestHandler(Room room, LoggedUser user)
{
	m_user = new LoggedUser(user);
	m_game = new Game(m_gameManager.create_game(room));
}

GameRequestHandler::~GameRequestHandler()
{
	delete m_user;
	delete m_game;
}

bool GameRequestHandler::isRequestRelevant(Request request)
{
	return request.get_id()==GET_QUESTION_ID || request.get_id()==SUBMIT_ANSWER_ID || request.get_id()==GET_GAME_RESULTS_ID || request.get_id()==LEAVE_GAME_ID;
}

RequestResult GameRequestHandler::handleRequest(Request request)
{
	if (request.get_id() == GET_QUESTION_ID)
	{
		return getQuestion(request);
	}
	else if (request.get_id() == SUBMIT_ANSWER_ID)
	{
		return submitAnswer(request);
	}
	else if(request.get_id() == GET_GAME_RESULTS_ID)
	{
		return getGameResults(request);
	}
	else if (request.get_id() == LEAVE_GAME_ID)
	{
		return leaveGame(request);
	}
	return RequestResult("",nullptr);
}

RequestResult GameRequestHandler::getQuestion(Request request)
{
	JsonResponsePacketSerializer serilize;
	Question question = m_game->getQuestion();
	std::vector<std::string> answers;
	//std::cout << "answers:  " << std::endl;
	for (std::string answer : question.get_m_possible_answers())
	{
		//std::cout << answer << std::endl;
		answers.push_back(answer);
	}
	GetQuestionResponse get_question_response(SUCCESS_STATUS,question.get_m_question(),answers);
	return RequestResult(serilize.serializeResponse(get_question_response),this);
}

RequestResult GameRequestHandler::submitAnswer(Request request)
{
	JsonRequestPacketDeserializer desirilize;
	JsonResponsePacketSerializer serilize;
	SubmitAnswerRequest submit_answer_request = desirilize.deserializeSubmitAnswerRequest(request.get_buffer());
	int correct_answer_id = m_game->submit_answer();
	bool is_right = submit_answer_request.get_answer_id() == correct_answer_id;
	m_game->set_player_data(*m_user, is_right);
	SubmitAnswerResponse submit_answer_response(SUCCESS_STATUS,correct_answer_id,is_right);
	return RequestResult(serilize.serializeResponse(submit_answer_response),this);
}

RequestResult GameRequestHandler::getGameResults(Request request)
{
	std::vector<PlayerResults> results;
	JsonResponsePacketSerializer serilize;
	for (GameData game_data : m_game->get_game_results())
	{
		results.push_back(PlayerResults(m_user->get_username(), game_data.get_correct_answer_count(), game_data.get_wrong_answer_count(), game_data.get_average_time()));
	}
	GetGameResultsResponse get_game_result_response(SUCCESS_STATUS,results);
	return RequestResult(serilize.serializeResponse(get_game_result_response),this);
}

RequestResult GameRequestHandler::leaveGame(Request request)
{		
	if (m_game->remove_player(*m_user) == 0)
	{
		m_gameManager.delete_game(*m_game);
	}
	JsonResponsePacketSerializer serialize;
	return RequestResult(serialize.serializeResponse(LeaveGameResponse(SUCCESS_STATUS)),new MenuRequestHandler(m_user->get_username(),new SqliteDatabase()));
}
