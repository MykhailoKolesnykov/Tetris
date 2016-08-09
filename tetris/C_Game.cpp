#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "C_Game.h"

using namespace std;

C_Game::C_Game()
{
	one_more_game = false;

	game_field = new C_Field();;

	current_figure = new C_1_figure_like_I();

	game_date = time(NULL);

	what_next = 1 + rand() % 7;

	what_prev = what_next;
	
	switch (what_next)
	{
	case 1:
	{
		next_figure = new C_1_figure_like_I();
		break;
	}
	case 2:
	{
		next_figure = new C_2_figure_like_S();
		break;
	}

	case 3:
	{
		next_figure = new C_3_figure_like_Z();
		break;
	}

	case 4:
	{
		next_figure = new C_4_figure_like_T();
		break;
	}

	case 5:
	{
		next_figure = new C_5_figure_like_J();
		break;
	}

	case 6:
	{
		next_figure = new C_6_figure_like_L();
		break;
	}

	case 7:
	{
		next_figure = new C_7_figure_like_O();
		break;
	}

	default:
	{
		next_figure = new C_1_figure_like_I();
		break;
	}
	}
		
}

void C_Game::Run()
{
	system("cls");

	COORD position;

	position.X = 33;
	position.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "ÎÁÅÐÈ Ð²ÂÅÍÜ ÃÐÈ";

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	for (int i = 0, j = 1; i < 10; ++i)
	{
		position.X = 40;
		position.Y = 3 + i + j;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		if (i == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		cout << i;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		++j;
	}

	int y0 = 4;
	int y1 = y0 + 2;
	int y2 = y1 + 2;
	int y3 = y2 + 2;
	int y4 = y3 + 2;
	int y5 = y4 + 2;
	int y6 = y5 + 2;
	int y7 = y6 + 2;
	int y8 = y7 + 2;
	int y9 = y8 + 2;
	
	position.X = 40;
	position.Y = y0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	bool exit = false;

	bool will_be_game = true;

	while (!exit)
	{
		switch (_getch())
		{
		case 72: // up
		{
			if (position.Y == y0)
			{
				
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "0";
				position.Y = y9;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "9";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << position.Y / 2 - 2;
				--position.Y; --position.Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << position.Y / 2 - 2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			break;
		}

		case 80: // down
		{
			if (position.Y != y9)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << position.Y / 2 - 2;
				++position.Y; ++position.Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << position.Y / 2 - 2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "9";
				position.Y = y0;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "0";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}

			break;
		}
		case 13: // enter
		{
			game_field->Set_game_level(position.Y / 2 - 2);
			exit = true;
			break;
		}
		case 27: // escape
		{ 
			will_be_game = false;
			exit = true;
			break;
		}
		}
	}

	if (will_be_game)
	{
		delete current_figure;

		C_1_figure_like_I * tmp_figure;

		game_field->Draw_empty_field();

		bool game_process = true;

		while (game_process)
		{

			switch (next_figure->Get_figure_type())
			{
			case 1:
			{
				current_figure = new C_1_figure_like_I();
				break;
			}

			case 2:
			{
				current_figure = new C_2_figure_like_S();
				break;
			}

			case 3:
			{
				current_figure = new C_3_figure_like_Z();
				break;
			}

			case 4:
			{
				current_figure = new C_4_figure_like_T();
				break;
			}

			case 5:
			{
				current_figure = new C_5_figure_like_J();
				break;
			}

			case 6:
			{
				current_figure = new C_6_figure_like_L();
				break;
			}

			case 7:
			{
				current_figure = new C_7_figure_like_O();
				break;
			}

			default:
			{
				current_figure = new C_1_figure_like_I();
				break;
			}
			}

			delete next_figure;

			while (true)
			{
				what_next = 1 + rand() % 7;

				if (what_next != what_prev) break;

			}

			what_prev = what_next;

			switch (what_next)
			{
			case 1:
			{
				next_figure = new C_1_figure_like_I();
				break;
			}
			case 2:
			{
				next_figure = new C_2_figure_like_S();
				break;
			}

			case 3:
			{
				next_figure = new C_3_figure_like_Z();
				break;
			}

			case 4:
			{
				next_figure = new C_4_figure_like_T();
				break;
			}

			case 5:
			{
				next_figure = new C_5_figure_like_J();
				break;
			}

			case 6:
			{
				next_figure = new C_6_figure_like_L();
				break;
			}

			case 7:
			{
				next_figure = new C_7_figure_like_O();
				break;
			}

			default:
			{
				next_figure = new C_1_figure_like_I();
				break;
			}
			}

			if (game_field->Get_next_figure_show())
			{
				COORD position;

				position.X = 19;
				position.Y = 10;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "        ";

				position.X = 19;
				position.Y = 11;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "        ";

				next_figure->Show_after_rotation(19, 10);
			}

			if (current_figure->Exist_free_place_for_new_figure())
			{
				current_figure->Show();

				game_field->Up_score_20();

				bool moving_down = true;

				while (moving_down)
				{
					if (!current_figure->Move_down(game_field->Get_game_level()))
					{
						Sleep(300);

						if (_kbhit())
						{
							switch (_getch())
							{
							case '8':case 72:
							{
								int rotated_left_x = 0;
								int rotated_top_y = 0;
								bool rotated_shift = false;

								if (current_figure->Rotatable(rotated_left_x, rotated_top_y, rotated_shift))
								{
									tmp_figure = game_field->Rotate(current_figure->Get_rotated_figure_type());

									current_figure->Erase();

									delete current_figure;

									current_figure = tmp_figure;

									current_figure->Show_after_rotation(rotated_left_x, rotated_top_y);

									current_figure->Set_shift(rotated_shift);

								}
								break;
							}

							case '7': case 75:
							{
								current_figure->Move_left();
								break;
							}

							case '9': case 77:
							{
								current_figure->Move_right();
								break;
							}
														
							case 27: // escape
							{
								Pause_of_game_menu(game_process);
								break;
							}

							default:
								break;


							}
						}

						if (!game_process)
						{
							game_field->Check_for_full_lines();
							game_date = time(NULL);
							break;
						}
												
						if (!current_figure->Move_down(game_field->Get_game_level()))
						{
							game_field->Check_for_full_lines();
							delete current_figure;
							break;
						}

					}

					

						switch (_getch())
						{
						case '4':
						{
							if (game_field->Get_game_level() < 9)
							{
								game_field->Set_game_level(game_field->Get_game_level() + 1);
							}
							break;
						}

						case '5': case 32: case 80:
						{
							current_figure->Move_down(10);
							break;
						}

						case '7': case 75:
						{
							current_figure->Move_left();
							break;
						}

						case '8': case 72:
						{
							int rotated_left_x = 0;
							int rotated_top_y = 0;
							bool rotated_shift = false;

							if (current_figure->Rotatable(rotated_left_x, rotated_top_y, rotated_shift))
							{
								tmp_figure = game_field->Rotate(current_figure->Get_rotated_figure_type());

								current_figure->Erase();

								delete current_figure;

								current_figure = tmp_figure;

								current_figure->Show_after_rotation(rotated_left_x, rotated_top_y);

								current_figure->Set_shift(rotated_shift);

							}

							break;
						}

						case '9': case 77:
						{
							current_figure->Move_right();
							break;
						}

						case '0':
						{
							game_field->Change_controls_info();
							break;
						}

						case '1':
						{
							game_field->Change_next_figure_show();

							if (game_field->Get_next_figure_show())
							{
								COORD position;

								position.X = 19;
								position.Y = 10;
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
								cout << "        ";

								position.X = 19;
								position.Y = 11;
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
								cout << "        ";

								next_figure->Show_after_rotation(19, 10);
							}
							break;
						}

						case 27: // escape
						{
							Pause_of_game_menu(game_process);
							if (!game_process)
							{
								game_date = time(NULL);
								moving_down = false;
							}
							break;
						}

						default:
						{
							break;
						}
						}
					
				}
			}

			else

			{
				game_date = time(NULL);
				End_of_game_menu();
				game_process = false;
			}

		}
	}
}

void C_Game::End_of_game_menu()
{
	COORD position;

	position.X = 1;
	position.Y = 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "ÃÐÓ ÇÀÊ²Í×ÅÍÎ";

	position.X = 1;
	position.Y = 12;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "ÍÎÂÀ ÃÐÀ";

		
	position.X = 1;
	position.Y = 14;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "ÃÎËÎÂÍÅ ÌÅÍÞ";
	
		
	position.X = 1;
	position.Y = 12;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	bool exit = false;

	while (!exit)
	{
		switch (_getch())
		{
		case 72: case 80: // up and down
		{
			if (position.Y == 12)
			{

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÍÎÂÀ ÃÐÀ";
				position.Y = 14;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÃÎËÎÂÍÅ ÌÅÍÞ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÃÎËÎÂÍÅ ÌÅÍÞ";
				position.Y = 12;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÍÎÂÀ ÃÐÀ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			break;
		}

		
		case 13: // enter
		{
			if (position.Y == 12) one_more_game = true;
			exit = true;
			break;
		
		}

		case 27: // escape
		{
			exit = true;
			break;
		}
		}
	}

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
}

void C_Game::Pause_of_game_menu(bool & game_process)
{
	COORD position;

	position.X = 1;
	position.Y = 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "ÏÀÓÇÀ";

	position.X = 1;
	position.Y = 12;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "ÍÎÂÀ ÃÐÀ";


	position.X = 1;
	position.Y = 14;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "ÃÎËÎÂÍÅ ÌÅÍÞ";


	position.X = 1;
	position.Y = 12;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	bool exit = false;

	while (!exit)
	{
		switch (_getch())
		{
		case 72: case 80: // up and down
		{
			if (position.Y == 12)
			{

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÍÎÂÀ ÃÐÀ";
				position.Y = 14;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÃÎËÎÂÍÅ ÌÅÍÞ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				cout << "ÃÎËÎÂÍÅ ÌÅÍÞ";
				position.Y = 12;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				cout << "ÍÎÂÀ ÃÐÀ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			break;
		}


		case 13: // enter
		{
			if (position.Y == 12) one_more_game = true;
			game_process = false;
			exit = true;
			break;
		}

		case 27: // escape
		{
			position.X = 1;
			position.Y = 10;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

			cout << "     ";

			position.X = 1;
			position.Y = 12;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "        ";


			position.X = 1;
			position.Y = 14;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "            ";
			
			exit = true;

			break;
		}
		}
	}

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
}

bool C_Game::One_more_game()
{
	return one_more_game;
}

time_t C_Game::Get_game_date()
{
	return game_date;
}

int C_Game::Get_game_score()
{
	return game_field->Get_current_score();
}

C_Game::~C_Game()
{
	delete current_figure;

	delete next_figure;

	delete game_field;
}




