#include "JsonResponsePacketSerializer.h"



JsonResponsePacketSerializer::JsonResponsePacketSerializer()
{
}


JsonResponsePacketSerializer::~JsonResponsePacketSerializer()
{
}
/*
This function serialize the error message.
Input:ErrorResponse.
Output:String.
*/
std::string JsonResponsePacketSerializer::serializeResponse(ErrorResponse error_response)
{
	json j;
	to_json(j, error_response);
	return j.dump();
}
/*
This function serialize the LoginResponse message.
Input:LoginResponse.
Output:String.
*/
std::string JsonResponsePacketSerializer::serializeResponse(LoginResponse login_response)
{
	json j;
	to_json(j, login_response);
	return j.dump();
}
/*
This function serialize the LoginResponse message.
Input:LoginResponse.
Output:String.
*/
std::string JsonResponsePacketSerializer::serializeResponse(SignupResponse signup_response)
{
	json j;
	to_json(j, signup_response);
	return j.dump();
}
/*
This function serialize the LogoutResponse message.
Input:LoginResponse.
Output:String.
*/
std::string JsonResponsePacketSerializer::serializeResponse(LogoutResponse logout_response)
{
	json j;
	to_json(j, logout_response);
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetRoomResponse get_room_response)
{
	std::vector<std::string> rooms;
	for (RoomData room_data : get_room_response.get_rooms())
	{
		rooms.push_back((json{ {"name",room_data.get_name()},{"id",room_data.get_id()},{"max_players",room_data.get_max_players()},{"time_per_question",room_data.get_time_per_question()},{"is_active",room_data.get_is_active()} }).dump());
	}
	return (json{ { "status",get_room_response.get_status()},{"rooms",rooms} }).dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse get_players_in_room_response)
{
	json j = json{ { "players",get_players_in_room_response.get_players() } };
	return j.dump();
}
/*
This function serialize the JoinRoomResponse message.
Input:LoginResponse.
Output:String.
*/
std::string JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse join_room_response)
{
	json j;
	to_json(j, join_room_response);
	return j.dump();
}
/*
This function serialize the CreateRoomResponse message.
Input:LoginResponse.
Output:String.
*/
std::string JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse create_room_response)
{
	json j;
	to_json(j, create_room_response);
	return j.dump();
}
/*
This function serialize the HighscoreResponse message.
Input:LoginResponse.
Output:String.
*/
std::string JsonResponsePacketSerializer::serializeResponse(HighscoreResponse highscore_response)
{
	Highscores highscores = highscore_response.get_highscores();
	json j = json{ { "status",highscore_response.get_status()},{"averag_time_for_answer", highscores.get_averag_time_for_answer()},{"num_games",highscores.get_num_games()},{"right_answers",highscores.get_right_answers()},{"worng_answers",highscores.get_worng_answers()} };
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(CloseRoomResponse close_room_response)
{
	json j;
	to_json(j, close_room_response);
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(StartGameResponse start_game_response)
{
	json j;
	to_json(j, start_game_response);
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse get_room_state_response)
{
	json j = json{ {"status",get_room_state_response.get_status()} ,{"has_game_begun",get_room_state_response.get_has_game_begun()},{"question_count",get_room_state_response.get_question_count()},{"answer_timeout",get_room_state_response.get_answer_timeout()},{"players",get_room_state_response.get_players()} };
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse leave_room_response)
{
	json j;
	to_json(j, leave_room_response);
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetQuestionResponse get_question_response)
{
	json j = { {"status",get_question_response.get_status()},{"question",get_question_response.get_question()},{"answers",get_question_response.get_answers()} };
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(SubmitAnswerResponse submit_answer_response)
{
	json j = json{ {"status",submit_answer_response.get_status()},{"correct_answer_id",submit_answer_response.get_correct_answer_id()}, {"is_right",submit_answer_response.get_is_right()} };
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetGameResultsResponse get_game_results_response)
{
	std::map <std::string, std::vector<unsigned int>> players_results;
	std::vector<unsigned int> temp_vector;
	for (PlayerResults player_result : get_game_results_response.get_results())
	{
		temp_vector.push_back(player_result.get_correct_answer_count());
		temp_vector.push_back(player_result.get_wrong_answer_count());
		temp_vector.push_back(player_result.get_average_answer_time());
		players_results.insert(std::make_pair(player_result.get_username(), temp_vector));
		temp_vector.clear();
	}
	json j = json{ {"status",get_game_results_response.get_status()},{"results",players_results} };
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(LeaveGameResponse leave_game_response)
{
	json j;
	to_json(j, leave_game_response);
	return j.dump();
}

void JsonResponsePacketSerializer::to_json(json & j, ErrorResponse & error_response)
{
	j = json{ { "message",error_response.get_message() } };
}
