#include <windows.h>
#include <iostream>
#include <conio.h>

#include "C_11_figure_like_I_rotated.h"

using namespace std;

C_11_figure_like_I_rotated::C_11_figure_like_I_rotated()
{
	length = 2;
	height = 4;
	bottom_y = 4;
	top_y = 1;
	left_x = 40;
	right_x = 41;

	figure_type = 11;

	rotated_figure_type = 1;
	rotated_figure_length = 8;
	rotated_figure_height = 1;

	shift = false;
}

void C_11_figure_like_I_rotated::Erase()
{
	COORD position;

	position.X = left_x;
	position.Y = top_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

	for (int j = 1; j <= height; ++j)
	{
		for (int i = 1; i <= length; ++i)
		{
			if (position.X % 2 != 0)
				cout << ".";
			else
				cout << " ";

			++position.X;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}

		position.X = left_x;
		++position.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
}

bool C_11_figure_like_I_rotated::Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift)
{
	for (int i = 0; i < height; ++i)
	{
		if (!Check_for_free_cell(left_x - 1, top_y + i) && !Check_for_free_cell(right_x + 1, top_y + i)) return false;
	}

	int free_cell_counter_left = 0;
	int free_cell_counter_right = 0;

	CHAR_INFO ci;
	COORD dwBufferCoord = { 0, 0 };
	COORD dwBufferSize = { 1, 1 };

	if (!shift)
	{
		for (int i = 1; i < rotated_figure_length - 3; ++i)
		{
			SMALL_RECT rect = { (short)(left_x - i), (short)(top_y + 1), (short)(left_x - i), (short)(top_y + 1) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_left;
		}

		for (int i = 1; i < 3; ++i)
		{

			SMALL_RECT rect = { (short)(right_x + i), (short)(top_y + 1), (short)(right_x + i), (short)(top_y + 1) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_right;
		}

		if (free_cell_counter_left + free_cell_counter_right == 6)
		{
			rotated_left_x = left_x - 4;
			rotated_top_y = top_y + 1;
			rotated_shift = true;
			return true;
		}
		else
		{
			int free_cell_counter_left = 0;
			int free_cell_counter_right = 0;

			for (int i = 1; i < rotated_figure_length - 3; ++i)
			{
				SMALL_RECT rect = { (short)(right_x + i), (short)(top_y + 1), (short)(right_x + i), (short)(top_y + 1) };
				ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

				if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_right;
			}

			for (int i = 1; i < 3; ++i)
			{

				SMALL_RECT rect = { (short)(left_x - i), (short)(top_y + 1), (short)(left_x - i), (short)(top_y + 1) };
				ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

				if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_left;
			}

			if (free_cell_counter_left + free_cell_counter_right == 6)
			{
				rotated_left_x = left_x - 2;
				rotated_top_y = top_y + 1;
				rotated_shift = true;
				return true;
			}
			else
			{
				int free_cell_counter_right = 0;

				for (int i = 1; i < rotated_figure_length - 1; ++i)
				{
					SMALL_RECT rect = { (short)(right_x + i), (short)(top_y + 1), (short)(right_x + i), (short)(top_y + 1) };
					ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

					if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_right;
				}

				
				if (free_cell_counter_right == 6)
				{
					rotated_left_x = left_x;
					rotated_top_y = top_y + 1;
					rotated_shift = true;
					return true;
				}
				else
				{
					int free_cell_counter_left = 0;

					for (int i = 1; i < rotated_figure_length - 1; ++i)
					{
						SMALL_RECT rect = { (short)(left_x - i), (short)(top_y + 1), (short)(left_x - i), (short)(top_y + 1) };
						ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

						if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_left;
					}


					if (free_cell_counter_left == 6)
					{
						rotated_left_x = left_x - 6;
						rotated_top_y = top_y + 1;
						rotated_shift = true;
						return true;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 1; i < rotated_figure_length - 3; ++i)
		{
			SMALL_RECT rect = { (short)(right_x + i), (short)(top_y + 1), (short)(right_x + i), (short)(top_y + 1) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_right;
		}

		for (int i = 1; i < 3; ++i)
		{

			SMALL_RECT rect = { (short)(left_x - i), (short)(top_y + 1), (short)(left_x - i), (short)(top_y + 1) };
			ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

			if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_left;
		}

		if (free_cell_counter_left + free_cell_counter_right == 6)
		{
			rotated_left_x = left_x - 2;
			rotated_top_y = top_y + 1;
			rotated_shift = false;
			return true;
		}
		else
		{
			int free_cell_counter_left = 0;
			int free_cell_counter_right = 0;

			for (int i = 1; i < rotated_figure_length - 3; ++i)
			{
				SMALL_RECT rect = { (short)(left_x - i), (short)(top_y + 1), (short)(left_x - i), (short)(top_y + 1) };
				ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

				if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_left;
			}

			for (int i = 1; i < 3; ++i)
			{

				SMALL_RECT rect = { (short)(right_x + i), (short)(top_y + 1), (short)(right_x + i), (short)(top_y + 1) };
				ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

				if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_right;
			}

			if (free_cell_counter_left + free_cell_counter_right == 6)
			{
				rotated_left_x = left_x - 4;
				rotated_top_y = top_y + 1;
				rotated_shift = false;
				return true;
			}
			else
			{
				int free_cell_counter_left = 0;

				for (int i = 1; i < rotated_figure_length - 1; ++i)
				{
					SMALL_RECT rect = { (short)(left_x - i), (short)(top_y + 1), (short)(left_x - i), (short)(top_y + 1) };
					ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

					if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_left;
				}

				if (free_cell_counter_left == 6)
				{
					rotated_left_x = left_x - 6;
					rotated_top_y = top_y + 1;
					rotated_shift = false;
					return true;
				}
				else
				{
					int free_cell_counter_right = 0;

					for (int i = 1; i < rotated_figure_length - 1; ++i)
					{
						SMALL_RECT rect = { (short)(right_x + i), (short)(top_y + 1), (short)(right_x + i), (short)(top_y + 1) };
						ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, dwBufferSize, dwBufferCoord, &rect);

						if (ci.Char.UnicodeChar == ' ' || ci.Char.UnicodeChar == '.') ++free_cell_counter_right;
					}


					if (free_cell_counter_right == 6)
					{
						rotated_left_x = left_x;
						rotated_top_y = top_y + 1;
						rotated_shift = false;
						return true;
					}
				}

			}
		}
	}

	return false;
}

C_11_figure_like_I_rotated::~C_11_figure_like_I_rotated()
{
}