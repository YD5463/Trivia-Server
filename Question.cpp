#include "Question.h"

Question::Question(std::string m_question, std::vector<std::string> m_possible_answers, std::string m_correct_answer)
{
	this->m_question = m_question;
	this->m_possible_answers = m_possible_answers;
	this->m_correct_answer = m_correct_answer;
}

std::string Question::get_m_question()
{
	return m_question;
}

std::vector<std::string> Question::get_m_possible_answers()
{
	return m_possible_answers;
}

std::string Question::get_m_correct_answer()
{
	return m_correct_answer;
}
