#include "LoginResponse.h"

LoginResponse::LoginResponse(unsigned int status)
{
	this->status = status;
}

unsigned int LoginResponse::get_status()
{
	return status;
}

