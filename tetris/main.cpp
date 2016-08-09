#include <iostream>
#include <ctime>

#include "C_Program.h"

int main()

{
	srand((unsigned)time(0));
	
	C_Program * playstation = new C_Program("scores.txt");

	playstation->Main_menu();

	delete playstation;
	
	return 0;
}