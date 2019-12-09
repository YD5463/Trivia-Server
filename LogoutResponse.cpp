#include "LogoutResponse.h"


LogoutResponse::LogoutResponse(unsigned int status)
{
	this->status = status;
}

unsigned int LogoutResponse::get_status()
{
	return status;
}
