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

std::vector<Point> hu_wcm(Point point){
	std::vector<Point> points;

	jands_one_wcm(point.get_x(), point.get_y()-1, &points);
      /*
	 *もしも敵の一番置くまで進んでいたら何も挿入せずに返す
	 */
	//if(point.get_y() == 1) return points;
	/*
	 *座標を挿入
	 */
	//points.push_back(Point(point.get_x(), point.get_y()-1));

	return points;
}

std::vector<Point> kyousha_wcm(Point point){
	std::vector<Point> points;
      int x = point.get_x(), y = point.get_y();
      while(y > 0){
		y--;
		if(main_ban[x][y] != EMPTY) break;
		points.push_back(Point(x, y));
	}
	return points;
}

bool empty(int x, int y){
	return main_ban[x][y] == EMPTY;
}

bool enemy(int x, int y){
	return main_ban[x][y] >= EN_HU && main_ban[x][y] <= EN_OU;
}

bool my_koma(int x, int y){
	return main_ban[x][y] > TARGET && main_ban[x][y] < EN_HU;
}

bool can_target(int x, int y){
	return empty(x, y) || enemy(x, y) && x > 0 && x < 9 && y > 0 && y < 0;
}

void jands_one_wcm(int x, int y, std::vector<Point> *points){
	if(can_target(x, y))
		points->push_back(Point(x, y));
}
