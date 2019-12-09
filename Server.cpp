#include "Server.h"

Server::Server(IDatabase& db_type) : m_database(db_type)
{
}

void Server::run()
{
	m_communicator.bind_and_listen();
}
