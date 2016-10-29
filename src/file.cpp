#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <iomanip>

void update_score(bool flag){
	std::remove("/home/takai/Documents/score.txt");
	std::ifstream back("/home/takai/Documents/score_back.txt");
	std::ofstream front("/home/takai/Documents/score.txt");
	std::string back_str;
	int win, lose;
	win = lose = 0;

	getline(back, back_str);
	getline(back, back_str);

	std::stringstream stream(back_str);
	stream >> win >> lose;

	if(!flag){
		//プレイヤーが勝った
		front << "こゆりちゃんの戦績" << std::endl;
		front << "現在" << std::to_string(win+1) << "勝" << std::to_string(lose) << "敗" << std::flush;
		back.close();
		std::remove("/home/takai/Documents/score_back.txt");
		std::ofstream new_back("/home/takai/Documents/score_back.txt");
		new_back << std::to_string(win+1) << " " <<  std::to_string(lose) << std::flush;
		new_back.close();
	}else{
		//プレイヤーが負けた
		front << "こゆりちゃんの戦績" << std::endl;
		front << "現在" << std::to_string(win) << "勝" << std::to_string(lose+1) << "敗" << std::flush;
		back.close();
		std::remove("/home/takai/Documents/score_back.txt");
		std::ofstream new_back("/home/takai/Documents/score_back.txt");
		new_back << std::to_string(win+1) << " " << std::to_string(lose) << std::flush;
		new_back.close();
	}
}
