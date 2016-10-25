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
Node *max(Node *node, int alpha, int beta, int limit){

	if(limit <= 0){
		/*
		 *一番深いノードまで達した
		 */
		node->set_evalue(EVAL(node));
		return node;
	}

	int score = 0, score_max = -10000;
	Node *te = NULL, *iti = NULL;
	//可能な手を生成
      EXPAND(node);

	for(int i = 0;i < (*node->get_children()).size();i++){
		iti = min((*node->get_children()).at(i), alpha, beta, limit-1);
		score = iti->get_evalue();
		if(score >= beta){
			/*
			 *beta値より大きくなった場合
			 */
			(*node->get_children()).at(i)->set_evalue(score);
			for(int n = i+1;n < (*node->get_children()).size();n++){
				delete (*node->get_children()).at(n);
			}
			delete te;
			delete iti;
			return (*node->get_children()).at(i);
		}
		if(score > score_max){
			/*
			 *よりよい解が見つかった
			 */
			delete te;
			te = (*node->get_children()).at(i);
			te->set_evalue(score);
			score_max = score;
			alpha = score;
		}else{
			delete (*node->get_children()).at(i);
		}
		delete iti;
	}

	return te;
}

Node *min(Node *node, int alpha, int beta, int limit){

	if(limit <= 0){
		/*
		 *一番深いノードまで達した
		 */
		node->set_evalue(EVAL(node));
		return node;
	}

	int score = 0, score_max = 10000;
	Node *te = NULL, *iti = NULL;
	//可能な手を生成
      PLAYER_EXPAND(node);


	for(int i = 0;i < (*node->get_children()).size();i++){
		score = max((*node->get_children()).at(i), alpha, beta, limit-1)->get_evalue();
		if(score <= alpha){
			/*
			 *alpha値より小さくなった場合
			 */
			(*node->get_children()).at(i)->set_evalue(score);
			for(int n = i+1;n < (*node->get_children()).size();n++){
				delete (*node->get_children()).at(n);
			}
			delete te;
			return (*node->get_children()).at(i);
		}
		if(score < score_max){
			/*
			 *よりよい解が見つかった
			 */
			delete te;
			te = (*node->get_children()).at(i);
			te->set_evalue(score);
			score_max = score;
			beta = score;
		}else{
			delete (*node->get_children()).at(i);
		}
	}

	return te;
}


void ai_turn(Node *root){

	int counters1[30] = {0};
	int counters2[30] = {0};

	Node *node = max(root, -100000, 100000, 4);
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

				}

			}
			set_and_redraw(Point(std::abs(9-x), y+1), node->get_banmen()->get_type(x, y));
		}
		std::cout << std::endl;
	}

	for(int y = 0;y < 9;y++){
		for(int x = 0;x < 9;x++){
			counters1[root->get_banmen()->get_type(x, y)]++;
			counters2[node->get_banmen()->get_type(x, y)]++;
		}
	}


	for(int i = 1;i < 30;i++){
		if(counters1[i] != counters2[i]){
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
