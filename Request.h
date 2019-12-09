#pragma once
#include <time.h>
#include <iostream>
#include <string>
class Request
{
public:
	Request(unsigned int id, std::string buffer);
	unsigned int get_id();
	std::string get_buffer();
	void set_id(unsigned int id);
	void set_buffer(std::string buffer);
private:
	unsigned int _id;
	time_t _receivalTime;
	std::string _buffer;
};

