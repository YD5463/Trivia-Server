#include "GameManager.h"

std::vector<Game> GameManager::m_games;

GameManager::GameManager()
{
	m_database = new SqliteDatabase();
}

GameManager::~GameManager()
{
}

Game GameManager::create_game(Room room)
{
	std::map<LoggedUser, GameData> players;
	for (LoggedUser user : room.getAllUsers())
	{
		players.insert(std::make_pair(user, GameData(0, 0, 0)));
	}
	Game game(players,m_database->getQuestions(room.get_m_metadata().get_question_count()));
	m_games.push_back(game);
	return game;
}

void GameManager::delete_game(Game game)
{
	for (int i = 0; i < m_games.size(); i++)
	{
		if (m_games[i].get_id() == game.get_id())
		{
			m_games.erase(m_games.begin() + i);
			m_database->set_highscores(game.get_m_players());
			break;
		}
	}
}
