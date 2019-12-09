#include "LeaveRoomResponse.h"

LeaveRoomResponse::LeaveRoomResponse(unsigned int status)
{
	this->status = status;
}

unsigned int LeaveRoomResponse::get_status()
{
	return status;
}
