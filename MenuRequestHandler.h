#pragma once
#include <string>
#include "IRequestHandler.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "HighscoreTable.h"
#include "RequestHandleFactory.h"
#include "RequestResult.h"
#include "Request.h"
#include "Constants.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "JoinRoomResponse.h"
#include "LoginRequestHandler.h"
#include "LogoutResponse.h"
#include "GetRoomResponse.h"
#include "GetPlayersInRoomRequest.h"
#include "GetPlayersInRoomResponse.h"
#include "CreateRoomRequest.h"
#include "HighscoreResponse.h"
#include "RoomData.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"

class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler(std::string username,IDatabase* database);
	bool isRequestRelevant(Request request) override;
	RequestResult handleRequest(Request request) override;
private:
	LoggedUser* m_user;
	static RoomManager m_roomManager;
	HighscoreTable* m_highscoreTable;
	RequestHandleFactory m_handlerFacroty;

	RequestResult signout(Request request);
	RequestResult getRooms(Request request);
	RequestResult getPlayersInRoom(Request request);
	RequestResult getHighscores(Request request);
	RequestResult joinRoom(Request request);
	RequestResult createRoom(Request request);

};