#include "../../include/type.hpp"
#include "../../include/prot.hpp"
#include "../../include/value.hpp"
#include <iostream>
#include <cmath>
#include <stdio.h>

/*
 *探索部分
 *探索の深さは2手先まで
 */
Node *max(Node *node, int limit){

	if(limit <= 0){
		node->set_evalue(EVAL(node));
		return node;
	}

	int score = 0, score_max = -1;
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
			printf("%3d", node->get_banmen()->get_type(x, y));
			set_and_redraw(Point(std::abs(9-x), y+1), node->get_banmen()->get_type(x, y));
		}
		std::cout << std::endl;
	}

	std::cout << "eval:" << node->get_evalue() << std::endl;
	
	//destroy_tree(root);
/*
  delete node;
  node = NULL;
  delete root;
  root = NULL;
*/
}
