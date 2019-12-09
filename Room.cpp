#include "Room.h"
#include <iostream>//delelte after
Room::Room(RoomData room_data)
{
	m_metadata = new RoomData(room_data);
}

Room::Room(RoomData room_data, std::vector<LoggedUser> users)
{
	m_metadata = new RoomData(room_data);
	m_users = users;
}

Room::~Room()
{
	//delete m_metadata;
}

bool Room::addUser(LoggedUser user)
{
	//add new check if the game has begun
	if (m_metadata->get_is_active())
	{
		return false;
	}
	for (int i = 0; i < m_users.size(); i++)
	{
		if (user.get_username() == m_users[i].get_username())
		{
			return false;
		}
	}
	m_users.push_back(user);
	return true;
}

bool Room::removeUser(LoggedUser user)
{
	for (int i = 0; i < m_users.size(); i++)
	{
		if (m_users[i].get_username() == user.get_username())
		{
			m_users.erase(m_users.begin() + i);
			return true;
		}
	}
	return false;
}

std::vector<LoggedUser> Room::getAllUsers()
{
	return m_users;
}

RoomData Room::get_m_metadata()
{
	return *m_metadata;
}
