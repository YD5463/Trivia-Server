#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(RoomData room_data, LoggedUser user, std::vector<LoggedUser> users)
{
	m_user = new LoggedUser(user);
	m_room = new Room(room_data,users);
}

RoomMemberRequestHandler::~RoomMemberRequestHandler()
{
	delete m_user;
	delete m_room;
}

bool RoomMemberRequestHandler::isRequestRelevant(Request request)
{
	return request.get_id()==GET_ROOM_STATE_ID || request.get_id()==LEAVE_ROOM_ID;
}

RequestResult RoomMemberRequestHandler::handleRequest(Request request)
{
	if (request.get_id() == GET_ROOM_STATE_ID)
	{
		return getRoomState(request);
	}
	else
	{
		return leaveRoom(request);
	}
}

RequestResult RoomMemberRequestHandler::leaveRoom(Request request)
{
	m_roomManager.delete_user_from_room(m_room->get_m_metadata().get_id(), *m_user);
	JsonResponsePacketSerializer serialize;
	std::string response = serialize.serializeResponse(LeaveRoomResponse(SUCCESS_STATUS));
	return RequestResult(response,new MenuRequestHandler(m_user->get_username(),new SqliteDatabase()));
}

RequestResult RoomMemberRequestHandler::getRoomState(Request request)
{
	return RequestResult(Helper::get_room_state(*m_room), new RoomMemberRequestHandler(m_room->get_m_metadata(),*m_user,m_room->getAllUsers()));
}
