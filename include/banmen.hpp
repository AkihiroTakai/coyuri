#ifndef BANMEN_HPP
#define BANMEN_HPP

#include "type.hpp"

class Banmen {

	/*
	 *将棋の盤面
	 */
	KOMA_TYPE ban[9][9];

public:
	/*
	 *盤面に駒をセットするメソッド
	 */
	void set_koma(Point p, KOMA_TYPE type);
	/*
	 *指定した駒の座標を返すメソッド
	 */
	KOMA_TYPE get_koma(Point p);
};

#endif

