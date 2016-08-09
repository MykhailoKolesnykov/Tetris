#pragma once

class C_1_figure_like_I
{
protected:
	
	int length;
	int height;
	int bottom_y;
	int top_y;
	int left_x;
	int right_x;

	int figure_type;

	int rotated_figure_type;

	int rotated_figure_length;
	int rotated_figure_height;

	bool shift;
	
public:
	
	C_1_figure_like_I();

	void virtual Show();

	void virtual Show_after_rotation(int rotated_left_x, int rotated_top_y);

	void virtual Erase();

	bool virtual Move_down(int current_level);

	bool virtual Move_left();
	
	bool virtual Move_right();

	bool virtual Rotatable(int & rotated_left_x, int & rotated_top_y, bool & rotated_shift);

	int virtual Get_rotated_figure_type();

	int virtual Get_left_x();

	int virtual Get_top_y();

	int virtual Get_figure_type();

	void virtual Set_shift(bool rotated_shift);

	bool virtual Check_for_free_cell(int x, int y);

	bool virtual Exist_free_place_for_new_figure();

	
		
	~C_1_figure_like_I();

};