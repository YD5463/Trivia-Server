#pragma once
#include <vector>
#include "RoomData.h"

class GetRoomResponse
{
public:
	GetRoomResponse(unsigned int status, std::vector<RoomData> rooms);
	unsigned int get_status();
	std::vector<RoomData> get_rooms();
private:
	unsigned int status;
	std::vector<RoomData> rooms;
};

