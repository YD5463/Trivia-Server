#include "LoggedUser.h"

LoggedUser::LoggedUser(std::string username) : m_username(username)
{}
/*
This function returns the username.
Input:None.
Output:String.
*/
std::string LoggedUser::get_username()const
{
	return m_username;
}

void LoggedUser::set_username(std::string username)
{
	m_username = username;
}

bool LoggedUser::operator<(const LoggedUser other)const
{
	return m_username<other.m_username;
}

