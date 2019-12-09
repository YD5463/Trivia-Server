#pragma once
class LeaveGameResponse
{
public:
	LeaveGameResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

