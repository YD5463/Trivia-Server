#include "RoomManager.h"

std::map<unsigned int, Room*> RoomManager::m_rooms;
RoomManager::RoomManager()
{
}


RoomManager::~RoomManager()
{
}

bool RoomManager::create_room(RoomData room_data, LoggedUser user)
{
	//need to add checking if the parmeters are valid(for exmpale:if the room name is already exist...)
	for (auto & room : m_rooms)
	{
		if (room.second->get_m_metadata().get_name() == room_data.get_name())
		{
			return false;
		}
	}
	std::cout << "id = " << room_data.get_id() << std::endl;
	m_rooms[room_data.get_id()] = new Room(room_data);
	m_rooms[room_data.get_id()]->addUser(user);
	return true;
}


void RoomManager::delete_room(unsigned int room_id)
{
	m_rooms.erase(room_id);
}

bool RoomManager::add_user_to_room(unsigned int room_id, LoggedUser user)
{
	return m_rooms[room_id]->addUser(user);
}

void RoomManager::delete_user_from_room(unsigned int room_id, LoggedUser user)
{
	m_rooms[room_id]->removeUser(user);
}

std::vector<LoggedUser> RoomManager::get_users_in_room(unsigned int room_id)
{
	return m_rooms[room_id]->getAllUsers();
}

std::vector<RoomData> RoomManager::get_rooms()
{
	std::vector<RoomData> rooms;
	for (auto & room : m_rooms)
	{
		rooms.push_back(room.second->get_m_metadata());
	}
	return rooms;
}
