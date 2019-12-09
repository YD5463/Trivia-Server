#include "MenuRequestHandler.h"

RoomManager MenuRequestHandler::m_roomManager;
MenuRequestHandler::MenuRequestHandler(std::string username, IDatabase* database)
{
	m_user = new LoggedUser(username);
	m_highscoreTable = new HighscoreTable(*database);
}

bool MenuRequestHandler::isRequestRelevant(Request request)
{
	return request.get_id()== SIGNOUT_ID || request.get_id() == GET_ROOMS_ID || request.get_id() == GET_PLAYERS_IN_ROOM_ID || request.get_id() == GET_HIGHSCORES_ID || request.get_id() == JOIN_ROOM_ID || request.get_id() == CREATE_ROOM_ID;
}

RequestResult MenuRequestHandler::handleRequest(Request request)
{
	if (request.get_id() == SIGNOUT_ID)
	{
		return signout(request);
	}
	else if (request.get_id() == GET_ROOMS_ID)
	{
		return getRooms(request);
	}
	else if (request.get_id() == GET_PLAYERS_IN_ROOM_ID)
	{
		return getPlayersInRoom(request);
	}
	else if (request.get_id() == GET_HIGHSCORES_ID)
	{
		return getHighscores(request);
	}
	else if (request.get_id() == JOIN_ROOM_ID)
	{
		return joinRoom(request);
	}
	else if (request.get_id() == CREATE_ROOM_ID)
	{
		return createRoom(request);
	}
	return RequestResult("",nullptr);
}

RequestResult MenuRequestHandler::signout(Request request)
{
	JsonResponsePacketSerializer serialize;
	LoginManager::logout(m_user->get_username());
	LogoutResponse logout_response(SUCCESS_STATUS);
	std::string response = serialize.serializeResponse(logout_response);
	return RequestResult(response, new LoginRequestHandler());
}

RequestResult MenuRequestHandler::getRooms(Request request)
{
	JsonResponsePacketSerializer serialize;
	GetRoomResponse	get_rooms_response(SUCCESS_STATUS,m_roomManager.get_rooms());
	std::string response = serialize.serializeResponse(get_rooms_response);
	return RequestResult(response, new MenuRequestHandler(m_user->get_username(),new SqliteDatabase()));
}

RequestResult MenuRequestHandler::getPlayersInRoom(Request request)
{
	JsonRequestPacketDeserializer deserialize;
	JsonResponsePacketSerializer serialize;
	std::vector<std::string> users_names;
	GetPlayersInRoomRequest	get_players_in_room_request = deserialize.deserializeGetPlayersInRoomRequest(request.get_buffer());
	for (LoggedUser& user : (m_roomManager.get_users_in_room(get_players_in_room_request.get_room_id())))
	{
		users_names.push_back(user.get_username());
	}
	std::string response = serialize.serializeResponse(GetPlayersInRoomResponse(users_names));
	return RequestResult(response, new MenuRequestHandler(m_user->get_username(), new SqliteDatabase()));
}

RequestResult MenuRequestHandler::getHighscores(Request request)
{
	JsonResponsePacketSerializer serialize;
	HighscoreResponse highscore_response(SUCCESS_STATUS,m_highscoreTable->get_highscore(*m_user));
	return RequestResult(serialize.serializeResponse(highscore_response), new MenuRequestHandler(m_user->get_username(), new SqliteDatabase()));
}

RequestResult MenuRequestHandler::joinRoom(Request request)
{
	JsonRequestPacketDeserializer desirialize;
	JsonResponsePacketSerializer serialize;
	JoinRoomRequest	join_room_request = desirialize.deserializeJoinRoomRequest(request.get_buffer());
	if (m_roomManager.add_user_to_room(join_room_request.get_room_id(), LoggedUser(m_user->get_username())))
	{
		return RequestResult(serialize.serializeResponse(JoinRoomResponse(SUCCESS_STATUS)), new RoomMemberRequestHandler(m_roomManager.get_rooms()[join_room_request.get_room_id()], *m_user, m_roomManager.get_users_in_room(join_room_request.get_room_id())));
	}
	return RequestResult(serialize.serializeResponse(JoinRoomResponse(FAILED_STATUS)), nullptr);
}
/*
Work
*/
RequestResult MenuRequestHandler::createRoom(Request request)
{
	JsonRequestPacketDeserializer desirialize;
	JsonResponsePacketSerializer serialize;
	CreateRoomRequest create_room_request = desirialize.deserializeCreateRoomRequest(request.get_buffer());
	RoomData room_data(create_room_request.get_room_name(), create_room_request.get_max_users(), create_room_request.get_answer_timeout(), create_room_request.get_question_count(), false);//check in what we need to init the is_active
	bool success = m_roomManager.create_room(room_data,*m_user);
	if (success)
	{
		//m_roomManager.get_users_in_room(room_data.get_id());
		return RequestResult(serialize.serializeResponse(CreateRoomResponse(SUCCESS_STATUS)), new RoomAdminRequestHandler(room_data, *m_user));
	}
	else
	{
		return RequestResult(serialize.serializeResponse(CreateRoomResponse(FAILED_STATUS)),this);
	}
}

