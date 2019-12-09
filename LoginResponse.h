#pragma once
class LoginResponse
{
public:
	LoginResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

