#include "C_Score.h"

C_Score::C_Score()
{
	game_score = 0;
	game_date = 0;
}

C_Score::C_Score(int new_score, time_t new_date)
{
	game_score = new_score;
	game_date = new_date;
}

time_t C_Score::Get_game_date()
{
	return game_date;
}

int C_Score::Get_game_score()
{
	return game_score;
}

void C_Score::Set_game_date(time_t new_date)
{
	game_date = new_date;
}

void C_Score::Set_game_score(int new_score)
{
	game_score = new_score;
}

C_Score::~C_Score()
{
}
