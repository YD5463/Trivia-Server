#include "LoginManager.h"

std::vector<LoggedUser> LoginManager::m_logged_user;

LoginManager::LoginManager(SqliteDatabase* sql_database) : m_database(sql_database)
{
}
/*
This function deallocate the memory.
Input:None.
Output:None.
*/
LoginManager::~LoginManager()
{
	delete m_database;
}
/*
This function signsUp USER.
Input:string*3.
Output:Bool.
*/
bool LoginManager::signup(std::string name, std::string pass, std::string email)
{
	return m_database->add_user(name, pass, email);
}
/*
This function logins an USER and checks if it already logged or registered.
Input:string*2.
Output:Bool.
*/
bool LoginManager::login(std::string name, std::string pass)
{
	bool success_login = false;
	if (m_database->user_is_registered(name,pass) && !is_user_already_logged(name))
	{
		success_login = true;
		LoggedUser temp(name);
		m_logged_user.push_back(name);
	}
	return success_login;
}
/*
This function logouts an USER and erase that user from the vector.
Input:string.
Output:None.
*/
void LoginManager::logout(std::string name)
{
	for (int i = 0; i < m_logged_user.size(); i++)
	{
		if (m_logged_user[i].get_username() == name)
		{
			m_logged_user.erase(m_logged_user.begin() + i);
		}
	}
}
/*
This function checks if the user is already logged.
Input:string.
Output:Bool.
*/
bool LoginManager::is_user_already_logged(std::string name)
{
	for (int i = 0; i < m_logged_user.size(); i++)
	{
		if (m_logged_user[i].get_username()==name)
		{
			return true;
		}
	}
	return false;
}
