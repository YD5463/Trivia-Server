#include "HighscoreResponse.h"

HighscoreResponse::HighscoreResponse(unsigned int status, Highscores highscores)
{
	this->status = status;
	this->highscores = new Highscores(highscores);
}

unsigned int HighscoreResponse::get_status()
{
	return status;
}

Highscores HighscoreResponse::get_highscores()
{
	return *highscores;
}
