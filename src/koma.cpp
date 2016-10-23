#include "../include/type.hpp"
#include "../include/value.hpp"
#include "../include/prot.hpp"

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

bool empty(int x, int y){
	return main_ban[9-x][y-1] == EMPTY;
}

bool enemy(int x, int y){
	return main_ban[9-x][y-1] >= EN_HU && main_ban[9-x][y-1] <= EN_OU;
}

bool my_koma(int x, int y){
	return main_ban[9-x][y-1] >= HU && main_ban[9-x][y-1] <= OU;
}

bool can_target(int x, int y){
	return (empty(x, y) || enemy(x, y)) && (x > 0 && x <= 9) && (y > 0 && y <= 9);
}

bool jands_one_wcm(int x, int y, std::vector<Point> *points){
	if(enemy(x, y) && (x > 0 && x <= 9) && (y > 0 && y <= 9)){
		points->push_back(Point(x, y));
		return false;
	}
	if(can_target(x, y)){
		points->push_back(Point(x, y));
		return true;
	}
	return false;
}

bool ai_can_target(int x, int y){
	return (empty(x, y) || my_koma(x, y)) && (x > 0 && x <= 9) && (y > 0 && y <= 9);
}


bool ai_jands_one_wcm(int x, int y, std::vector<Point> *points){
	if(my_koma(x, y) && (x > 0 && x <= 9) && (y > 0 && y <= 9)){
		points->push_back(Point(x, y));
		return false;
	}
	if(ai_can_target(x, y)){
		points->push_back(Point(x, y));
		return true;
	}
	return false;
}
