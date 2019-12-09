#pragma once
#include <string>

class ErrorResponse
{
public:
	ErrorResponse(std::string message);
	std::string get_message();
private:
	std::string message;
};

