#include <windows.h>
#include <iostream>

#include "C_Field.h"

using namespace std;

C_Field::C_Field()
{
	    full_lines_counter = 0;
		game_level = 0;
		current_score = 0;
		next_figure_show = false;
		show_controls_info = true;
}

void C_Field::Draw_empty_field()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	COORD position;
	
	position.X = 1;
	position.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "ÏÎÂÍÈÕ ÐßÄÊ²Â: " << full_lines_counter;

	position.X = 1;
	position.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "Ð²ÂÅÍÜ:        " << game_level;

	position.X = 1;
	position.Y = 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << " ÐÀÕ.:  " << current_score;

	position.X = 28;
	position.Y = 0;
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << "<!====================!>";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	++position.Y;
	
	position.X = 28;
	
	while (position.Y < 21)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "<! . . . . . . . . . .!>";
		++position.Y;
	}

	position.X = 28;
	
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "<!====================!>";
		++position.Y;
	
	position.X = 28;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/  ";
	
	position.X = 55;
	position.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "7: Ë²ÂÎÐÓ×   9: ÏÐÀÂÎÐÓ×";


	position.X = 55;
	++position.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "       8: ÏÎÂÎÐÎÒ       ";

	position.X = 55;
	++position.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "4: ÏÐÈÑÊÎÐÈÒÈ 5: ÑÊÈÍÓÒÈ";

	position.X = 55;
	++position.Y;;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "  1: ÏÎÊÀÇÀÒÈ ÍÀÑÒÓÏÍÓ";

	position.X = 55;
	++position.Y;;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "  0: ÑÒÅÐÒÈ  ÖÅÉ ÒÅÊÑÒ";

	position.X = 55;
	++position.Y;;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << "    ÏÐÎÁ²Ë - ÑÊÈÍÓÒÈ";

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
}

void C_Field::Set_game_level(int current_level)
{
	if (game_level < 9)
	{
		game_level = current_level;
		
		COORD position;

		position.X = 16;
		position.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << game_level;
	}


}

int C_Field::Get_game_level()
{
	return game_level;
}

void C_Field::Up_score_20()
{
		current_score += 20;

		COORD position;

		position.X = 9;
		position.Y = 3;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << current_score;
}

void C_Field::Plus_one_line()
{
	++full_lines_counter;

	COORD position;

	position.X = 16;
	position.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << full_lines_counter;

	if (full_lines_counter == 10 && game_level < 1) game_level = 1;
	if (full_lines_counter == 20 && game_level < 2) game_level = 2;
	if (full_lines_counter == 30 && game_level < 3) game_level = 3;
	if (full_lines_counter == 40 && game_level < 4) game_level = 4;
	if (full_lines_counter == 50 && game_level < 5) game_level = 5;
	if (full_lines_counter == 60 && game_level < 6) game_level = 6;
	if (full_lines_counter == 70 && game_level < 7) game_level = 7;
	if (full_lines_counter == 80 && game_level < 8) game_level = 8;
	if (full_lines_counter == 90 && game_level < 9) game_level = 9;
	
	position.X = 16;
	position.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << game_level;

	current_score += 100;

	position.X = 9;
	position.Y = 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << current_score;
}


