#include "Communicator.h"
#include "IRequestHandler.h"
#include "LoginRequestHandler.h"

Communicator::Communicator()
{
	// notice that we step out to the global namespace
	// for the resolution of the function socket

	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	_serverSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Communicator::~Communicator()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		::closesocket(_serverSocket);
		for (auto const& x : m_client)//delete the allocated memory in the map 
		{
			delete x.second;
		}

	}
	catch (...) {}
}

/*
This function Connects the client to the server and opens a new theard.
Input:None.
Output:None.
*/
void Communicator::bind_and_listen()
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(PORT);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (::bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	if (::listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");

	while (true)
	{
		start_theard_for_new_client();
	}
}

/*
This function Receives information from the client and creates a relevant HANDLE.
If it fails, it will send an error message to the client.
Input:SOCKET.
Output:None.
*/
void Communicator::handleRequests(SOCKET client_socket)
{
	JsonResponsePacketSerializer serializer;
	int code = 0;
	int buffer_size = 0;
	std::string buffer = "";
	Request request(code, buffer);
	std::string response;
	RequestResult request_result("",nullptr);
	while (m_client[client_socket] != nullptr)
	{
		code = Helper::getMessageTypeCode(client_socket);
		if (code == EXIT)
		{
			break;
		}
		buffer_size = Helper::getIntPartFromSocket(client_socket, LENGHT_MSG_SIZE);
		buffer = Helper::getStringPartFromSocket(client_socket, buffer_size);
		request.set_id(code);
		request.set_buffer(buffer);
		if (m_client[client_socket]->isRequestRelevant(request))
		{
			request_result = m_client[client_socket]->handleRequest(request);
			response = request_result.get_response();
			//delete m_client[client_socket];
			m_client[client_socket] = request_result.get_newHandler();
		}
		else
		{
			ErrorResponse error_response("The request is not relevant!");
			response = serializer.serializeResponse(error_response);
		}
		Helper::sendData(client_socket, response);
	}
	closesocket(client_socket);
}

/*
This function opens a new theard to each client and insert them into the clients&sokect map.
using locks.
Input:None.
Output:None.
*/
void Communicator::start_theard_for_new_client()
{
	// this accepts the client and create a specific socket from server to this client
	SOCKET client_socket = ::accept(_serverSocket, NULL, NULL);
	std::thread* temp;
	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	// the function that handle the conversation with the client

	m_client.insert(std::make_pair(client_socket,new LoginRequestHandler()));

	temp = new std::thread(&Communicator::handleRequests, this, client_socket);

}
