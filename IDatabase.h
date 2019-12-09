#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "LoggedUser.h"
#include "Constants.h"
#include "Highscores.h"
#include "Question.h"
#include "GameData.h"

class IDatabase
{
public:
	IDatabase();
	//virtual ~IDatabase();
	virtual void set_highscores(std::map<LoggedUser, GameData> players_data) = 0;
	virtual std::map<LoggedUser,Highscores> getHighscores() = 0;
	virtual bool doesUserExiste(std::string username) = 0;
	virtual void remove_user(std::string username) = 0;
	virtual bool add_user(std::string username, std::string password, std::string email) = 0;
	virtual std::vector<Question> getQuestions(int count) = 0;
	virtual bool open() = 0;
	virtual void close() = 0;
	virtual bool user_is_registered(std::string username, std::string password) = 0;
};

