#include "StartGameResponse.h"

StartGameResponse::StartGameResponse(unsigned int status)
{
	this->status = status;
}

unsigned int StartGameResponse::get_status()
{
	return status;
}
