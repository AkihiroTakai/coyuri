#include <fstream>
#include <string>
#include <iostream>

void update_score(bool flag){
	std::ifstream back("/home/takai/Documents/score_back.txt");
	std::ifstream front("/home/takai/Documents/score.txt");
	std::string back_str;

	getline(back, back_str);

	std::stringstream stream(back_str);

	if(flag){
		//プレイヤーが勝った

	}else{
		
	}
}
