#pragma once
class GetPlayersInRoomRequest
{
public:
	GetPlayersInRoomRequest(unsigned int room_id);
	unsigned int get_room_id();
private:
	unsigned int room_id;
};

