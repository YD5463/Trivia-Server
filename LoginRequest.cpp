#include "LoginRequest.h"

LoginRequest::LoginRequest(std::string username, std::string password) : _username(username),_password(password)
{}
/*
This function returns the userName.
Input:string.
Output:None.
*/
std::string LoginRequest::get_username()
{
	return _username;
}
/*
This function returns the password.
Input:None.
Output:string.
*/
std::string LoginRequest::get_password()
{
	return _password;
}
