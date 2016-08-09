#include <windows.h>
#include <iostream>
#include <conio.h>

#include "C_5_figure_like_J.h"

using namespace std;

C_5_figure_like_J::C_5_figure_like_J()
{
	length = 6;
	height = 2;
	bottom_y = 2;
	top_y = 1;
	left_x = 36;
	right_x = 41;

	figure_type = 5;

	rotated_figure_type = 51;
	rotated_figure_length = 4;
	rotated_figure_height = 3;

	shift = false;
}

void C_5_figure_like_J::Show()
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
		else
		{
			position.X = left_x + 4;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			cout << (char)219 << (char)219;
		}

		++position.Y;
		position.X = left_x;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

void C_5_figure_like_J::Show_after_rotation(int rotated_left_x, int rotated_top_y)
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
		else
		{
			position.X = left_x + 4;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			cout << (char)219 << (char)219;
		}

		++position.Y;
		position.X = left_x;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

}

bool C_5_figure_like_J::Move_down(int current_level)
{
	while (!_kbhit())

	{
		if (!Check_for_free_cell(left_x, bottom_y)) return false;
		if (!Check_for_free_cell(left_x + 2, bottom_y)) return false;
		if (!Check_for_free_cell(right_x, bottom_y + 1)) return false;

		if (current_level != 10) Sleep(700 - 70 * current_level);

		Erase();

		++top_y;
		++bottom_y;

		Show();
	}

	return true;
}


void C_5_figure_like_J::Erase()
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
		else
		{
			position.X = left_x + 4;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
			cout << " .";
		}

		++position.Y;
		position.X = left_x;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

bool C_5_figure_like_J::Move_left()
{
	if (!Check_for_free_cell(left_x - 1, top_y)) return false;
	if (!Check_for_free_cell(left_x + 2, bottom_y)) return false;

	Erase();

	--left_x;
	--left_x;
	--right_x;
	--right_x;

	Show();

	return true;
}

bool C_5_figure_like_J::Move_right()
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


bool C_5_figure_like_J::Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift)
{

	if (!Check_for_free_cell(left_x, top_y - 1) && !Check_for_free_cell(left_x, bottom_y)) return false;

	if (!Check_for_free_cell(left_x + 2, top_y - 1) && !Check_for_free_cell(left_x + 2, bottom_y)) return false;

	if (!Check_for_free_cell(right_x, top_y - 1) && !Check_for_free_cell(right_x, bottom_y + 1)) return false;

	if (!Check_for_free_cell(left_x + 2, bottom_y) && !Check_for_free_cell(right_x + 1, bottom_y)) return false;

	int free_cell_counter = 0;

	
	if (Check_for_free_cell(right_x - 2, bottom_y + 1)) ++free_cell_counter;

	if (Check_for_free_cell(right_x, bottom_y + 1)) ++free_cell_counter;

	if (free_cell_counter == 2)
	{
		rotated_left_x = left_x + 2;
		rotated_top_y = top_y;
		rotated_shift = false;
		return true;
	}

	free_cell_counter = 0;

	if (Check_for_free_cell(left_x + 2, bottom_y)) ++free_cell_counter;

	if (Check_for_free_cell(left_x + 2, bottom_y + 1)) ++free_cell_counter;

	if (Check_for_free_cell(left_x, bottom_y + 1)) ++free_cell_counter;

	if (free_cell_counter == 3)
	{
		rotated_left_x = left_x;
		rotated_top_y = top_y;
		rotated_shift = false;
		return true;
	}

	free_cell_counter = 0;

	if (Check_for_free_cell(right_x, top_y - 1)) ++free_cell_counter;

	if (Check_for_free_cell(right_x - 2, bottom_y)) ++free_cell_counter;

	if (free_cell_counter == 2)
	{
		rotated_left_x = left_x + 2;
		rotated_top_y = top_y - 1;
		rotated_shift = false;
		return true;
	}

	free_cell_counter = 0;

	if (Check_for_free_cell(right_x - 2, top_y - 1)) ++free_cell_counter;

	if (Check_for_free_cell(right_x - 2, bottom_y)) ++free_cell_counter;

	if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

	if (free_cell_counter == 3)
	{
		rotated_left_x = left_x;
		rotated_top_y = top_y - 1;
		rotated_shift = false;
		return true;
	}

	return false;
}

bool C_5_figure_like_J::Exist_free_place_for_new_figure()
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
			if (!Check_for_free_cell(right_x, top_y + i)) return false;

	}

	return true;
}

C_5_figure_like_J::~C_5_figure_like_J()
{
}