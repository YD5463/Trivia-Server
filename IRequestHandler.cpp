#include "IRequestHandler.h"

IRequestHandler::~IRequestHandler()
{
	delete request;
}
