#pragma once
class Highscores
{
public:
	Highscores();
	Highscores(unsigned int num_games,unsigned int right_answers,unsigned int worng_answers,float averag_time_for_answer);
	void set_num_games(unsigned int games);
	void set_right_answers(unsigned int right_ans);
	void set_worng_answers(unsigned int worng_ans);
	void set_averag_time_for_answer(float avg);
	unsigned int get_num_games();
	unsigned int get_right_answers();
	unsigned int get_worng_answers();
	float get_averag_time_for_answer();
private:
	unsigned int num_games;
	unsigned int right_answers;
	unsigned int worng_answers;
	float averag_time_for_answer;
};

