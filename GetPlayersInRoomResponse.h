#pragma once
#include <vector>
#include <string>
#include "LoggedUser.h"
class GetPlayersInRoomResponse
{
public:
	GetPlayersInRoomResponse(std::vector<std::string> players);
	std::vector<std::string> get_players();
private:
	std::vector<std::string> players;
};

