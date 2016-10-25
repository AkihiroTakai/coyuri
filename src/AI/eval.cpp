#include "../../include/type.hpp"
#include "../../include/value.hpp"
#include "../../include/prot.hpp"
#include <cmath>
#include <iostream>

const int WITHIN_OU     = 5;
const int WITHIN_HISHA  = 3;
const int WITHIN_KAKU   = 2;
const int WITHIN_PLAYER = -15;
const int PLAYER_HISHA  = 30;
const int PLAYER_KAKU   = 27;

const int HU_EVAL = 10;
const int KYOUSHA_EVAL = 15;
const int KEIMA_EVAL = 15;
const int GIN_EVAL = 30;
const int KIN_EVAL = 50;
const int HISHA_EVAL = 100;
const int KAKU_EVAL = 95;
const int OU_EVAL = 1000;
const int TOKIN_EVAL = 55;
const int NARIKYOU_EVAL = 55;
const int NARIKEI_EVAL = 55;
const int NARIGIN_EVAL = 55;
const int RYU_EVAL = 150;
const int UMA_EVAL = 140;


int within_ou(BANMEN *banmen);
int within_hisha(BANMEN *banmen);
int within_kaku(BANMEN *banmen);
int within_player(BANMEN *banmen);
int num_on_ban(BANMEN *banmen);
int player_hisha(BANMEN *banmen);
int player_kaku(BANMEN *banmen);

/*
 *注
 *ここで言う"敵"とはプレイヤーのこと
 *"自分"というのはAIのこと
 */

int EVAL(Node *node){
	int score = 0;
	int counters[30] = {0};
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

	/*
	 *自分の陣地にプレーヤーの駒が入ってくる場合
	 */
	score += within_player(node->get_banmen());

	/*
	 *自分の駒が盤面に何枚残っているか
	 */
	score += num_on_ban(node->get_banmen());

	for(int y = 0;y < 9;y++){
		for(int x = 0;x < 9;x++){
			counters[main_ban[x][y]]++;
		}
	}

	score -= counters[2]*HU_EVAL;
	score -= counters[3]*KYOUSHA_EVAL;
	score -= counters[4]*KEIMA_EVAL;
	score -= counters[5]*GIN_EVAL;
	score -= counters[6]*KIN_EVAL;
	score -= counters[7]*HISHA_EVAL;
	score -= counters[8]*KAKU_EVAL;
	score -= counters[9]*TOKIN_EVAL;
	score -= counters[10]*NARIKYOU_EVAL;
	score -= counters[11]*NARIKEI_EVAL;
	score -= counters[12]*NARIGIN_EVAL;
	score -= counters[13]*RYU_EVAL;
	score -= counters[14]*UMA_EVAL;
	score -= counters[15]*OU_EVAL;
	score += counters[16]*HU_EVAL;
	score += counters[17]*KYOUSHA_EVAL;
	score += counters[18]*KEIMA_EVAL;
	score += counters[19]*GIN_EVAL;
	score += counters[20]*KIN_EVAL;
	score += counters[21]*HISHA_EVAL;
	score += counters[22]*KAKU_EVAL;
	score += counters[23]*TOKIN_EVAL;
	score += counters[24]*NARIKYOU_EVAL;
	score += counters[25]*NARIKEI_EVAL;
	score += counters[26]*NARIGIN_EVAL;
	score += counters[27]*RYU_EVAL;
	score += counters[28]*UMA_EVAL;
	score += counters[29]*OU_EVAL;

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
 *自分の陣地にプレーヤーの駒が入ってくる場合
 */
int within_player(BANMEN *banmen){
	for(int y = 0;y < 3;y++)
		for(int x = 0;x < 9;x++)
			if(banmen->get_type(x, y) >= HU && banmen->get_type(x, y) <= OU)
				return WITHIN_PLAYER;

	return -WITHIN_PLAYER;
}

/*
 *自分の陣地にプレーヤーの駒が入ってくる場合
 */
int num_on_ban(BANMEN *banmen){
	int count;
	for(int y = 0;y < 9;y++)
		for(int x = 0;x < 9;x++)
			if(banmen->get_type(x, y) >= EN_HU && banmen->get_type(x, y) <= EN_OU)
			     count++;

	return count*2;
}

/*
 *盤面上にプレイヤーの飛車(龍も含む)はいるか
 */
int player_hisha(BANMEN *banmen){
	if(banmen->find_koma(HISHA).get_x() != -1 && banmen->find_koma(RYU).get_x() != -1)
		return 0;
	return PLAYER_HISHA;
}


/*
 *盤面上にプレイヤーの角(馬も含む)はいるか
 */
int player_kaku(BANMEN *banmen){
	if(banmen->find_koma(KAKU).get_x() != -1 && banmen->find_koma(UMA).get_x() != -1)
		return 0;

	return PLAYER_KAKU;
}


/*
 *渡された盤面からコンピュータがさせる手をすべてリストアップする関数
 */
void EXPAND(Node *node){

	for(int x = 0;x < 9;x++){
		for(int y = 0;y < 9;y++){
			if(node->get_banmen()->get_type(x, y) >= EN_HU && node->get_banmen()->get_type(x, y) <= EN_OU){
				for(Point p : wcm_ftable[node->get_banmen()->get_type(x, y)](Point(std::abs(x-9), y+1))){
					BANMEN *new_banmen = new BANMEN;
					new_banmen->copy_banmen(node->get_banmen());
					new_banmen->set_type(9-p.get_x(), p.get_y()-1, node->get_banmen()->get_type(x, y));
					new_banmen->set_type(x, y, EMPTY);
					node->get_children()->push_back(new Node(new_banmen, node));
				}
			}
		}
	}

	/*
	 *AIが持ち駒を打つ場合
	 */
	for(KOMA_TYPE koma : AI_TEGOMA){
		for(Point p : tegoma_wcm(Point(-1, -1))){
			BANMEN *new_banmen = new BANMEN;
			new_banmen->copy_banmen(node->get_banmen());
			new_banmen->set_type(9-p.get_x(), p.get_y()-1, koma);
			node->get_children()->push_back(new Node(new_banmen, node));
		}
	}
}

/*
 *渡された盤面からプレイヤーがさせる手をすべてリストアップする関数
 */
void PLAYER_EXPAND(Node *node){

	for(int x = 0;x < 9;x++){
		for(int y = 0;y < 9;y++){
			if(node->get_banmen()->get_type(x, y) >= HU && node->get_banmen()->get_type(x, y) <= OU){
				for(Point p : wcm_ftable[node->get_banmen()->get_type(x, y)](Point(std::abs(x-9), y+1))){
					BANMEN *new_banmen = new BANMEN;
					new_banmen->copy_banmen(node->get_banmen());
					new_banmen->set_type(9-p.get_x(), p.get_y()-1, node->get_banmen()->get_type(x, y));
					new_banmen->set_type(x, y, EMPTY);
					node->get_children()->push_back(new Node(new_banmen, node));
				}
			}
		}
	}
}
