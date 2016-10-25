#include "../../include/type.hpp"
#include "../../include/prot.hpp"
#include "../../include/value.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

/*
 *探索部分
 *探索の深さは2手先まで
 */
Node *max(Node *node, int limit){

	if(limit <= 0){
		node->set_evalue(EVAL(node));
		return node;
	}

	int score = 0, score_max = -10000;
	Node *te = NULL;
	//可能な手を生成
      EXPAND(node);

	for(Node * & banmen : *(node->get_children())){
		score = min(banmen, limit-1)->get_evalue();
		if(score > score_max){
			delete te;
			te = banmen;
			te->set_evalue(score);
			score_max = score;
		}else{
			delete banmen;
			banmen = NULL;
		}

	}

	return te;
}

Node *min(Node *node, int limit){

	if(limit <= 0){
		node->set_evalue(EVAL(node));
		return node;
	}

	int score = 0, score_max = 10000;
	Node *te = NULL;
	//可能な手を生成
      PLAYER_EXPAND(node);

	for(Node * & banmen : *(node->get_children())){
		score = max(banmen, limit-1)->get_evalue();
		if(score < score_max){

			delete te;
			te = banmen;
			te->set_evalue(score);
			score_max = score;
		}else{
			delete banmen;
			banmen = NULL;
		}
	}

	return te;
}


void ai_turn(Node *root){

	Node *node = max(root, 4);
	for(int y = 0;y < 9;y++){
		for(int x = 0;x < 9;x++){
			printf("%3d", root->get_banmen()->get_type(x, y));
			if(node->get_banmen()->get_type(x, y) != root->get_banmen()->get_type(x, y)){
				/*
				 *rootとnodeで盤面が異なる場合(AIが駒をとった可能性がある)
				 */
				if(root->get_banmen()->get_type(x, y) != EMPTY && node->get_banmen()->get_type(x, y) != EMPTY){
					/*
					 *EMPTYじゃない。つまり、駒をとった->プッシュします
					 */
					AI_TEGOMA.push_back(ai_negaeri(root->get_banmen()->get_type(x, y)));
					std::cout << "TYPE!!!!!!!!!!!!!:" << ai_negaeri(node->get_banmen()->get_type(x, y)) << std::endl;

				}

			}
			set_and_redraw(Point(std::abs(9-x), y+1), node->get_banmen()->get_type(x, y));
		}
		std::cout << std::endl;
	}

	int counters1[30] = {0};
	int counters2[30] = {0};
	for(int y = 0;y < 9;y++){
		for(int x = 0;x < 9;x++){
			counters1[root->get_banmen()->get_type(x, y)]++;
			counters2[node->get_banmen()->get_type(x, y)]++;
		}
	}

	for(KOMA_TYPE koma : AI_TEGOMA){
		std::cout << koma << " ";
	}
	for(int i = 1;i < 30;i++){
		if(counters1[i] != counters2[i]){
			std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n" << i << std::endl;
			if(std::find(AI_TEGOMA.begin(), AI_TEGOMA.end(), i) != AI_TEGOMA.end()){
				AI_TEGOMA.erase(std::find(AI_TEGOMA.begin(), AI_TEGOMA.end(), i));
			}
		}
	}
	std::cout << "eval:" << node->get_evalue() << std::endl;

}

void AI_START(Fl_Widget* widget){
	/*
	 *AIのターン
	 */
	BANMEN *banmen = new BANMEN;

	for(int x = 0;x < 9;x++)
		for(int y = 0;y < 9;y++)
			banmen->set_type(x, y, main_ban[x][y]);

	Node *root = new Node(banmen, NULL);
	ai_turn(root);
}
