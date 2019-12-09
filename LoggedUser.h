#pragma once
#include <string>

class LoggedUser 
{
public:
	LoggedUser(std::string username);
	std::string get_username()const;
	void set_username(std::string username);
	bool operator<(const LoggedUser other)const;
private:
	std::string m_username;
};

