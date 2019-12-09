#pragma once
#include "Request.h"
#include "RequestHandleFactory.h"
//#include "RequestResult.h"

class RequestResult;

class IRequestHandler
{
public:
	virtual ~IRequestHandler();
	virtual bool isRequestRelevant(Request request) = 0;
	virtual RequestResult handleRequest(Request request) = 0;
protected:
	RequestHandleFactory m_request_handle_factory;
	Request* request;
};