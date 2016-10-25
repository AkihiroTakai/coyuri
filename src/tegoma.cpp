#include "../include/type.hpp"
#include "../include/prot.hpp"
#include "../include/value.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

std::vector<KOMA_TYPE> AI_TEGOMA;
std::vector<KOMA_TYPE> PLAYER_TEGOMA;

void PLAYER_UTSU(KOMA_TYPE type, Point p);

Tegoma::Tegoma(int x, int y, int width, int height, int in_x, int in_y, KOMA_TYPE arg_type) : Fl_Box(x, y, width, height, 0){
	X = in_x;
	Y = in_y;
	type = arg_type;
}

int Tegoma::handle(int event){
	if(event == FL_RELEASE){
		if(type == HU){
			for(Point point : nihu_wcm()){
				target_masu(point);
			}
		}else{
			for(Point point : wcm_ftable[TEGOMA](Point(0, 0))){
				target_masu(point);
			}
		}
		UTSU = type;
		UTSU_KOMA.set_x(9-X);
		UTSU_KOMA.set_y(Y+1);
	}

	return 1;
}


void player_push_koma(KOMA_TYPE type){
	PLAYER_TEGOMA.push_back(type);
}

void ai_push_koma(KOMA_TYPE type){
	AI_TEGOMA.push_back(type);
}

void show_tegoma(){
	std::cout << "Player:";
	int x = 0, y = 0;
	for(KOMA_TYPE koma : PLAYER_TEGOMA){
		player_tegomas[x][y]->image(images[koma]);
		player_tegomas[x][y]->redraw();
		x++;
		if(x == 9){
			/*
			 *いい感じに循環させます
			 */
			x = 0;
			y++;
		}
		std::cout << koma << " ";
	}

	std::cout << std::endl << "AI:";
	for(KOMA_TYPE koma : AI_TEGOMA){
		std::cout << koma << " ";
	}
	std::cout << std::endl;
}

void Tegoma::set_type(KOMA_TYPE arg_type){
	if(arg_type >= EN_HU && arg_type <= EN_OU){
		type = negaeri(arg_type);
	}else{
		type = arg_type;
	}
}

void PLAYER_UTSU(KOMA_TYPE type, Point p){

	set_and_redraw(p, type);
	player_tegomas[(PLAYER_TEGOMA.size()-1) % 6][(PLAYER_TEGOMA.size()-1) / 6]->image(images[EMPTY]);
	player_tegomas[(PLAYER_TEGOMA.size()-1) % 6][(PLAYER_TEGOMA.size()-1) / 6]->redraw();

	PLAYER_TEGOMA.erase(std::find(PLAYER_TEGOMA.begin(), PLAYER_TEGOMA.end(), type));

}
