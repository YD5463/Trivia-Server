#pragma once
#include "IRequestHandler.h"
#include "LoginManager.h"
#include "RequestResult.h"
#include "Constants.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "LoginRequest.h"
#include "SignUpRequest.h"
#include "SignupResponse.h"
#include "LoginResponse.h"
#include "MenuRequestHandler.h"

class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler();
	~LoginRequestHandler();
	bool isRequestRelevant(Request request);
	RequestResult handleRequest(Request request);

private:
	LoginManager* m_loginManager;
	RequestResult login(Request request);
	RequestResult signup(Request request);
};

