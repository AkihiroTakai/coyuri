#include "../include/type.hpp"
#include "../include/prot.hpp"
#include "../include/value.hpp"
#include <vector>
#include <iostream>

std::vector<KOMA_TYPE> AI_TEGOMA;
std::vector<KOMA_TYPE> PLAYER_TEGOMA;

void player_push_koma(KOMA_TYPE type){
	PLAYER_TEGOMA.push_back(type);
}

void ai_push_koma(KOMA_TYPE type){
	AI_TEGOMA.push_back(type);
}

void show_tegoma(){
	std::cout << "Player:";
	for(KOMA_TYPE koma : PLAYER_TEGOMA){
		std::cout << koma << " ";
	}

	std::cout << std::endl << "AI:";
	for(KOMA_TYPE koma : AI_TEGOMA){
		std::cout << koma << " ";
	}
	std::cout << std::endl;
}
