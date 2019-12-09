#pragma once
#include "Communicator.h"
#include "IDatabase.h"
#include "RequestHandleFactory.h"
#include <iostream>

class Server
{
public:
	Server(IDatabase& db_type);
	void run();
private:
	IDatabase& m_database;
	Communicator m_communicator;
	RequestHandleFactory m_handle_factory;
};

