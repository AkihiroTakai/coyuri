#include "../include/type.hpp"
#include "../include/prot.hpp"
#include "../include/value.hpp"
#include <iostream>
#include <FL/fl_message.H>
#include <cmath>

Masu::Masu(int x, int y, int width, int height) : Fl_Box(x, y, width, height, 0){
	X = x;
	Y = y;
}

int Masu::handle(int event){
	if(event == FL_RELEASE){
		int x = (X/70) - 1, y = (Y/70) - 1;
		if(main_ban[x][y] >= EN_HU && main_ban[x][y] <= EN_OU && target_ban[x][y]->image() != images[TARGET]){
			target_clear();
			return -1;
		}
		if(target_ban[x][y]->image() == images[TARGET]){
			if(UTSU != EMPTY){
				PLAYER_UTSU(UTSU, Point(9-x, y+1));
				UTSU = EMPTY;
				target_clear();
			}else{
				move(Point(std::abs(x-9), y+1));
				target_clear();
				show_tegoma();
			}
			if(win()){
				fl_message("負けちゃった。でも楽しかったよ。\nまた将棋しようね。");
				exit(0);
			}
			return 0;
		}
		target_clear();
		TARGET_KOMA.set_x(x);
		TARGET_KOMA.set_y(y);
		std::cout << "EVENT!!!!\n";
		for(Point point : wcm_ftable[main_ban[x][y]](Point(std::abs(x-9), y+1))){
			target_masu(point);
		}
	}

	return 1;
}
