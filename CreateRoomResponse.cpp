#include "CreateRoomResponse.h"

CreateRoomResponse::CreateRoomResponse(unsigned int status)
{
	this->status = status;
}

unsigned int CreateRoomResponse::get_status()
{
	return status;
}
