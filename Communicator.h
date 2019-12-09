#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <map>
#include <utility> 
#include <thread>
#include <mutex>
#include "IRequestHandler.h"
#include "RequestHandleFactory.h"
#include <WinSock2.h>
#include <Windows.h>
#include "Constants.h"
#include "Helper.h"
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "ErrorResponse.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"
#include "LoginRequest.h"
#include "RequestResult.h"

class Communicator
{
public:
	Communicator();
	~Communicator();
	void bind_and_listen();
	void handleRequests(SOCKET client_socket);
private:
	std::map<SOCKET, IRequestHandler*> m_client;
	SOCKET _serverSocket;
	std::mutex mtx;
	RequestHandleFactory m_handlerFactory;
	void start_theard_for_new_client();
};