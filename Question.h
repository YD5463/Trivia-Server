#pragma once
#include <string>
#include <vector>

class Question
{
public:
	Question(std::string m_question,std::vector<std::string> m_possible_answers, std::string m_correct_answer);
	std::string get_m_question();
	std::vector<std::string> get_m_possible_answers();
	std::string get_m_correct_answer();
private:
	std::string m_question;
	std::vector<std::string> m_possible_answers;
	std::string m_correct_answer;
};

