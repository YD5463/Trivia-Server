#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(RoomData room_data, LoggedUser user)
{
	m_user = new LoggedUser(user);
	std::vector<LoggedUser> users;
	users.push_back(*m_user);
	m_room = new Room(room_data,users);
}

RoomAdminRequestHandler::~RoomAdminRequestHandler()
{
	delete m_user;
	delete m_room;
}

bool RoomAdminRequestHandler::isRequestRelevant(Request request)
{
	return request.get_id()==CLOSE_ROOM_ID || request.get_id()==GET_ROOM_STATE_ID || request.get_id()==START_GAME_ID;
}

RequestResult RoomAdminRequestHandler::handleRequest(Request request)
{
	if (request.get_id() == CLOSE_ROOM_ID)
	{
		return closeRoom();
	}
	else if (request.get_id() == GET_ROOM_STATE_ID)
	{
		return getRoomState();
	}
	else
	{
		return startGame(request);
	}
}

RequestResult RoomAdminRequestHandler::closeRoom()
{
	m_roomManager.delete_room(m_room->get_m_metadata().get_id());
	JsonResponsePacketSerializer serialize;
	return RequestResult(serialize.serializeResponse(CloseRoomResponse(SUCCESS_STATUS)), new MenuRequestHandler(m_user->get_username(),new SqliteDatabase()));
}

RequestResult RoomAdminRequestHandler::startGame(Request request)
{
	JsonResponsePacketSerializer serilize;
	StartGameResponse start_game_response(SUCCESS_STATUS);
	return RequestResult(serilize.serializeResponse(start_game_response),new GameRequestHandler(*m_room, *m_user));
}

RequestResult RoomAdminRequestHandler::getRoomState()
{
	return RequestResult(Helper::get_room_state(*m_room), new RoomAdminRequestHandler(m_room->get_m_metadata(),*m_user));
}
