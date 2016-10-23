#include "../include/type.hpp"
#include "../include/prot.hpp"
#include "../include/value.hpp"
#include <vector>

std::vector<KOMA_TYPE> AI_TEGOMA;
std::vector<KOMA_TYPE> PLAYER_TEGOMA;

void player_push_koma(KOMA_TYPE type){
	PLAYER_TEGOMA.push_back(type);
}

void ai_push_koma(KOMA_TYPE type){
	AI_TEGOMA.push_back(type);
}
