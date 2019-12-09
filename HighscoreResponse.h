#pragma once
#include <vector>
#include "Highscores.h"
class HighscoreResponse
{
public:
	HighscoreResponse(unsigned int status, Highscores highscores);
	unsigned int get_status();
	Highscores get_highscores();
private:
	unsigned int status;
	Highscores* highscores;
};

