#include "HighscoreTable.h"

HighscoreTable::HighscoreTable(IDatabase& database):m_database(database)
{
}

Highscores HighscoreTable::get_highscore(LoggedUser user)
{
	return m_database.getHighscores()[user];
}

