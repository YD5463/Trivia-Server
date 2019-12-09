#include "GetRoomStateResponse.h"

GetRoomStateResponse::GetRoomStateResponse(unsigned int status, bool has_game_begun, std::vector<std::string> players, unsigned int question_count, unsigned int answer_timeout)
{
	this->status = status;
	this->has_game_begun = has_game_begun;
	this->players = players;
	this->question_count = question_count;
	this->answer_timeout = answer_timeout;
}

unsigned int GetRoomStateResponse::get_status()
{
	return status;
}

bool GetRoomStateResponse::get_has_game_begun()
{
	return has_game_begun;
}

std::vector<std::string> GetRoomStateResponse::get_players()
{
	return players;
}

unsigned int GetRoomStateResponse::get_question_count()
{
	return question_count;
}

unsigned int GetRoomStateResponse::get_answer_timeout()
{
	return answer_timeout;
}