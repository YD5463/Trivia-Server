#pragma once
#include <map>
#include <vector>
#include "LoggedUser.h"
#include "GameData.h"
#include "Question.h"

class Game
{
public:
	Game(std::map<LoggedUser, GameData> players, std::vector<Question> questions);
	int get_id();
	Question getQuestion();
	int submit_answer();
	int remove_player(LoggedUser user);
	std::vector<GameData> get_game_results();
	void set_player_data(LoggedUser user,bool is_right);
	std::map<LoggedUser, GameData> get_m_players();
private:
	static int id;
	std::vector<Question> m_questions;
	std::vector<Question> used_questions;
	std::map<LoggedUser, GameData> m_players;
};

