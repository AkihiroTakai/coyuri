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

Tegoma::Tegoma(int x, int y, int width, int height, int arg_index, KOMA_TYPE arg_type) : Fl_Box(x, y, width, height, 0){
	type = arg_type;
	index = arg_index;
}

int Tegoma::handle(int event){
	if(event == FL_RELEASE){
		std::cout << "EVENT!!!!\n";
		for(Point point : wcm_ftable[TEGOMA](Point(0, 0))){
			target_masu(point);
		}
		UTSU = type;
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
	int i = 0;
	for(KOMA_TYPE koma : PLAYER_TEGOMA){

		player_tegomas[i]->image(images[koma]);
		player_tegomas[i]->redraw();
		std::cout << "aaaaaaaaaaaaaaa\n";
		std::cout << koma << " ";
	}

	std::cout << std::endl << "AI:";
	for(KOMA_TYPE koma : AI_TEGOMA){
		std::cout << koma << " ";
	}
	std::cout << std::endl;
}

void Tegoma::set_type(KOMA_TYPE arg_type){
	type = arg_type;
}

void PLAYER_UTSU(KOMA_TYPE type, Point p){
	std::vector<KOMA_TYPE>::iterator result = std::find(PLAYER_TEGOMA.begin(), PLAYER_TEGOMA.end(), type);
	if(result != PLAYER_TEGOMA.end()){
		/*
		 *あった
		 */
		PLAYER_TEGOMA.erase(result);
		set_and_redraw(p, type);
	}
	/*
	 *ない
	 */
}
