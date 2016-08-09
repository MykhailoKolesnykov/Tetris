#include <windows.h>
#include <iostream>
#include <conio.h>

#include "C_1_figure_like_I.h"
#include"C_Field.h"

using namespace std;

C_1_figure_like_I::C_1_figure_like_I()
{
	length = 8;
	height = 1;
	bottom_y = 1;
	top_y = 1;
	left_x = 36;
	right_x = 43;

	figure_type = 1;

	rotated_figure_type = 11;
	rotated_figure_length = 2;
	rotated_figure_height = 4;

	shift = false;

}

void C_1_figure_like_I::Show()
{

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 1; i <= height; ++i)
	{

		for (int i = 0; i < length; ++i)
		{
			cout << (char)219;
		}

		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

void C_1_figure_like_I::Show_after_rotation(int rotated_left_x, int rotated_top_y)
{
	top_y = rotated_top_y;
	bottom_y = rotated_top_y + height - 1;
	left_x = rotated_left_x;
	right_x = rotated_left_x + length - 1;
	
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 1; i <= height; ++i)
	{

		for (int i = 0; i < length; ++i)
		{
			cout << (char)219;
		}

		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

void C_1_figure_like_I::Erase()
{
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 1; i <= length; ++i)
	{
		if (position.X % 2 != 0)
			cout << ".";
		else
			cout << " ";

		++position.X;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

}

bool C_1_figure_like_I::Move_down(int current_level)
{
	while (!_kbhit())

	{

		for (int i = 0; i < length; ++i)
		{
			CHAR_INFO ci;
			COORD dwBufferCoord = { 0, 0 };
			COORD dwBufferSize = { 1, 1 };
			SMALL_RECT rect = { (short)(left_x + i), (short)(bottom_y + 1), (short)(left_x + i), (short)(bottom_y + 1) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;
			
		}

		if (current_level != 10) Sleep(700 - 70 * current_level);

		COORD position;

		position.X = left_x;
		position.Y = top_y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

		for (int i = 1; i <= length; ++i)
		{
			if (position.X % 2 != 0)
				cout << ".";
			else
				cout << " ";
			
			++position.X;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}

		++top_y;
		++bottom_y;

		Show();
	}

	return true;
}

bool C_1_figure_like_I::Move_left()
{
	for (int i = 0; i < height; ++i)
	{
		CHAR_INFO ci;
		COORD dwBufferCoord = { 0, 0 };
		COORD dwBufferSize = { 1, 1 };
		SMALL_RECT rect = { (short)(left_x - 1), (short)(top_y + i), (short)(left_x - 1), (short)(top_y + i) };
		ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

		if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;
	}

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 1; i <= height; ++i)
	{
		for (int j = 1; j <= length / 2; ++j)
		{
			if (position.X % 2 == 0)
				cout << " .";
			else
				cout << "  ";
			
		}
		
		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

	--left_x;
	--left_x;
	--right_x;
	--right_x;

	Show();

	return true;
}

bool C_1_figure_like_I::Move_right()
{

	for (int i = 0; i < height; ++i)
	{
		CHAR_INFO ci;
		COORD dwBufferCoord = { 0, 0 };
		COORD dwBufferSize = { 1, 1 };
		SMALL_RECT rect = { (short)(right_x + 1), (short)(top_y + i), (short)(right_x + 1), (short)(top_y + i) };
		ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

		if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;
	}

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 1; i <= height; ++i)
	{

		for (int j = 1; j <= length / 2; ++j)
		{
			
			if (position.X % 2 != 0)
				cout << "  ";
			else
				cout << " .";
			
		}

		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

	++left_x;
	++left_x;
	++right_x;
	++right_x;

	Show();

	return true;

	/*CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };
	SMALL_RECT rect = { right_x + 1, bottom_y, right_x + 1, bottom_y };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 1; i <= length; ++i)
	{
		if (position.X % 2 != 0)
			cout << ".";
		else
			cout << " ";
	}

	++left_x;
	++right_x;

	Show();

	return true;*/
}

bool C_1_figure_like_I::Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift)
{
	
	for (int i = 0; i < length; ++i)
	{
		if (!Check_for_free_cell(left_x + i, top_y - 1) && !Check_for_free_cell(left_x + i, bottom_y + 1)) return false;
	}
	
	int free_cell_counter_up = 0;
	int free_cell_counter_down = 0;
	
	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };

	if (!shift)
	{
		for (int i = 1; i < rotated_figure_height - 1; ++i)
		{
			SMALL_RECT rect = { (short)(left_x + 4), (short)(top_y - i), (short)(left_x + 4), (short)(top_y - i) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_up;
		}

		
			SMALL_RECT rect = { (short)(left_x + 4), (short)(top_y + 1), (short)(left_x + 4), (short)(top_y + 1) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_down;
				
		if (free_cell_counter_up + free_cell_counter_down == rotated_figure_height - 1)
		{
			rotated_left_x = left_x + 4;
			rotated_top_y = top_y - 2;
			rotated_shift = false;
			return true;
		}
		else
		{
			free_cell_counter_up = 0;

			for (int i = 1; i < rotated_figure_height ; ++i)
			{
				SMALL_RECT rect = { (short)(left_x + 4), (short)(top_y - i), (short)(left_x + 4), (short)(top_y - i) };
				ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

				if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_up;
			}
			if (free_cell_counter_up == rotated_figure_height - 1)
			{
				rotated_left_x = left_x + 4;
				rotated_top_y = top_y - 3;
				rotated_shift = false;
				return true;
			}
			else 
			{
				free_cell_counter_down = 0;

				for (int i = 1; i < rotated_figure_height; ++i)
				{
					SMALL_RECT rect = { (short)(left_x + 4), (short)(top_y + i), (short)(left_x + 4), (short)(top_y + i) };
					ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

					if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_down;
				}
				if (free_cell_counter_down == rotated_figure_height - 1)
				{
					rotated_left_x = left_x + 4;
					rotated_top_y = top_y;
					rotated_shift = false;
					return true;
				}
			
			}
		}


	}
	else
	{
		for (int i = 1; i < rotated_figure_height - 1; ++i)
		{
			SMALL_RECT rect = { (short)(left_x + 2), (short)(top_y - i), (short)(left_x + 2), (short)(top_y - i) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_up;
		}


		SMALL_RECT rect = { (short)(left_x + 2), (short)(top_y + 1), (short)(left_x + 2), (short)(top_y + 1) };
		ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

		if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_down;

		if (free_cell_counter_up + free_cell_counter_down == rotated_figure_height - 1)
		{
			rotated_left_x = left_x + 2;
			rotated_top_y = top_y - 2;
			rotated_shift = true;
			return true;
		}
		else
		{
			free_cell_counter_up = 0;

			for (int i = 1; i < rotated_figure_height; ++i)
			{
				SMALL_RECT rect = { (short)(left_x + 2), (short)(top_y - i), (short)(left_x + 2), (short)(top_y - i) };
				ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

				if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_up;
			}
			if (free_cell_counter_up == rotated_figure_height - 1)
			{
				rotated_left_x = left_x + 2;
				rotated_top_y = top_y - 3;
				rotated_shift = true;
				return true;
			}
			else
			{
				free_cell_counter_down = 0;

				for (int i = 1; i < rotated_figure_height; ++i)
				{
					SMALL_RECT rect = { (short)(left_x + 2), (short)(top_y + i), (short)(left_x + 2), (short)(top_y + i) };
					ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

					if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_down;
				}
				if (free_cell_counter_down == rotated_figure_height - 1)
				{
					rotated_left_x = left_x + 2;
					rotated_top_y = top_y;
					rotated_shift = true;
					return true;
				}

			}
		}
	}
		
	return false;
}

int C_1_figure_like_I::Get_rotated_figure_type()
{
	return rotated_figure_type;
}

int C_1_figure_like_I::Get_left_x()
{
	return left_x;
}

int C_1_figure_like_I::Get_top_y()
{
	return top_y;
}

int C_1_figure_like_I::Get_figure_type()
{
	return figure_type;
}

void C_1_figure_like_I::Set_shift(bool rotated_shift)
{
	shift = rotated_shift;
}

bool C_1_figure_like_I::Check_for_free_cell(int x, int y)
{
	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };

	SMALL_RECT rect = { (short)(x), (short)(y), (short)(x), (short)(y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') return true;

	return false;
}

bool C_1_figure_like_I::Exist_free_place_for_new_figure()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			if (!Check_for_free_cell(left_x + j, top_y + i)) return false;
		}
	}

	return true;
}

C_1_figure_like_I::~C_1_figure_like_I()
{
}