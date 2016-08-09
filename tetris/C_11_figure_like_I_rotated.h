#pragma once

#include "C_1_figure_like_I.h"

class C_11_figure_like_I_rotated : public C_1_figure_like_I
{

public:
	
	C_11_figure_like_I_rotated();
		
	void Erase();

	bool Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift);

	~C_11_figure_like_I_rotated();

};