#include "../include/prot.hpp"
#include "../include/value.hpp"

std::vector<Point> hu_wcm(Point point){
	std::vector<Point> points;

	/*
	 *一つ前方を確認
	 */
	jands_one_wcm(point.get_x(), point.get_y()-1, &points);

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
