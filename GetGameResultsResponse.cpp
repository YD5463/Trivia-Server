#include "GetGameResultsResponse.h"

GetGameResultsResponse::GetGameResultsResponse(unsigned int status, std::vector<PlayerResults> results)
{
	this->status = status;
	this->results = results;
}

unsigned int GetGameResultsResponse::get_status()
{
	return status;
}

std::vector<PlayerResults> GetGameResultsResponse::get_results()
{
	return results;
}
