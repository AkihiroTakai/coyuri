#include "../../include/type.hpp"
#include "../../include/value.hpp"
#include "../../include/prot.hpp"
#include <cmath>

const int WITHIN_OU    = 5;
const int WITHIN_HISHA = 3;
const int WITHIN_KAKU  = 2;

int within_ou(BANMEN *banmen);
int within_hisha(BANMEN *banmen);
int within_kaku(BANMEN *banmen);
/*
 *注
 *ここで言う"敵"とはプレイヤーのこと
 *"自分"というのはAIのこと
 */

int EVAL(Node *node){
	int score = 0;
      /*
	 *盤面を評価
	 */

	/*
	 *自分の王が自分の陣地内にいれば評価値加算
	 */
      score += within_ou(node->get_banmen());

	/*
	 *飛車が自分の陣地の外にいればマイナス
	 */
	score += within_hisha(node->get_banmen());

	/*
	 *角が自分の陣地の外にいればマイナス
	 */
	score += within_kaku(node->get_banmen());

	return score;
}

/*
 *自分の王が自分の陣地内にいれば評価値を返す
 */
int within_ou(BANMEN *banmen){
	if(banmen->find_koma(EN_OU).get_y() <= 3) return WITHIN_OU;
	return 0;
}

/*
 *自分の飛車が自分の陣地内にいれば評価値を返す
 */
int within_hisha(BANMEN *banmen){
	if(banmen->find_koma(EN_HISHA).get_y() >= 3) return WITHIN_HISHA;
	return -WITHIN_HISHA;
}

/*
 *自分の王が自分の陣地内にいれば評価値を返す
 */
int within_kaku(BANMEN *banmen){
	if(banmen->find_koma(EN_KAKU).get_y() >= 3) return WITHIN_KAKU;
	return -WITHIN_KAKU;
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
