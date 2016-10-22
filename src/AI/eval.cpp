#include "../../include/type.hpp"
#include "../../include/value.hpp"
#include "../../include/prot.hpp"
#include <cmath>

int EVAL(Node *node){
	/*
	 *盤面を評価
	 */
	return 0;
}

/*
 *渡された盤面からコンピュータがさせる手をすべてリストアップする関数
 */
void EXPAND(Node *node){

	for(int x = 0;x < 9;x++){
		for(int y = 0;y < 9;y++){
			if(node->get_banmen()->get_type(x, y) >= EN_HU && node->get_banmen()->get_type(x, y) <= EN_OU){
				for(Point p : wcm_ftable[node->get_banmen()->get_type(x, y)](Point(std::abs(x-9), y+1))){
				      BANMEN *new_banmen = new BANMEN();
					new_banmen->copy_banmen(node->get_banmen());
					new_banmen->set_type(9-p.get_x(), p.get_y()-1, node->get_banmen()->get_type(x, y));
					new_banmen->set_type(x, y, EMPTY);
					node->get_children()->push_back(new Node(new_banmen, node));
				}
			}
		}
	}
}
