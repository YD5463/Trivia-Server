#pragma once
#include <string>
class PlayerResults
{
public:
	PlayerResults(std::string username,unsigned int correct_answer_count,unsigned int wrong_answer_count,unsigned int average_answer_time);
	std::string get_username();
	unsigned int get_correct_answer_count();
	unsigned int get_wrong_answer_count();
	unsigned int get_average_answer_time();
private:
	std::string username;
	unsigned int correct_answer_count;
	unsigned int wrong_answer_count;
	unsigned int average_answer_time;
};

