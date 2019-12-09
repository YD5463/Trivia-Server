#pragma once
class CreateRoomResponse
{
public:
	CreateRoomResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};

