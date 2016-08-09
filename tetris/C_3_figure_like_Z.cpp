#include <windows.h>
#include <iostream>
#include <conio.h>

#include "C_3_figure_like_Z.h"

using namespace std;

C_3_figure_like_Z::C_3_figure_like_Z()
{
	length = 6;
	height = 2;
	bottom_y = 2;
	top_y = 1;
	left_x = 36;
	right_x = 41;

	figure_type = 3;

	rotated_figure_type = 31;
	rotated_figure_length = 4;
	rotated_figure_height = 3;

	shift = false;
}

void C_3_figure_like_Z::Show()
{

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 1; i <= height; ++i)
	{
		for (int i = 0; i < length - 2; ++i)
		{
			cout << (char)219;
		}

		++position.Y;
		position.X = left_x + 2;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

void C_3_figure_like_Z::Show_after_rotation(int rotated_left_x, int rotated_top_y)
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
		for (int i = 0; i < length - 2; ++i)
		{
			cout << (char)219;
		}

		++position.Y;
		position.X = left_x + 2;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

}

bool C_3_figure_like_Z::Move_down(int current_level)
{
	while (!_kbhit())

	{

		for (int i = 0; i < length - 2; ++i)
		{
			CHAR_INFO ci;
			COORD dwBufferCoord = { 0, 0 };
			COORD dwBufferSize = { 1, 1 };
			SMALL_RECT rect = { (short)(right_x - i), (short)(bottom_y + 1), (short)(right_x - i), (short)(bottom_y + 1) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

		}

		for (int i = 0; i < length - 4; ++i)
		{
			CHAR_INFO ci;
			COORD dwBufferCoord = { 0, 0 };
			COORD dwBufferSize = { 1, 1 };
			SMALL_RECT rect = { (short)(left_x + i), (short)(bottom_y), (short)(left_x + i), (short)(bottom_y) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

		}

		if (current_level != 10) Sleep(700 - 70 * current_level);

		Erase();

		++top_y;
		++bottom_y;

		Show();
	}

	return true;
}


void C_3_figure_like_Z::Erase()
{
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int j = 1; j <= height; ++j)
	{
		for (int i = 1; i <= length - 2; ++i)
		{

			if (position.X % 2 != 0)
				cout << ".";
			else
				cout << " ";

			++position.X;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}

		position.X = left_x + 2;
		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

bool C_3_figure_like_Z::Move_left()
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

bool C_3_figure_like_Z::Move_right()
{
	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };
	SMALL_RECT rect = { (short)(right_x + 1), (short)(bottom_y), (short)(right_x + 1), (short)(bottom_y) };
	ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

	if (ci.Char.UnicodeChar != ' ' && ci.Char.UnicodeChar != '.') return false;

	rect = { (short)(right_x), (short)(top_y), (short)(right_x), (short)(top_y) };
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


bool C_3_figure_like_Z::Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift)
{

	if (!Check_for_free_cell(right_x, top_y) && !Check_for_free_cell(right_x, bottom_y + 1)) return false;

	if (!Check_for_free_cell(left_x + 2, top_y - 1) && !Check_for_free_cell(left_x + 2, bottom_y + 1)) return false;

	if (!Check_for_free_cell(left_x, top_y - 1) && !Check_for_free_cell(left_x, bottom_y)) return false;

	int free_cell_counter = 0;

	if (!shift)
	{

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(right_x - 2, top_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y - 1;
			rotated_shift = false;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(right_x, top_y)) ++free_cell_counter;

		if (Check_for_free_cell(right_x, top_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x + 2;
			rotated_top_y = top_y - 1;
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

		free_cell_counter = 0;

		if (Check_for_free_cell(right_x, top_y)) ++free_cell_counter;

		if (Check_for_free_cell(left_x + 2, bottom_y + 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x + 2;
			rotated_top_y = top_y;
			rotated_shift = false;
			return true;
		}

	}
	else
	{

		if (Check_for_free_cell(right_x, top_y)) ++free_cell_counter;

		if (Check_for_free_cell(left_x + 2, bottom_y + 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x + 2;
			rotated_top_y = top_y;
			rotated_shift = true;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(left_x, bottom_y + 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y;
			rotated_shift = true;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(right_x, top_y)) ++free_cell_counter;

		if (Check_for_free_cell(right_x, top_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x + 2;
			rotated_top_y = top_y - 1;
			rotated_shift = true;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(right_x - 2, top_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y - 1;
			rotated_shift = true;
			return true;
		}
		
	}

	return false;
}

bool C_3_figure_like_Z::Exist_free_place_for_new_figure()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length - 2; ++j)
		{
			if (i == 1)
			{
				if (!Check_for_free_cell(left_x + 2 + j, top_y + i)) return false;
			}
			else
				if (!Check_for_free_cell(left_x + j, top_y + i)) return false;
		}
	}

	return true;
}

C_3_figure_like_Z::~C_3_figure_like_Z()
{
}