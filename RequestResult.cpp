#include "RequestResult.h"

RequestResult::RequestResult(std::string response, IRequestHandler* newHandler) : _response(response),_newHandler(newHandler)
{
}
/*
RequestResult::~RequestResult()
{
	delete _newHandler;
}
*/
IRequestHandler * RequestResult::get_newHandler()
{
	return _newHandler;
}
std::string RequestResult::get_response()
{
	return _response;
}
