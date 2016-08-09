#pragma once

#include <ctime>

#include "C_Field.h"

class C_Game
{

private:

	C_Field * game_field;

	C_1_figure_like_I * next_figure;

	C_1_figure_like_I * current_figure;

	time_t game_date;

	int current_level;
	
	int what_next;

	int what_prev;

	bool one_more_game;

public:
	
	C_Game();

	void Run();

	void End_of_game_menu();

	void Pause_of_game_menu(bool & game_process);

	bool One_more_game();

	time_t Get_game_date();

	int Get_game_score();

	~C_Game();

};
