#include "../include/koma.hpp"

/*/////////////////////////////////////////////////////////////
 *駒クラスの定義
 */
Koma::Koma(KOMA_TYPE type){
	Type = type;
}

Point Koma::get_point(){
	return point;
}

void Koma::move(Point p){
	point = p;
}

///////////////////////////////////////////////////////////////


/*/////////////////////////////////////////////////////////////
 *歩クラスの定義
 */

std::vector<Point> HU::where_can_move(){
	std::vector<Point> points;
	/*
	 *もしも敵の一番置くまで進んでいたら何も挿入せずに返す
	 */
	if(point.get_y() == 1) return points;
	/*
	 *座標を挿入
	 */
	points.push_back(Point(point.get_x(), point.get_y()-1));

	return points;
}

///////////////////////////////////////////////////////////////
