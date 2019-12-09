#include "Game.h"
#include<iostream>
int Game::id = 0;

Game::Game(std::map<LoggedUser, GameData> players, std::vector<Question> questions)
{
	id++;
	m_players = players;
	m_questions = questions;
}

int Game::get_id()
{
	return id;
}

Question Game::getQuestion()
{
	std::cout << "question" << std::endl;
	for (int i = 0; i < m_questions.size(); i++)
	{
		std::cout << m_questions[i].get_m_question() << std::endl;
	}
	Question question = m_questions.back();
	std::cout << question.get_m_question() << std::endl;
	m_questions.pop_back();
	used_questions.push_back(question);
	return question;
}

int Game::submit_answer()
{
	Question question = used_questions.back();
	std::vector<std::string> possible_answers = question.get_m_possible_answers();
	int i;
	for (i = 0; i < possible_answers.size(); i++)
	{
		if (possible_answers[i] == question.get_m_correct_answer())
		{
			i++;
			break;
		}
	}
	return i;//i is the id of correct answer
}

int Game::remove_player(LoggedUser user)
{
	int num_players = 0;
	for (auto &player : m_players)
	{
		num_players++;
	}
	m_players.erase(user);
	return num_players--;
}

std::vector<GameData> Game::get_game_results()
{
	std::vector<GameData> results;
	for (auto result : m_players)
	{
		results.push_back(result.second);
	}
	return results;
}

void Game::set_player_data(LoggedUser user, bool is_right)
{
	if (is_right)
	{
		m_players[user].add_correct_answer_count();
	}
	else
	{
		m_players[user].add_wrong_answer_count();
	}
}

std::map<LoggedUser, GameData> Game::get_m_players()
{
	return m_players;
}
