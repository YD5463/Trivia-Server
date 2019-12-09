#include "RoomData.h"
unsigned int RoomData::id = 0;
RoomData::RoomData(std::string name,unsigned int max_players, unsigned int time_per_question,unsigned int question_count, bool is_active)
{
	this->name = name;
	id = id;
	this->max_players = max_players;
	this->time_per_question = time_per_question;
	this->question_count = question_count;
	this->is_active = is_active;
}

std::string RoomData::get_name()
{
	return name;
}

unsigned int RoomData::get_id()
{
	return id;
}

unsigned int RoomData::get_max_players()
{
	return max_players;
}

unsigned int RoomData::get_time_per_question()
{
	return time_per_question;
}

unsigned int RoomData::get_question_count()
{
	return question_count;
}

bool RoomData::get_is_active()
{
	return is_active;
}
