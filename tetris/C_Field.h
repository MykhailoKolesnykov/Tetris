#pragma once

#include "C_1_figure_like_I.h"
#include "C_11_figure_like_I_rotated.h"
#include "C_2_figure_like_S.h"
#include "C_21_figure_like_S_rotated.h"
#include "C_3_figure_like_Z.h"
#include "C_31_figure_like_Z_rotated.h"
#include "C_4_figure_like_T.h"
#include "C_41_figure_like_T_rotated.h"
#include "C_42_figure_like_T_rotated.h"
#include "C_43_figure_like_T_rotated.h"
#include "C_5_figure_like_J.h"
#include "C_51_figure_like_J_rotated.h"
#include "C_52_figure_like_J_rotated.h"
#include "C_53_figure_like_J_rotated.h"
#include "C_6_figure_like_L.h"
#include "C_61_figure_like_L_rotated.h"
#include "C_62_figure_like_L_rotated.h"
#include "C_63_figure_like_L_rotated.h"
#include "C_7_figure_like_O.h"

class C_Field
{
private:
	int full_lines_counter;
	int game_level;
	int current_score;
	bool next_figure_show;
	bool show_controls_info;  

public:
		
	C_Field();

	void Draw_empty_field();
	
	void Set_game_level(int new_level);

	int Get_game_level();

	void Up_score_20();

	void Plus_one_line();

	void Change_controls_info();

	void Change_next_figure_show();

	bool Get_next_figure_show();

	C_1_figure_like_I * Rotate(int rotated_figure_type);

	int Get_current_score();
	
	void Check_for_full_lines();

	bool Check_for_free_cell(int x, int y);

	int Get_symbol_from_field(int x, int y);

	~C_Field();

};