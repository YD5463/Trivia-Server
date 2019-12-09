#pragma once
class SubmitAnswerResponse
{
public:
	SubmitAnswerResponse(unsigned int status,unsigned int correct_answer_id, bool is_right);
	unsigned int get_status();
	unsigned int get_correct_answer_id();
	bool get_is_right();
private:
	unsigned int status;
	unsigned int correct_answer_id;
	bool is_right;
};

