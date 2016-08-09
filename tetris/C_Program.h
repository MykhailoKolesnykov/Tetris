#pragma once

#include "C_Game.h"
#include "C_Score.h"

class C_Program
{

private:

	C_Game * tetris;

	C_Score ** top10;

	char * top10_file;

public:

	C_Program();

	C_Program(char * file);

	void Main_menu();

	char* FixString(char* brokenString);

	bool Load();

	void Save();

	void Show_top_10();

	void Print_date_from_time_t(time_t date);

	void Sort_top_10();

	bool Check_top_file();

	bool All_Digits(char * arr);

	~C_Program();

};
