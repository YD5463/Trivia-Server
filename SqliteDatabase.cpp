#include "SqliteDatabase.h"
int num_result;
std::map<LoggedUser, Highscores> highscores;
std::vector<Question> questions;

SqliteDatabase::SqliteDatabase()
{
	open();
}

SqliteDatabase::~SqliteDatabase()
{
	close();
}

/*
This function opens a new DB and creats the tables.
Input:None.
Output:Bool.
*/
bool SqliteDatabase::open()
{
	bool is_opened = true;
	int res = sqlite3_open(DB_FILE_NAME, &db);
	if (res != SQLITE_OK)
	{
		is_opened = false;
	}
	else
	{
		char* errMessage = nullptr;
		std::string str_statement = "CREATE TABLE IF NOT EXISTS User(username TEXT PRIMARY KEY,password TEXT,email TEXT);";
		res = sqlite3_exec(db, str_statement.c_str(), nullptr, nullptr, &errMessage);

		errMessage = nullptr;
		str_statement = "CREATE TABLE IF NOT EXISTS Question(question_id INTEGER PRIMARY KEY,question TEXT,correct_ans TEXT,ans2 TEXT,ans3 TEXT,ans4 TEXT);";
		res = sqlite3_exec(db, str_statement.c_str(), nullptr, nullptr, &errMessage);

		errMessage = nullptr;
		str_statement = "CREATE TABLE IF NOT EXISTS Game(game_id INTEGER PRIMARY KEY,status TEXT,start _time INTEGER,end_time INTEGER);";
		res = sqlite3_exec(db, str_statement.c_str(), nullptr, nullptr, &errMessage);

		errMessage = nullptr;
		str_statement = "CREATE TABLE IF NOT EXISTS Highscore(highscore_id INTEGER PRIMARY KEY,num_games INTEGER,right_answers INTEGER,worng_answers INTEGER,averag_time_for_answer REAL,user_id TEXT REFERENCES User(username));";
		res = sqlite3_exec(db, str_statement.c_str(), nullptr, nullptr, &errMessage);

	}
	return is_opened;
}
/*
This function closes the DB
Input:None.
Output:None.
*/
void SqliteDatabase::close()
{
	sqlite3_close(db);
	db = nullptr;
}
/*
This function the numer of users with the same name
Input:void*,int,char[][],char[][].
Output:int
*/
int get_number_callback(void *unused, int count, char **data, char **columns)
{
	num_result = atoi(data[0]);
	return 0;
}
int get_questions_callback(void *unused, int count, char **data, char **columns)
{
	std::vector<std::string> possible_answers;
	std::string question;
	std::string correct_answers;
	for (int i = 0; i < count; i++)
	{
		if (std::string(columns[i]) == "question")
		{
			question = std::string(data[i]);
		}
		if (std::string(columns[i]) == "correct_ans")
		{
			correct_answers = std::string(data[i]);
			possible_answers.push_back(std::string(data[i]));
		}
		if (std::string(columns[i]) == "ans2" || std::string(columns[i]) == "ans3" || std::string(columns[i]) == "ans4")
		{
			possible_answers.push_back(std::string(data[i]));
		}
		questions.push_back(Question(question, possible_answers, correct_answers));
	}
	return 0;
}
int get_highscore_callback(void *unused, int count, char **data, char **columns)
{
	int i;
	Highscores temp_highscore(0,0,0,0);
	LoggedUser user("");
	for (i = 0; i < count; i++)
	{
		if(std::string(columns[i]) == "user_id")
		{
			user.set_username(std::string(data[i]));
		}
		if (std::string(columns[i]) == "num_games")
		{
			temp_highscore.set_num_games(atoi(data[i]));
		}
		if (std::string(columns[i]) == "right_answers")
		{
			temp_highscore.set_right_answers(atoi(data[i]));
		}
		if (std::string(columns[i]) == "worng_answers")
		{
			temp_highscore.set_worng_answers(atoi(data[i]));
		}
		if (std::string(columns[i]) == "averag_time_for_answer")
		{
			temp_highscore.set_averag_time_for_answer(atof(data[i]));
		}
	}
	highscores.insert(std::pair<LoggedUser, Highscores>(user, temp_highscore));
	return 0;
}

void SqliteDatabase::set_highscores(std::map<LoggedUser, GameData> players_data)
{
	char* errMessage = nullptr;
	std::string str_statement;
	int res;
	for (auto& player : players_data)
	{
		str_statement = "INSERT INTO Highscore (right_answers,worng_answers,averag_time_for_answer,user_id) VALUES("+ std::to_string(player.second.get_correct_answer_count())+","+ std::to_string(player.second.get_wrong_answer_count())+","+ std::to_string(player.second.get_average_time())+",'"+ player.first.get_username()+"');";
		res = sqlite3_exec(db, str_statement.c_str(), nullptr, nullptr, &errMessage);
	}
}

std::map<LoggedUser, Highscores> SqliteDatabase::getHighscores()
{
	highscores.clear();
	char* errMessage = nullptr;
	std::string str_statement = "SELECT * FROM Highscore;";
	int res = sqlite3_exec(db, str_statement.c_str(), get_highscore_callback, nullptr, &errMessage);
	return highscores;
}

/*
I think thats a duplicate function of "user_is_registered" func!!
NEED TO CHECK THIS!!
*/
bool SqliteDatabase::doesUserExiste(std::string username)
{
	char* errMessage = nullptr;
	std::string str_statement = "SELECT COUNT(username) FROM User WHERE username='" + username + "';";
	int res = sqlite3_exec(db, str_statement.c_str(), get_number_callback, nullptr, &errMessage);
	return num_result == 1;
}
/*
This function checks if the user is already registered.
Input:String*2.
Output:Bool.
*/
bool SqliteDatabase::user_is_registered(std::string username,std::string password)
{
	char* errMessage = nullptr;
	std::string str_statement = "SELECT COUNT(username) FROM User WHERE username='" + username + "' AND password='"+password+"';";
	int res = sqlite3_exec(db, str_statement.c_str(), get_number_callback, nullptr, &errMessage);
	return num_result == 1;
}
/*
This function adds a new user.
Input:String*3.
Output:Bool.
*/
bool SqliteDatabase::add_user(std::string username, std::string password, std::string email)
{
	bool success_added = false;
	if (!doesUserExiste(username))
	{
		char* errMessage = nullptr;
		std::string str_statement = "INSERT INTO User VALUES('" + username + "','" + password + "','" + email + "');";
		int res = sqlite3_exec(db, str_statement.c_str(), nullptr, nullptr, &errMessage);
		success_added = true;
	}
	return success_added;
}
/*
This function removes an user.
Input:String.
Output:Bool.
*/
void SqliteDatabase::remove_user(std::string username)
{
	//need do add a checking for if the user exist and return boolean
	char* errMessage = nullptr;
	std::string str_statement = "DELETE FROM User WHERE username='" + username + "';";
	int res = sqlite3_exec(db, str_statement.c_str(), nullptr, nullptr, &errMessage);
}

std::vector<Question> SqliteDatabase::getQuestions(int count)
{
	char* errMessage = nullptr;
	std::string str_statement = "SELECT * FROM Question ORDER BY RANDOM() LIMIT "+std::to_string(count)+";";
	int res = sqlite3_exec(db, str_statement.c_str(), get_questions_callback, nullptr, &errMessage);
	return questions;
}
