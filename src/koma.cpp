#include "../include/type.hpp"

std::vector<Point> where_can_move(Point point, KOMA_TYPE type){
	std::vector<Point> points;
	switch(type){
	case HU:
		/*
		 *もしも敵の一番置くまで進んでいたら何も挿入せずに返す
		 */
		if(point.get_y() == 1) break;
		/*
		 *座標を挿入
		 */
		points.push_back(Point(point.get_x(), point.get_y()-1));
		break;
	default:
		break;
	}
	return points;
}

