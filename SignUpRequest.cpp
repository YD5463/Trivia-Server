#include "SignUpRequest.h"

SignUpRequest::SignUpRequest(std::string username, std::string password, std::string email) : _username(username),_password(password),_email(email)
{}

std::string SignUpRequest::get_username()
{
	return _username;
}

std::string SignUpRequest::get_password()
{
	return _password;
}

std::string SignUpRequest::get_email()
{
	return _email;
}
