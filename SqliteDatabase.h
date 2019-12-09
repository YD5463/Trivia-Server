#pragma once
#include <utility>
#include <map>
#include <vector>
#include "Question.h"
#include "IDatabase.h"
#include "Constants.h"
#include "sqlite3.h"
#include "Highscores.h"
#include "LoggedUser.h"
#include <stdlib.h>

class SqliteDatabase : public IDatabase
{
public:
	SqliteDatabase();
	~SqliteDatabase();
	void set_highscores(std::map<LoggedUser, GameData> players_data) override;
	std::map<LoggedUser,Highscores> getHighscores() override;
	bool doesUserExiste(std::string username) override;
	bool user_is_registered(std::string username, std::string password) override;
	bool add_user(std::string username, std::string password, std::string email) override;
	void remove_user(std::string username) override;
	std::vector<Question> getQuestions(int count)override;
	bool open() override;
	void close() override;
private:
	sqlite3* db;
};
