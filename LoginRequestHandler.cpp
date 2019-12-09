#include "LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler()
{
	m_loginManager = new LoginManager(new SqliteDatabase());
}
/*
This function deallocate the memory.
Input:None.
Output:None.
*/
LoginRequestHandler::~LoginRequestHandler()
{
	delete m_loginManager;
}
/*
This function checks if the requset is relevant.
Input:Requset.
Output:Bool.
*/
bool LoginRequestHandler::isRequestRelevant(Request request)
{
	return request.get_id() == SIGNUP_ID || request.get_id() == LOGIN_ID;
}
/*
This function Redirects the program to the relevant function.
Input:Requset.
Output:RequsetResult.
*/
RequestResult LoginRequestHandler::handleRequest(Request request)
{
	if (request.get_id() == LOGIN_ID)
	{
		return login(request);
	}
	else if (request.get_id() == SIGNUP_ID)
	{
		return signup(request);
	}
	return RequestResult("", nullptr);
}
/*
This function logins a new user and send response to the client.
Input:Requset.
Output:RequsetResult.
*/
RequestResult LoginRequestHandler::login(Request request)
{
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	std::string response;
	LoginRequest login_request = deserializer.deserializeLoginRequest(request.get_buffer());
	bool success = m_loginManager->login(login_request.get_username(), login_request.get_password());
	if (success)
	{
		LoginResponse login_response(SUCCESS_STATUS);
		response = serializer.serializeResponse(login_response);
		RequestResult result(response, new MenuRequestHandler(login_request.get_username(), new SqliteDatabase()));
		return result;
	}
	else
	{
		//need do to serialize to LoginResponse with failed status
		LoginResponse login_response(FAILED_STATUS);
		response = serializer.serializeResponse(login_response);
		RequestResult result(response, new LoginRequestHandler());
		return result;
	}
}
/*
This function SignsUp a new user and send response to the client.
Input:Requset.
Output:RequsetResult.
*/
RequestResult LoginRequestHandler::signup(Request request)
{
	JsonRequestPacketDeserializer deserializer;
	JsonResponsePacketSerializer serializer;
	std::string response;
	SignUpRequest signup_request = deserializer.deserializeSignupRequest(request.get_buffer());
	bool success = m_loginManager->signup(signup_request.get_username(), signup_request.get_password(), signup_request.get_email());
	if (success)
	{
		SignupResponse signup_response(SUCCESS_STATUS);
		response = serializer.serializeResponse(signup_response);
		MenuRequestHandler menu_request_handler(signup_request.get_username(),new SqliteDatabase());
		RequestResult result(response, &menu_request_handler);
		return result;
	}
	else
	{
		SignupResponse signup_response(FAILED_STATUS);
		response = serializer.serializeResponse(signup_response);
		RequestResult result(response, this);
		return result;
	}
}