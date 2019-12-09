#include "GetPlayersInRoomRequest.h"

GetPlayersInRoomRequest::GetPlayersInRoomRequest(unsigned int room_id)
{
	this->room_id = room_id;
}

unsigned int GetPlayersInRoomRequest::get_room_id()
{
	return room_id;
}
