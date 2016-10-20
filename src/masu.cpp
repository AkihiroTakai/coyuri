#include "../include/type.hpp"
#include "../include/prot.hpp"
#include "../include/value.hpp"
#include <iostream>
#include <cmath>

Masu::Masu(int x, int y, int width, int height) : Fl_Box(x, y, width, height, 0){
	//std::cout << (x/46) << ":" << (y/46) << std::endl;
	X = x;
	Y = y;
}

int Masu::handle(int event){

	if(event == FL_RELEASE){
		int x = (X/70) - 1, y = (Y/70) - 1;
		std::cout << "EVENT!!!!\n";
		std::cout << x << y << std::endl;
		for(Point point : wcm_ftable[main_ban[x][y]](Point(std::abs(x-9), y+1))){
			set_and_redraw(point, TARGET);
		}
	}

	return 1;
}
