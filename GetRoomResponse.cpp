#include "GetRoomResponse.h"

GetRoomResponse::GetRoomResponse(unsigned int status, std::vector<RoomData> rooms)
{
	this->status = status;
	this->rooms = rooms;
}

unsigned int GetRoomResponse::get_status()
{
	return status;
}

std::vector<RoomData> GetRoomResponse::get_rooms()
{
	return rooms;
}
