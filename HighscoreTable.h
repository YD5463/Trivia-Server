#pragma once
#include "IDatabase.h"
#include "Highscores.h"
#include "LoggedUser.h"

class HighscoreTable
{
public:
	HighscoreTable(IDatabase& m_database);
	Highscores get_highscore(LoggedUser user);
private:
	IDatabase& m_database;
};