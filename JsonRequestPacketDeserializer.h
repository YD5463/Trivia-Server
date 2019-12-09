#pragma once
#include "LoginRequest.h"
#include "SignUpRequest.h"
#include "GetPlayersInRoomRequest.h"
#include "JoinRoomRequest.h"
#include "CreateRoomRequest.h"
#include "SubmitAnswerRequest.h"
#include <string>
#include <iostream>
#include "C:\Users\magshimim\cget\include\nlohmann\json.hpp"
using nlohmann::json;
class JsonRequestPacketDeserializer
{
public:
	JsonRequestPacketDeserializer();
	LoginRequest deserializeLoginRequest(std::string buffer);
	SignUpRequest deserializeSignupRequest(std::string buffer);
	GetPlayersInRoomRequest deserializeGetPlayersInRoomRequest(std::string buffer);
	JoinRoomRequest deserializeJoinRoomRequest(std::string buffer);
	CreateRoomRequest deserializeCreateRoomRequest(std::string buffer);
	SubmitAnswerRequest deserializeSubmitAnswerRequest(std::string buffer);
};

