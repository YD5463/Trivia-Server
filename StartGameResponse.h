#pragma once
class StartGameResponse
{
public:
	StartGameResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

