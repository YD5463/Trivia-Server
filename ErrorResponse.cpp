#include "ErrorResponse.h"

/*
This function initalize the error message.
Input:string.
Output:None.
*/
ErrorResponse::ErrorResponse(std::string message)
{
	this->message = message;
}

/*
This function returns the error msg.
Input:None.
Output:string.
*/
std::string ErrorResponse::get_message()
{
	return message;
}

