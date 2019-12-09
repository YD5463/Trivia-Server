#pragma once
class JoinRoomRequest
{
public:
	JoinRoomRequest(unsigned int room_id);
	unsigned int get_room_id();
private:
	unsigned int room_id;
};

