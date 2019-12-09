#pragma once
#pragma comment (lib, "ws2_32.lib")
#include "Server.h"
#include "WSAInitializer.h"
#include "SqliteDatabase.h"

void main()
{
	try
	{
		WSAInitializer wsaInit;
		SqliteDatabase sqlite_db;
		Server server(sqlite_db);

		server.run();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
}