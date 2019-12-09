#pragma once
#include "IDatabase.h"
#include "LoggedUser.h"
#include <vector>
#include <string>
#include "SqliteDatabase.h"

class LoginManager
{
public:
	LoginManager(SqliteDatabase* sql_database);
	~LoginManager();
	bool signup(std::string name, std::string pass, std::string email);
	bool login(std::string name, std::string pass);
	static void logout(std::string name);
private:
	IDatabase* m_database;
	static std::vector<LoggedUser> m_logged_user;//remeber to fix this bug(make this verible static)
	bool is_user_already_logged(std::string name);
};

