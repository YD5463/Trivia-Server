#include "SubmitAnswerResponse.h"


SubmitAnswerResponse::SubmitAnswerResponse(unsigned int status, unsigned int correct_answer_id, bool is_right)
{
	this->status = status;
	this->correct_answer_id = correct_answer_id;
	this->is_right = is_right;
}

unsigned int SubmitAnswerResponse::get_status()
{
	return status;
}

unsigned int SubmitAnswerResponse::get_correct_answer_id()
{
	return correct_answer_id;
}

bool SubmitAnswerResponse::get_is_right()
{
	return is_right;
}
