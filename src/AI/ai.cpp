#include "../../include/type.hpp"
#include "../../include/prot.hpp"

/*
 *探索部分
 *探索の深さは2手先まで
 */
int max(Node *node, int limit){

	if(limit <= 0)
		return EVAL(node);

	int score, score_max;
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

	int score, score_max;
	//可能な手を生成
      EXPAND(node);

	for(Node *banmen : *(node->get_children())){
		score = max(banmen, limit-1);
		if(score > score_max){
			score_max = score;
		}
	}

	return score_max;
}


Point decide(BANMEN banmen){

}