C_1_figure_like_I * C_Field::Rotate(int rotated_figure_type)
{
	switch (rotated_figure_type)
	{
	case 1:
	{
			C_1_figure_like_I * rotated_figure = new C_1_figure_like_I();
			return rotated_figure;
			break;
	}
	case 11:
	{
			C_11_figure_like_I_rotated * rotated_figure = new C_11_figure_like_I_rotated();
			return rotated_figure;
			break; 
	}
	case 2:
	{
			C_2_figure_like_S * rotated_figure = new C_2_figure_like_S();
			return rotated_figure;
			break;
	}
	case 21:
	{
		C_21_figure_like_S_rotated * rotated_figure = new C_21_figure_like_S_rotated();
		return rotated_figure;
		break;
	}

	case 3:
	{
		C_3_figure_like_Z * rotated_figure = new C_3_figure_like_Z();
		return rotated_figure;
		break;
	}
	case 31:
	{
		C_31_figure_like_Z_rotated * rotated_figure = new C_31_figure_like_Z_rotated();
		return rotated_figure;
		break;
	}

	case 4:
	{
		C_4_figure_like_T * rotated_figure = new C_4_figure_like_T();
		return rotated_figure;
		break;
	}

	case 41:
	{
		C_41_figure_like_T_rotated * rotated_figure = new C_41_figure_like_T_rotated();
		return rotated_figure;
		break;
	}

	case 42:
	{
		C_42_figure_like_T_rotated * rotated_figure = new C_42_figure_like_T_rotated();
		return rotated_figure;
		break;
	}

	case 43:
	{
		C_43_figure_like_T_rotated * rotated_figure = new C_43_figure_like_T_rotated();
		return rotated_figure;
		break;
	}

	case 5:
	{
		C_5_figure_like_J * rotated_figure = new C_5_figure_like_J();
		return rotated_figure;
		break;
	}

	case 51:
	{
		C_51_figure_like_J_rotated * rotated_figure = new C_51_figure_like_J_rotated();
		return rotated_figure;
		break;
	}

	case 52:
	{
		C_52_figure_like_J_rotated * rotated_figure = new C_52_figure_like_J_rotated();
		return rotated_figure;
		break;
	}
	
	case 53:
	{
		C_53_figure_like_J_rotated * rotated_figure = new C_53_figure_like_J_rotated();
		return rotated_figure;
		break;
	}

	case 6:
	{
		C_6_figure_like_L * rotated_figure = new C_6_figure_like_L();
		return rotated_figure;
		break;
	}

	case 61:
	{
		C_61_figure_like_L_rotated * rotated_figure = new C_61_figure_like_L_rotated();
		return rotated_figure;
		break;
	}
	
	case 62:
	{
		C_62_figure_like_L_rotated * rotated_figure = new C_62_figure_like_L_rotated();
		return rotated_figure;
		break;
	}

	case 63:
	{
		C_63_figure_like_L_rotated * rotated_figure = new C_63_figure_like_L_rotated();
		return rotated_figure;
		break;
	}

	case 7:
	{
		C_7_figure_like_O * rotated_figure = new C_7_figure_like_O();
		return rotated_figure;
		break;
	}

	default:
	{
			C_1_figure_like_I * rotated_figure = new C_1_figure_like_I();
			return rotated_figure;
			break;
	}
	}
}

int C_Field::Get_current_score()
{
	return current_score;
}

void C_Field::Check_for_full_lines()
{
	bool exist_free_cell = false;

	for (int y = 20; y >= 1; --y)
	{
		for (int x = 30; x <= 49; ++x)
		{
			if (Check_for_free_cell(x, y)) exist_free_cell = true;
		}

		if (!exist_free_cell)

		{
			Plus_one_line();
			
			COORD position;

			for (int i = y - 1 ; i > 0; --i)
			{
				for (int x = 30; x <= 49; ++x)
				{
					COORD position;

					position.X = x;
					position.Y = i + 1;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
					cout << char(Get_symbol_from_field(x,i));
				}
			
			}

			position.X = 28;
			position.Y = 1;
			
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			cout << "<! . . . . . . . . . .!>";
			++y;
		}
			
		exist_free_cell = false;
	}


}

bool C_Field::Check_for_free_cell(int x, int y)
{
	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };

	SMALL_RECT rect = { (short)(x), (short)(y), (short)(x), (short)(y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') return true;

	return false;
}

int C_Field::Get_symbol_from_field(int x, int y)
{
	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };

	SMALL_RECT rect = { (short)(x), (short)(y), (short)(x), (short)(y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);
	
	if (ci.Char.UnicodeChar == ' ') return 32;
	else
	if (ci.Char.UnicodeChar == '.') return 46;
	else return 219;
}

void C_Field::Change_controls_info()
{
	if (show_controls_info)
	{
		show_controls_info = false;

		COORD position;

		position.X = 55;
		position.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "                        ";


		position.X = 55;
		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "                        ";

		position.X = 55;
		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "                        ";

		position.X = 55;
		++position.Y;;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "                      ";

		position.X = 55;
		++position.Y;;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "                      ";

		position.X = 55;
		++position.Y;;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "                    ";

	}
	else
	{
		show_controls_info = true;

		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		COORD position;

		position.X = 55;
		position.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "7: Ë²ÂÎÐÓ×   9: ÏÐÀÂÎÐÓ×";


		position.X = 55;
		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "       8: ÏÎÂÎÐÎÒ       ";

		position.X = 55;
		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "4: ÏÐÈÑÊÎÐÈÒÈ 5: ÑÊÈÍÓÒÈ";

		position.X = 55;
		++position.Y;;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "  1: ÏÎÊÀÇÀÒÈ ÍÀÑÒÓÏÍÓ";

		position.X = 55;
		++position.Y;;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "  0: ÑÒÅÐÒÈ  ÖÅÉ ÒÅÊÑÒ";

		position.X = 55;
		++position.Y;;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "    ÏÐÎÁ²Ë - ÑÊÈÍÓÒÈ";

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
	}
}

void C_Field::Change_next_figure_show()
{
	if (next_figure_show)
	{
		next_figure_show = false;

		COORD position;

		position.X = 19;
		position.Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "        ";

		position.X = 19;
		position.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "        ";
			

	}
	else
	{
		next_figure_show = true;

	}

}


bool C_Field::Get_next_figure_show()
{
	return next_figure_show;
}

C_Field::~C_Field()
{
}
