#include "JoinRoomResponse.h"

JoinRoomResponse::JoinRoomResponse(unsigned int status)
{
	this->status = status;
}

unsigned int JoinRoomResponse::get_status()
{
	return status;
}
