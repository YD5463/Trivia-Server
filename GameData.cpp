#include "GameData.h"


GameData::GameData()
{

}

GameData::GameData(unsigned int correct_answer_count, unsigned int wrong_answer_count, unsigned int average_time)
{
	this->correct_answer_count = correct_answer_count;
	this->wrong_answer_count = wrong_answer_count;
	this->average_time = average_time;
}

unsigned int GameData::get_correct_answer_count()
{
	return correct_answer_count;
}

unsigned int GameData::get_wrong_answer_count()
{
	return wrong_answer_count;
}

unsigned int GameData::get_average_time()
{
	return average_time;
}

void GameData::add_correct_answer_count()
{
	correct_answer_count++;
}

void GameData::add_wrong_answer_count()
{
	wrong_answer_count++;
}
