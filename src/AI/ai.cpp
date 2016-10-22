#include "../../include/prot.hpp"

/*
 *探索部分
 *探索の深さは2手先まで
 */
int negamax(int alpha, int beta, int limit){
	/*
	 *何もしない
	 */

	if(limit <= 0)
		return EVAL(NULL);

	int score, score_max;

	/*
	//可能な手を生成
	std::vector<BANMEN> nodes;
	nodes.push_back(NULL);

	
	for(BANMEN banmen : nodes){
		score = -negamax(-beta, -alpha, limit-1);

		if(score >= beta){
			return score;
		}

		if(score > score_max){
			score_max = score;
			alpha = score_max;
		}
	}
	*/

	return score_max;
}
