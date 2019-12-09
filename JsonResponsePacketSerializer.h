#pragma once
#include "ErrorResponse.h"
#include "LoginResponse.h"
#include "SignupResponse.h"
#include "LogoutResponse.h"
#include "GetRoomResponse.h"
#include "GetPlayersInRoomResponse.h"
#include "JoinRoomResponse.h"
#include "CreateRoomResponse.h"
#include "HighscoreResponse.h"
#include "Highscores.h"
#include "CloseRoomResponse.h"
#include "StartGameResponse.h"
#include "GetRoomStateResponse.h"
#include "LeaveRoomResponse.h"
#include "GetQuestionResponse.h"
#include "SubmitAnswerResponse.h"
#include "GetGameResultsResponse.h"
#include "LeaveGameResponse.h"
#include <string>

#include "C:\Users\magshimim\cget\include\nlohmann\json.hpp"
using nlohmann::json;

class JsonResponsePacketSerializer
{
public:
	JsonResponsePacketSerializer();
	~JsonResponsePacketSerializer();
	std::string serializeResponse(ErrorResponse error_response);
	std::string serializeResponse(LoginResponse login_response);
	std::string serializeResponse(SignupResponse signup_response);

	std::string serializeResponse(LogoutResponse logout_response);
	std::string serializeResponse(GetRoomResponse get_room_response);
	std::string serializeResponse(GetPlayersInRoomResponse get_players_in_room_response);
	std::string serializeResponse(JoinRoomResponse join_room_response);
	std::string serializeResponse(CreateRoomResponse create_room_response);
	std::string serializeResponse(HighscoreResponse highscore_response);

	std::string serializeResponse(CloseRoomResponse close_room_response);
	std::string serializeResponse(StartGameResponse start_game_response);
	std::string serializeResponse(GetRoomStateResponse get_room_state_response);
	std::string serializeResponse(LeaveRoomResponse leave_room_response);

	std::string serializeResponse(GetQuestionResponse get_question_response);
	std::string serializeResponse(SubmitAnswerResponse submit_answer_response);
	std::string serializeResponse(GetGameResultsResponse get_game_results_response);
	std::string serializeResponse(LeaveGameResponse leave_game_response);
private:
	template <typename T>
	void to_json(json& j, T& t)//maybe dangerous
	{
		j = json{ { "status",t.get_status() } };
	}
	void to_json(json& j, ErrorResponse& error_response);
};

