#pragma once
class LogoutResponse
{
public:
	LogoutResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

