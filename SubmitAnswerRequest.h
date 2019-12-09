#pragma once
class SubmitAnswerRequest
{
public:
	SubmitAnswerRequest(unsigned int answer_id);
	unsigned int get_answer_id();
private:
	unsigned int answer_id;
};

