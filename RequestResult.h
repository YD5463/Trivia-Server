#pragma once
#include <string>
#include "RequestHandleFactory.h"

class IRequestHandler;
class RequestResult
{
public:
	RequestResult(std::string response, IRequestHandler* newHandler);
	//~RequestResult();
	IRequestHandler* get_newHandler();
	std::string get_response();
private:
	std::string _response;
	IRequestHandler* _newHandler;

};

