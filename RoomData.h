#pragma once
#include <string>

class RoomData
{
public:
	RoomData(std::string name,unsigned int max_players,unsigned int time_per_question, unsigned int question_count,bool is_active);
	std::string get_name();
	unsigned int get_id();
	unsigned int get_max_players();
	unsigned int get_time_per_question();
	unsigned int get_question_count();
	bool get_is_active(); 

private:
	std::string name;
	static unsigned int id;
	unsigned int max_players; //change from "string" (uml)
	unsigned int time_per_question;
	unsigned int question_count;
	bool is_active; //change from "int" (uml)
};

