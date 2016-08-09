#include <windows.h>
#include <iostream>
#include <conio.h>

#include "C_4_figure_like_T.h"

using namespace std;

C_4_figure_like_T::C_4_figure_like_T()
{
	length = 6;
	height = 2;
	bottom_y = 2;
	top_y = 1;
	left_x = 36;
	right_x = 41;

	figure_type = 4;

	rotated_figure_type = 41;
	rotated_figure_length = 4;
	rotated_figure_height = 3;

	shift = false;
}

void C_4_figure_like_T::Show()
{

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 0; i < height; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < length; ++j)
			{
				cout << (char)219;
			}
		}
		else cout << (char)219 << (char)219 ;
		
		++position.Y;
		position.X = left_x + 2;
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

void C_4_figure_like_T::Show_after_rotation(int rotated_left_x, int rotated_top_y)
{
	top_y = rotated_top_y;
	bottom_y = rotated_top_y + height - 1;
	left_x = rotated_left_x;
	right_x = rotated_left_x + length - 1;

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 0; i < height; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < length; ++j)
			{
				cout << (char)219;
			}
		}
		else cout << (char)219 << (char)219;

		++position.Y;
		position.X = left_x + 2;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

}

bool C_4_figure_like_T::Move_down(int current_level)
{
	while (!_kbhit())

	{
		if (!Check_for_free_cell(left_x , bottom_y)) return false;
		if (!Check_for_free_cell(left_x + 2 , bottom_y + 1)) return false;
		if (!Check_for_free_cell(right_x, bottom_y)) return false;

		if (current_level != 10) Sleep(700 - 70 * current_level);

		Erase();

		++top_y;
		++bottom_y;

		Show();
	}

	return true;
}


void C_4_figure_like_T::Erase()
{
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 0; i < height; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < length / 2; ++j)
			{
				cout << " .";
			}
		}
		else cout << " .";;

		++position.Y;
		position.X = left_x + 2;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

bool C_4_figure_like_T::Move_left()
{

	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };
	SMALL_RECT rect = { (short)(left_x), (short)(bottom_y), (short)(left_x), (short)(bottom_y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

	rect = { (short)(left_x - 1), (short)(top_y), (short)(left_x - 1), (short)(top_y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

	Erase();

	--left_x;
	--left_x;
	--right_x;
	--right_x;

	Show();

	return true;
}

bool C_4_figure_like_T::Move_right()
{
	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };
	SMALL_RECT rect = { (short)(right_x + 1), (short)(top_y), (short)(right_x + 1), (short)(top_y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

	rect = { (short)(right_x), (short)(bottom_y), (short)(right_x), (short)(bottom_y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

	Erase();

	++left_x;
	++left_x;
	++right_x;
	++right_x;

	Show();

	return true;


}


bool C_4_figure_like_T::Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift)
{

	if (!Check_for_free_cell(left_x, top_y - 1) && !Check_for_free_cell(left_x, bottom_y)) return false;

	if (!Check_for_free_cell(left_x + 2, top_y - 1) && !Check_for_free_cell(left_x + 2, bottom_y + 1)) return false;

	if (!Check_for_free_cell(right_x, top_y - 1) && !Check_for_free_cell(right_x, bottom_y)) return false;

	if (!Check_for_free_cell(left_x, bottom_y) && !Check_for_free_cell(right_x, bottom_y)) return false;

	int free_cell_counter = 0;

	
		if (Check_for_free_cell(right_x - 2, top_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 1)
		{
			rotated_left_x = left_x + 2;
			rotated_top_y = top_y - 1;
			rotated_shift = false;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(left_x, top_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y - 1;
			rotated_shift = false;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(right_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(right_x - 2, bottom_y + 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x + 2;
			rotated_top_y = top_y;
			rotated_shift = false;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(left_x, bottom_y + 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y;
			rotated_shift = false;
			return true;
		}

	return false;
}

bool C_4_figure_like_T::Exist_free_place_for_new_figure()
{
	for (int i = 0; i < height; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < length; ++j)
			{
				if (!Check_for_free_cell(left_x + j, top_y + i)) return false;
			}
		}
		else
			if (!Check_for_free_cell(left_x + 2, top_y + i)) return false;
		
	}

	return true;
}

C_4_figure_like_T::~C_4_figure_like_T()
{
}