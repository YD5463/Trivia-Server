#include "JoinRoomRequest.h"

JoinRoomRequest::JoinRoomRequest(unsigned int room_id)
{
	this->room_id = room_id;
}

unsigned int JoinRoomRequest::get_room_id()
{
	return room_id;
}
