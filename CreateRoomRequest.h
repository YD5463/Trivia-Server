#pragma once
#include <string>
class CreateRoomRequest
{
public:
	CreateRoomRequest(std::string room_name,unsigned int max_users, unsigned int question_count, unsigned int answer_timeout);
	std::string get_room_name();
	unsigned int get_max_users();
	unsigned int get_question_count();
	unsigned int get_answer_timeout();
private:
	std::string room_name;
	unsigned int max_users;
	unsigned int question_count;
	unsigned int answer_timeout;
};

