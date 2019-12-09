#pragma once
#include <string>
class LoginRequest
{
public:
	LoginRequest(std::string username, std::string password);
	std::string get_username();
	std::string get_password();
private:
	std::string _username;
	std::string _password;
};

