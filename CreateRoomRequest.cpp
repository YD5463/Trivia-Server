#include "CreateRoomRequest.h"


CreateRoomRequest::CreateRoomRequest(std::string room_name, unsigned int max_users, unsigned int question_count, unsigned int answer_timeout)
{
	this->room_name = room_name;
	this->max_users = max_users;
	this->question_count = question_count;
	this->answer_timeout = answer_timeout;
}

std::string CreateRoomRequest::get_room_name()
{
	return room_name;
}

unsigned int CreateRoomRequest::get_max_users()
{
	return max_users;
}

unsigned int CreateRoomRequest::get_question_count()
{
	return question_count;
}

unsigned int CreateRoomRequest::get_answer_timeout()
{
	return answer_timeout;
}
