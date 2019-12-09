#pragma once
class SignupResponse
{
public:

	SignupResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

