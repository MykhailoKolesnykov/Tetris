#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>

#include "C_Program.h"

using namespace std;

C_Program::C_Program()
{
}

C_Program::C_Program(char * file)
{
	tetris = new C_Game();

	top10_file = FixString(file);

	if (!Load())
	{
		top10 = new C_Score * [10];

		for (int i = 0; i < 10; ++i)
		{
			top10[i] = new C_Score(0, time(NULL));
		}
	}

	Sort_top_10();
	
	Save();

}

void C_Program::Main_menu()
{
	
	int menu_left_edge = 35;
	int top_menu = 11;
	int down_menu = top_menu + 4;
	
	COORD position;

	position.X = menu_left_edge;
	position.Y = top_menu - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << "TETPIC";

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	position.X = menu_left_edge;
	position.Y = top_menu;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "ÍÎÂÀ ÃÐÀ";

	position.X = menu_left_edge;
	position.Y = top_menu + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "ÐÅÊÎÐÄÈ";

	position.X = menu_left_edge;
	position.Y = down_menu;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "ÂÈÕ²Ä";
	
	position.X = menu_left_edge;
	position.Y = top_menu;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	
	bool exit = false;
	
	while (!exit)
	{
				
		switch (_getch())
		{

		case 72: // up
		{
			if (position.Y == top_menu)
			{
				
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
								
				cout << "ÍÎÂÀ ÃÐÀ";

				
				position.Y = down_menu;

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY );
				cout << "ÂÈÕ²Ä";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			if (position.Y == top_menu + 2)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÐÅÊÎÐÄÈ";
								
				position.Y = top_menu;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÍÎÂÀ ÃÐÀ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			if (position.Y == down_menu)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÂÈÕ²Ä";
								
				position.Y = top_menu + 2;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÐÅÊÎÐÄÈ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}

			break;
		}

		case 80: // down
		{
			if (position.Y == down_menu)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÂÈÕ²Ä";
								
				
				position.Y = top_menu;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÍÎÂÀ ÃÐÀ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			if (position.Y == top_menu + 2)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÐÅÊÎÐÄÈ";

				
				position.Y = down_menu;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÂÈÕ²Ä";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			if (position.Y == top_menu)
			{

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÍÎÂÀ ÃÐÀ";

				
				position.Y = top_menu + 2;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÐÅÊÎÐÄÈ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}

			break;
		}
		case 13: // enter
		{
			if (position.Y == down_menu) exit = true;

			if (position.Y == top_menu)
			{
				while (true)
				{
					delete tetris;
					tetris = new C_Game();
					tetris->Run();

					if (tetris->Get_game_score() >= top10[9]->Get_game_score())
					{
						top10[9]->Set_game_score(tetris->Get_game_score());
						top10[9]->Set_game_date(tetris->Get_game_date());
						Sort_top_10();
						Save();
					}

					if (!tetris->One_more_game())
					{
						system("cls");

						COORD position;

						position.X = menu_left_edge;
						position.Y = top_menu - 2;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

						cout << "TETPIC";

						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);

						position.X = menu_left_edge;
						position.Y = top_menu;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
						cout << "ÍÎÂÀ ÃÐÀ";

						position.X = menu_left_edge;
						position.Y = top_menu + 2;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "ÐÅÊÎÐÄÈ";

						position.X = menu_left_edge;
						position.Y = down_menu;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "ÂÈÕ²Ä";

						position.X = menu_left_edge;
						position.Y = top_menu;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

						break;
					}
				}


			}

			if (position.Y == top_menu + 2)
			{
						Show_top_10();

						system("cls");

						position.X = menu_left_edge;
						position.Y = top_menu - 2;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

						cout << "TETPIC";

						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);

						position.X = menu_left_edge;
						position.Y = top_menu;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
						cout << "ÍÎÂÀ ÃÐÀ";

						position.X = menu_left_edge;
						position.Y = top_menu + 2;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "ÐÅÊÎÐÄÈ";

						position.X = menu_left_edge;
						position.Y = down_menu;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "ÂÈÕ²Ä";

						position.X = menu_left_edge;
						position.Y = top_menu;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			}

			break;
		}
		case 27: // escape
		{
			exit = true;
			
			break;
		}
		}
	}

	system("cls");

	position.X = 35;
	position.Y = 11;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "ÁÓÂÀÉ :)";

	//Sleep(300);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);

}

char * C_Program::FixString(char* brokenString)
{
	int length = strlen(brokenString) + 1;
	char* fixedString = new char[length];
	strcpy_s(fixedString, length, brokenString);

	return fixedString;
}

