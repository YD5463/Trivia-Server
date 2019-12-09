#pragma once
class CloseRoomResponse
{
public:
	CloseRoomResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

