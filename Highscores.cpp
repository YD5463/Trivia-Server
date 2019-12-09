#include "Highscores.h"

Highscores::Highscores()
{
}

Highscores::Highscores(unsigned int num_games, unsigned int right_answers, unsigned int worng_answers, float averag_time_for_answer)
{
	this->num_games = num_games;
	this->right_answers = right_answers;
	this->worng_answers = worng_answers;
	this->averag_time_for_answer = averag_time_for_answer;
}

void Highscores::set_num_games(unsigned int games)
{
	num_games = games;
}

void Highscores::set_right_answers(unsigned int right_ans)
{
	right_answers = right_ans;
}

void Highscores::set_worng_answers(unsigned int worng_ans)
{
	worng_answers = worng_ans;
}

void Highscores::set_averag_time_for_answer(float avg)
{
	averag_time_for_answer = avg;
}

unsigned int Highscores::get_num_games()
{
	return num_games;
}

unsigned int Highscores::get_right_answers()
{
	return right_answers;
}

unsigned int Highscores::get_worng_answers()
{
	return worng_answers;
}

float Highscores::get_averag_time_for_answer()
{
	return averag_time_for_answer;
}
