#include <windows.h>
#include <iostream>
#include <conio.h>

#include "C_7_figure_like_O.h"

using namespace std;

C_7_figure_like_O::C_7_figure_like_O()
{
	length = 4;
	height = 2;
	bottom_y = 2;
	top_y = 1;
	left_x = 36;
	right_x = 39;

	figure_type = 7;

	rotated_figure_type = 7;
	rotated_figure_length = 4;
	rotated_figure_height = 2;

	shift = false;
}

void C_7_figure_like_O::Show()
{

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
			{
				cout << (char)219;
			}

		++position.Y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

void C_7_figure_like_O::Show_after_rotation(int rotated_left_x, int rotated_top_y)
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
		for (int j = 0; j < length; ++j)
		{
			cout << (char)219;
		}

		++position.Y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

}

bool C_7_figure_like_O::Move_down(int current_level)
{
	while (!_kbhit())

	{
		if (!Check_for_free_cell(left_x, bottom_y + 1)) return false;
		if (!Check_for_free_cell(right_x, bottom_y + 1)) return false;

		if (current_level != 10) Sleep(700 - 70 * current_level);

		Erase();

		++top_y;
		++bottom_y;

		Show();
	}

	return true;
}


void C_7_figure_like_O::Erase()
{
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length / 2; ++j)
		{
			cout << " .";
		}
		
		++position.Y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

bool C_7_figure_like_O::Move_left()
{
	if (!Check_for_free_cell(left_x - 1, top_y)) return false;
	if (!Check_for_free_cell(left_x - 1, bottom_y)) return false;

	Erase();

	--left_x;
	--left_x;
	--right_x;
	--right_x;

	Show();

	return true;
}

bool C_7_figure_like_O::Move_right()
{
	if (!Check_for_free_cell(right_x + 1, top_y)) return false;
	if (!Check_for_free_cell(right_x + 1, bottom_y)) return false;

	Erase();

	++left_x;
	++left_x;
	++right_x;
	++right_x;

	Show();

	return true;
}


bool C_7_figure_like_O::Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift)
{
	return false;
}

bool C_7_figure_like_O::Exist_free_place_for_new_figure()
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

C_7_figure_like_O::~C_7_figure_like_O()
{
}