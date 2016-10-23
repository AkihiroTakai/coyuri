#include "../../include/type.hpp"
#include "../../include/prot.hpp"
#include <iostream>

/*
 *探索部分
 *探索の深さは2手先まで
 */
int max(Node *node, int limit){

	if(limit <= 0)
		return EVAL(node);

	int score = 0, score_max = -1;
	//可能な手を生成
      EXPAND(node);

	for(Node *banmen : *(node->get_children())){
		score = min(banmen, limit-1);
		if(score > score_max){

			score_max = score;
		}
	}

	return score_max;
}

int min(Node *node, int limit){

	if(limit <= 0)
		return EVAL(node);

	int score = 0, score_max = 10000;
	//可能な手を生成
      EXPAND(node);

	for(Node *banmen : *(node->get_children())){
		score = max(banmen, limit-1);
		if(score < score_max){
			score_max = score;
		}
	}

	return score_max;
}


void ai_turn(BANMEN *banmen){
	Node *root = new Node(banmen, NULL);
	std::cout << max(root, 4) << std::endl;
}
