#include "PlayerResults.h"

PlayerResults::PlayerResults(std::string username, unsigned int correct_answer_count, unsigned int wrong_answer_count, unsigned int average_answer_time)
{
	this->username = username;
	this->correct_answer_count = correct_answer_count;
	this->wrong_answer_count = wrong_answer_count;
	this->average_answer_time = average_answer_time;
}

std::string PlayerResults::get_username()
{
	return username;
}

unsigned int PlayerResults::get_correct_answer_count()
{
	return correct_answer_count;
}

unsigned int PlayerResults::get_wrong_answer_count()
{
	return wrong_answer_count;
}

unsigned int PlayerResults::get_average_answer_time()
{
	return average_answer_time;
}
