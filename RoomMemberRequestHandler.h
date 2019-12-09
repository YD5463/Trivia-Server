#pragma once
#include "IRequestHandler.h"
#include "Room.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "RequestHandleFactory.h"
#include "RoomData.h"
#include "RequestResult.h"
#include "LeaveRoomResponse.h"
#include "JsonResponsePacketSerializer.h"
#include "MenuRequestHandler.h"
#include "Helper.h"
#include<vector>
#include <string>

class MenuRequestHandler;

class RoomMemberRequestHandler : public IRequestHandler
{
public:
	RoomMemberRequestHandler(RoomData room_data, LoggedUser user,std::vector<LoggedUser> users);
	~RoomMemberRequestHandler();
	bool isRequestRelevant(Request request);
	RequestResult handleRequest(Request request);
private:
	Room* m_room;
	LoggedUser* m_user;
	RoomManager m_roomManager;
	RequestHandleFactory m_handlerFacroty;

	RequestResult leaveRoom(Request request);
	RequestResult getRoomState(Request request);
};

