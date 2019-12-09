#pragma once
#include "Question.h"
class GameData
{
public:
	GameData();
	GameData(unsigned int correct_answer_count,unsigned int wrong_answer_count,unsigned int average_time);
	unsigned int get_correct_answer_count();
	unsigned int get_wrong_answer_count();
	unsigned int get_average_time();
	void add_correct_answer_count();
	void add_wrong_answer_count();
	//~GameData();
private:
	unsigned int correct_answer_count;
	unsigned int wrong_answer_count;
	unsigned int average_time;
};

