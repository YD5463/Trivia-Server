#pragma once
#include "IDatabase.h"
#include "SqliteDatabase.h"
#include "Game.h"
#include "Room.h"
#include <vector>

class GameManager
{
public:
	GameManager();
	~GameManager();
	Game create_game(Room room);
	void delete_game(Game game);
private:
	IDatabase* m_database;
	static std::vector<Game> m_games;
};

