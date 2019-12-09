#pragma once
#include <string>
class SignUpRequest
{
public:
	SignUpRequest(std::string username,std::string password,std::string email);
	std::string get_username();
	std::string get_password();
	std::string get_email();
private:
	std::string _username;
	std::string _password;
	std::string _email;
};

