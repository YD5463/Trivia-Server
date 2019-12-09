#pragma once
class JoinRoomResponse
{
public:
	JoinRoomResponse(unsigned int status);
	unsigned int get_status();
private:
	unsigned int status;
};