#pragma once
class LeaveRoomResponse
{
public:
	LeaveRoomResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

