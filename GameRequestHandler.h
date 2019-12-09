#pragma once
#include "IRequestHandler.h"
#include "Game.h"
#include "Room.h"
#include "LoggedUser.h"
#include "GameManager.h"
#include "RequestHandleFactory.h"
#include "RequestResult.h"
#include "Constants.h"
#include "JsonRequestPacketDeserializer.h"
#include "SubmitAnswerRequest.h"
#include "SubmitAnswerResponse.h"
#include "JsonResponsePacketSerializer.h"
#include "PlayerResults.h"
#include "GetGameResultsResponse.h"
#include "GetQuestionResponse.h"
#include "LeaveGameResponse.h"
#include "MenuRequestHandler.h"

class GameRequestHandler : public IRequestHandler
{
public:
	GameRequestHandler(Room room, LoggedUser user);
	~GameRequestHandler();
	bool isRequestRelevant(Request request);
	RequestResult handleRequest(Request request);
private:
	Game* m_game;
	LoggedUser* m_user;
	GameManager m_gameManager;
	RequestHandleFactory m_handlerFacroty;

	RequestResult getQuestion(Request request);
	RequestResult submitAnswer(Request request);
	RequestResult getGameResults(Request request);
	RequestResult leaveGame(Request request);
};

