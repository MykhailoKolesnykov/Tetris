#include <windows.h>
#include <iostream>
#include <conio.h>

#include "C_21_figure_like_S_rotated.h"

using namespace std;

C_21_figure_like_S_rotated::C_21_figure_like_S_rotated()
{
	length = 4;
	height = 3;
	bottom_y = 3;
	top_y = 1;
	left_x = 38;
	right_x = 41;

	figure_type = 21;

	rotated_figure_type = 2;
	rotated_figure_length = 6;
	rotated_figure_height = 2 ;

	shift = false;
}

void C_21_figure_like_S_rotated::Show()
{

	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << (char)219 << (char)219;
		
	++position.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 0; i < length; ++i)
	{
		cout << (char)219;
	}

	++position.Y;
	position.X = left_x + 2;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << (char)219 << (char)219;
}

void C_21_figure_like_S_rotated::Show_after_rotation(int rotated_left_x, int rotated_top_y)
{
	top_y = rotated_top_y;
	bottom_y = rotated_top_y + height - 1;
	left_x = rotated_left_x;
	right_x = rotated_left_x + length - 1;
	
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << (char)219 << (char)219;

	++position.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int i = 0; i < length; ++i)
	{
		cout << (char)219;
	}

	++position.Y;
	position.X = left_x + 2;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	cout << (char)219 << (char)219;

}

bool C_21_figure_like_S_rotated::Move_down(int current_level)
{
	while (!_kbhit())

	{

		if (!Check_for_free_cell(left_x, bottom_y)) return false;

		if (!Check_for_free_cell(left_x + 2, bottom_y + 1)) return false;

		if (current_level != 10) Sleep(700 - 70 * current_level);

		Erase();

		++top_y;
		++bottom_y;

		Show();
	}

	return true;
}


void C_21_figure_like_S_rotated::Erase()
{
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	if (position.X % 2 != 0)
		cout << ". ";
	else
		cout << " .";

	position.Y = top_y + 1;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	if (position.X % 2 != 0)
		cout << ". . ";
	else
		cout << " . .";

	position.X = left_x + 2 ;
	position.Y = bottom_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	if (position.X % 2 != 0)
		cout << ". ";
	else
		cout << " .";

}

bool C_21_figure_like_S_rotated::Move_left()
{
	if (!Check_for_free_cell(left_x - 1, top_y)) return false;
	if (!Check_for_free_cell(left_x - 1, top_y + 1)) return false;
	if (!Check_for_free_cell(left_x, bottom_y)) return false;

	Erase();

	--left_x;
	--left_x;
	--right_x;
	--right_x;

	Show();

	return true;
}

bool C_21_figure_like_S_rotated::Move_right()
{
	if (!Check_for_free_cell(right_x, top_y)) return false;
	if (!Check_for_free_cell(right_x + 2, top_y + 1)) return false;
	if (!Check_for_free_cell(right_x + 2, bottom_y)) return false;

	Erase();

	++left_x;
	++left_x;
	++right_x;
	++right_x;

	Show();

	return true;


}


bool C_21_figure_like_S_rotated::Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift)
{

	if (!Check_for_free_cell(left_x - 1, top_y) && !Check_for_free_cell(right_x, top_y)) return false;

	if (!Check_for_free_cell(left_x - 1, top_y + 1) && !Check_for_free_cell(right_x + 1, top_y + 1)) return false;

	if (!Check_for_free_cell(left_x , bottom_y) && !Check_for_free_cell(right_x + 1, bottom_y)) return false;

	
	int free_cell_counter = 0;

	if (!shift)
	{

		if (Check_for_free_cell(left_x - 1, bottom_y - 1)) ++free_cell_counter;

		if (Check_for_free_cell(right_x, top_y)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x - 2;
			rotated_top_y = top_y;
			rotated_shift = true;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x - 1, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x - 2;
			rotated_top_y = top_y + 1;
			rotated_shift = true;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x, bottom_y - 1)) ++free_cell_counter;

		if (Check_for_free_cell(right_x + 2, top_y)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y;
			rotated_shift = true;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(right_x + 2, bottom_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y + 1;
			rotated_shift = true;
			return true;
		}

	}
	else
	{

		
		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(right_x + 2, bottom_y - 1)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y + 1;
			rotated_shift = false;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x, bottom_y - 1)) ++free_cell_counter;

		if (Check_for_free_cell(right_x + 2, top_y)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x;
			rotated_top_y = top_y;
			rotated_shift = false;
			return true;
		}

		free_cell_counter = 0;

		if (Check_for_free_cell(left_x - 1, bottom_y)) ++free_cell_counter;

		if (Check_for_free_cell(left_x, bottom_y)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x - 2;
			rotated_top_y = top_y + 1;
			rotated_shift = false;
			return true;
		}

		free_cell_counter = 0;


		if (Check_for_free_cell(left_x - 1, bottom_y - 1)) ++free_cell_counter;

		if (Check_for_free_cell(right_x, top_y)) ++free_cell_counter;

		if (free_cell_counter == 2)
		{
			rotated_left_x = left_x - 2;
			rotated_top_y = top_y;
			rotated_shift = false;
			return true;
		}

		
	}

	return false;
}

C_21_figure_like_S_rotated::~C_21_figure_like_S_rotated()
{
}