bool C_Program::Load()
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	SetConsoleTitle(L"TETPIC");

	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = 80;
	scrn.Y = 25;

	SMALL_RECT src = { 0, 0, scrn.X - 1, scrn.Y - 1 };

	SetConsoleScreenBufferSize(hConsole, scrn);

	SetConsoleWindowInfo(hConsole, TRUE, &src);

	SetWindowPos(FindWindow(NULL, L"TETPIC"), HWND_TOP, 200, 100, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);


	ifstream s_fin(top10_file);

	if (s_fin)
	{
		top10 = new C_Score *[10];

		int tmp_score = -1;
		int tmp_date = -1;

		time_t null_date = time(NULL);

		streambuf * s_cinbuf = cin.rdbuf();

		cin.rdbuf(s_fin.rdbuf());
		
		for (int i = 0; i < 10; ++i)
		{
			cin >> tmp_score;

			cin >> tmp_date;
			
			if (tmp_score >= 0 && tmp_date >= 0) top10[i] = new C_Score(tmp_score, tmp_date);
			else top10[i] = new C_Score(0, null_date);

			tmp_score = -1;
			tmp_date = -1;

		}
		
		cin.rdbuf(s_cinbuf);

		s_fin.close();

		for (int i = 0; i < 9; ++i)
		{

			if (top10[i]->Get_game_score() == top10[i + 1]->Get_game_score()
				&& top10[i]->Get_game_date() == top10[i + 1]->Get_game_date())
			{
				delete top10[i];
				top10[i] = new C_Score(0, null_date);
			}
		}

		if (Check_top_file()) return true;

		else
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			COORD position;

			position.X = 25;
			position.Y = 11;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "ÔÀÉË Ç ÐÅÊÎÐÄÀÌÈ ÏÎØÊÎÄÆÅÍÎ.";
			
			position.X = 25;
			position.Y = 13;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << " ÄÀÍ² ÏÐÎ ÐÅÊÎÐÄÈ ÎÁÍÓËÅÍÎ.";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);

			system("pause");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

			system("cls");
		}

	}
	else
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		COORD position;

		position.X = 25;
		position.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "ÔÀÉË Ç ÐÅÊÎÐÄÀÌÈ ÍÅ ÇÍÀÉÄÅÍÎ.";
		
		position.X = 25;
		position.Y = 13;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " ÄÀÍ² ÏÐÎ ÐÅÊÎÐÄÈ ÎÁÍÓËÅÍÎ.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);

		system("pause");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		system("cls");
	}

	return false;
}

void C_Program::Save()
{
	ofstream fout(top10_file);

	if (fout)
	{
		for (int i = 0; i < 10; i++)
		{
			fout << top10[i]->Get_game_score() << endl;

			fout << top10[i]->Get_game_date() << endl;
		}

		fout.close();
	}
}

void C_Program::Show_top_10()
{
	system("cls");

	int left_x = 19;
	int top = 5;

	COORD position;

	position.X = left_x;
	position.Y = top - 4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << "        ÒÅÒÐ²Ñ - ÊÐÀÙ² ÄÅÑßÒÜ ²ÃÎÐ";


	position.X = left_x;
	position.Y = top - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << "Ïîçèö³ÿ    Ðàõóíîê           Êîëè ç³ãðàíî";


	for (int i = 0; i < 10; ++i)
	{
		
		position.X = left_x;
		position.Y = top + 2*i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				
		cout << setw(2) << left << i + 1 << " "<< right << setw(15) << top10[i]->Get_game_score() << "    ";

		Print_date_from_time_t(top10[i]->Get_game_date());
	
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	system("pause");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void C_Program::Print_date_from_time_t(time_t date)
{
	time_t *ptr_tmp = new time_t(date);
	tm* buf = new tm();
	localtime_s(buf, ptr_tmp);

	cout << setw(2) << setfill('0') << right << buf->tm_mday << "."
		<< setw(2) << setfill('0') << right << buf->tm_mon + 1 << "."
		<< buf->tm_year + 1900 << " "
		<< setw(2) << setfill('0') << right << buf->tm_hour << ":"
		<< setw(2) << setfill('0') << right << buf->tm_min << ":"
		<< setw(2) << setfill('0') << right << buf->tm_sec << setfill(' ');

	delete buf;
	delete ptr_tmp;

}

void C_Program::Sort_top_10()
{
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (top10[j]->Get_game_score() <= top10[j+1]->Get_game_score())
			{
				swap(top10[j], top10[j+1]);
			}
		}
	}
}

bool C_Program::Check_top_file()
{
	ifstream s_fin(top10_file);

	bool bad_records = false;

	if (s_fin)
	{
		streambuf * s_cinbuf = cin.rdbuf();

		cin.rdbuf(s_fin.rdbuf());

		char * buffer_score;
		char * buffer_date;

		for (int i = 0; i < 10; ++i)
		{
			buffer_score = new char[256];

			buffer_date = new char[256];
			
			cin >> buffer_score;

			cin >> buffer_date;

			if (!All_Digits(buffer_score) || !All_Digits(buffer_date)) bad_records = true;
			

			delete[] buffer_score;
			delete[] buffer_date;
		}

		cin.rdbuf(s_cinbuf);

		s_fin.close();
		
	}

	if (bad_records) return false;
	
	return true;
}

bool C_Program::All_Digits(char * arr)
{
	int number_counter = 0;

	for (int i = 0; i < (int)strlen(arr); ++i)
	{
		if (isdigit(arr[i])) ++number_counter;
	}

	if (number_counter == strlen(arr))
	{
		return true;
	}
	else
	{
		return false;
	}
}

C_Program::~C_Program()
{
	delete tetris;
	
	for (int i = 0; i < 10; ++i)
	{
		delete top10[i];
	}

	delete[] top10;

	delete[] top10_file;
}
