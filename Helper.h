#pragma once
#include <vector>
#include <string>
#include <WinSock2.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Constants.h"
#include "JsonResponsePacketSerializer.h"
#include "LoggedUser.h"
#include "Room.h"

class Helper
{
public:
	Helper() = default;
	static int getMessageTypeCode(SOCKET sc);
	static int getIntPartFromSocket(SOCKET sc, int bytesNum);
	static std::string getStringPartFromSocket(SOCKET sc, int bytesNum);
	static void sendData(SOCKET sc, std::string message);
	static std::string getPaddedNumber(int num, int digits);
	static std::string get_room_state(Room m_room);
private:
	static char* Helper::getPartFromSocket(SOCKET sc, int bytesNum);
	static char* getPartFromSocket(SOCKET sc, int bytesNum, int flags);
};

