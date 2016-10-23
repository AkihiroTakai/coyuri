#include "../include/value.hpp"
#include "../include/prot.hpp"
#include <iostream>

void move(Point replace){
	std::cout << "move\n";
	set_and_redraw(Point(replace.get_x(), replace.get_y()), main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()]);
	set_and_redraw(Point(9-TARGET_KOMA.get_x(), TARGET_KOMA.get_y()+1), EMPTY);
}
