#pragma once
#include "IRequestHandler.h"
#include "Room.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "RequestHandleFactory.h"
#include "CloseRoomResponse.h"
#include "StartGameResponse.h"
#include "GetRoomStateResponse.h"
#include "JsonResponsePacketSerializer.h"
#include "RoomData.h"
#include "RequestResult.h"
#include "Constants.h"
#include "Helper.h"
#include <vector>
#include <string>
#include "MenuRequestHandler.h"
#include "GameRequestHandler.h"

class MenuRequestHandler;

class RoomAdminRequestHandler : public IRequestHandler
{
public:
	RoomAdminRequestHandler(RoomData room_data,LoggedUser user);
	~RoomAdminRequestHandler();
	bool isRequestRelevant(Request request);
	RequestResult handleRequest(Request request);
private:
	Room* m_room;
	LoggedUser* m_user;
	RoomManager m_roomManager;
	RequestHandleFactory m_handlerFacroty;

	RequestResult closeRoom();
	RequestResult startGame(Request request);
	RequestResult getRoomState();
};