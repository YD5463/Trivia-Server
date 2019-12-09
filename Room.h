#pragma once
#include <vector>
#include "LoggedUser.h"
#include "RoomData.h"
class Room
{
public:
	Room(RoomData room_data);
	Room(RoomData room_data, std::vector<LoggedUser> users);
	~Room();
	bool addUser(LoggedUser user);
	bool removeUser(LoggedUser user);
	std::vector<LoggedUser> getAllUsers();
	RoomData get_m_metadata();
private:
	std::vector<LoggedUser> m_users;
	RoomData* m_metadata;
};

