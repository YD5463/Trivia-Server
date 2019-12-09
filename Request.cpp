#include "Request.h"

Request::Request(unsigned int id, std::string buffer) : _id(id), _buffer(buffer)
{
	time(&_receivalTime);
}

unsigned int Request::get_id()
{
	return _id;
}
std::string Request::get_buffer()
{
	return _buffer;
}

void Request::set_id(unsigned int id)
{
	_id = id;
}

void Request::set_buffer(std::string buffer)
{
	_buffer = buffer;
}

