#pragma once
#include "LoginManager.h"
#include "RoomManager.h"
#include "HighscoreTable.h"
#include "LoggedUser.h"
#include "RoomData.h"
#include "GameManager.h"
#include "Game.h"
#include "LoggedUser.h"
#include <vector>
#include <string>
class LoginRequestHandler;
class MenuRequestHandler;
class RoomAdminRequestHandler;
class RoomMemberRequestHandler;
class GameRequestHandler;

class RequestHandleFactory 
{
public:
	RequestHandleFactory();
	~RequestHandleFactory();
	LoginRequestHandler create_login_request_handler();
	MenuRequestHandler createMenuRequestHandler(std::string username,IDatabase* database);
	RoomAdminRequestHandler createRoomAdminRequestHandler(RoomData room_data, LoggedUser user);
	RoomMemberRequestHandler createRoomMemberRequestHandler(RoomData room_data, LoggedUser user);
	GameRequestHandler createGameRequestHandler(Room room, LoggedUser user);
private:
	LoginManager* m_login_manager;
	HighscoreTable*  m_highscoreTable;
	RoomManager* m_roomManager;
	GameManager* m_gameManager;
	//SqliteDatabase* database;
};