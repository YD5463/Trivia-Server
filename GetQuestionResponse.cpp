#include "GetQuestionResponse.h"

GetQuestionResponse::GetQuestionResponse(unsigned int status, std::string question, std::vector<std::string> answers)
{
	this->status = status;
	this->question = question;
	this->answers = answers;
}

unsigned int GetQuestionResponse::get_status()
{
	return status;
}

std::string GetQuestionResponse::get_question()
{
	return question;
}

std::vector<std::string> GetQuestionResponse::get_answers()
{
	return answers;
}
