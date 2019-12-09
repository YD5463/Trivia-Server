#include "CloseRoomResponse.h"

CloseRoomResponse::CloseRoomResponse(unsigned int status)
{
	this->status = status;
}

unsigned int CloseRoomResponse::get_status()
{
	return status;
}
