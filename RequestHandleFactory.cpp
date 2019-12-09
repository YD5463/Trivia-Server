#include "RequestHandleFactory.h"
#include "LoginRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "GameRequestHandler.h"

RequestHandleFactory::RequestHandleFactory()
{
	//database = new SqliteDatabase();
}

RequestHandleFactory::~RequestHandleFactory()
{
	delete m_login_manager;
}

LoginRequestHandler RequestHandleFactory::create_login_request_handler()
{
	return LoginRequestHandler();
}

MenuRequestHandler RequestHandleFactory::createMenuRequestHandler(std::string username, IDatabase* database)
{
	return MenuRequestHandler(username,database);
}

RoomAdminRequestHandler RequestHandleFactory::createRoomAdminRequestHandler(RoomData room_data, LoggedUser user)
{
	return RoomAdminRequestHandler(room_data,user);
}

RoomMemberRequestHandler RequestHandleFactory::createRoomMemberRequestHandler(RoomData room_data, LoggedUser user)
{
	std::vector<LoggedUser> temp;
	return RoomMemberRequestHandler(room_data,user,temp);
}

GameRequestHandler RequestHandleFactory::createGameRequestHandler(Room room, LoggedUser user)
{
	return GameRequestHandler(room,user);
}

