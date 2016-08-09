#pragma once

#include <ctime>

class C_Score
{

private:
	
	int game_score;

	time_t game_date;
	
public:

	C_Score();

	C_Score(int new_score, time_t new_date);

	time_t Get_game_date();

	int Get_game_score();

	void Set_game_date(time_t new_date);

	void  Set_game_score(int new_score);

	~C_Score();

};
