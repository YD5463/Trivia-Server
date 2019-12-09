#pragma once
#include <string>
#include <vector>

class GetRoomStateResponse
{
public:
	GetRoomStateResponse(unsigned int status,bool has_game_begun,std::vector<std::string> players,unsigned int question_count,unsigned int answer_timeout);
	unsigned int get_status();
	bool get_has_game_begun();
	std::vector<std::string> get_players();
	unsigned int get_question_count();
	unsigned int get_answer_timeout();
private:
	unsigned int status;
	bool has_game_begun;
	std::vector<std::string> players;
	unsigned int question_count;
	unsigned int answer_timeout;
};

