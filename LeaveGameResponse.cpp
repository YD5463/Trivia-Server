#include "LeaveGameResponse.h"

LeaveGameResponse::LeaveGameResponse(unsigned int status)
{
	this->status = status;
}

unsigned int LeaveGameResponse::get_status()
{
	return status;
}
