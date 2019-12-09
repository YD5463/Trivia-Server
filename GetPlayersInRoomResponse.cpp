#include "GetPlayersInRoomResponse.h"

GetPlayersInRoomResponse::GetPlayersInRoomResponse(std::vector<std::string> players)
{
	this->players = players;
}

std::vector<std::string> GetPlayersInRoomResponse::get_players()
{
	return players;
}



