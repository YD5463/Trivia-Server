#include "SignupResponse.h"

SignupResponse::SignupResponse(unsigned int status)
{
	this->status = status;
}

unsigned int SignupResponse::get_status()
{
	return status;
}

