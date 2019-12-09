#pragma once
#include <string>
#include <vector>
#include <map>
class GetQuestionResponse
{
public:
	GetQuestionResponse(unsigned int status,std::string question, std::vector<std::string> answers);
	unsigned int get_status();
	std::string get_question();
	std::vector<std::string> get_answers();
private:
	unsigned int status;
	std::string question;
	std::vector<std::string> answers;
};

