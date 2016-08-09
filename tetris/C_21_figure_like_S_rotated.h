#pragma once

#include "C_1_figure_like_I.h"

class C_21_figure_like_S_rotated : public C_1_figure_like_I
{

public:

	C_21_figure_like_S_rotated();

	void virtual Show();

	void virtual Show_after_rotation(int rotated_left_x, int rotated_top_y);

	void virtual Erase();

	bool virtual Move_down(int current_level);

	bool virtual Move_left();

	bool virtual Move_right();

	bool virtual Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift);

	//int virtual Get_rotated_figure_type();

	//int virtual Get_left_x();

	//int virtual Get_top_y();

	//int virtual Get_figure_type();

	//void virtual Set_shift(bool rotated_shift);

	~C_21_figure_like_S_rotated();

};
