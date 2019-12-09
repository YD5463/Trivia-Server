#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Room.h"
#include "LoggedUser.h"
#include "RoomData.h"

class RoomManager
{
public:
	RoomManager();
	~RoomManager();
	bool create_room(RoomData room_data,LoggedUser user);
	void delete_room(unsigned int room_id);
	bool add_user_to_room(unsigned int room_id, LoggedUser user);
	void delete_user_from_room(unsigned int room_id,LoggedUser user);
	std::vector<LoggedUser> get_users_in_room(unsigned int room_id);
	//unsigned int get_room_state(unsigned int room_id);
	std::vector<RoomData> get_rooms();
private:
	static std::map<unsigned int, Room*> m_rooms;//room id and room

};

