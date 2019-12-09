#pragma once
#include <vector>
#include "PlayerResults.h"
class GetGameResultsResponse
{
public:
	GetGameResultsResponse(unsigned int status,std::vector<PlayerResults> results);
	unsigned int get_status();
	std::vector<PlayerResults> get_results();
private:
	unsigned int status;
	std::vector<PlayerResults> results;
};

