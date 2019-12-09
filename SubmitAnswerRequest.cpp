#include "SubmitAnswerRequest.h"

SubmitAnswerRequest::SubmitAnswerRequest(unsigned int answer_id)
{
	this->answer_id = answer_id;
}

unsigned int SubmitAnswerRequest::get_answer_id()
{
	return answer_id;
}
