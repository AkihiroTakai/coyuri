#include "../include/prot.hpp"
#include "../include/value.hpp"
#include <iostream>

/*
 *wcm関数内では通常の将棋の盤面を操作する感じで行う
 */

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
	int y = point.get_y()-1;
	while(jands_one_wcm(point.get_x(), y, &points)){
		y--;
	}
	return points;
}

//桂馬のwcm関数
std::vector<Point> keima_wcm(Point p){
	std::vector<Point> points;

	/*
	 *２つ前に進めない位置にいる場合移動できない
	 */
	if(p.get_y() <= 2) return points;

	if(can_target(p.get_x() + 1, p.get_y() - 2))
		points.push_back(Point(p.get_x() + 1, p.get_y() - 2));

	if(can_target(p.get_x() - 1, p.get_y() - 2))
		points.push_back(Point(p.get_x() - 1, p.get_y() - 2));

	return points;
}

//銀のwcm関数
std::vector<Point> gin_wcm(Point p){
	std::vector<Point> points;

	/*
	 *前方方向の移動可能判定
	 */
	jands_one_wcm(p.get_x()-1, p.get_y()-1, &points);
	jands_one_wcm(p.get_x(), p.get_y()-1, &points);
	jands_one_wcm(p.get_x()+1, p.get_y()-1, &points);

	/*
	 *後方方向の移動可能判定
	 */
	jands_one_wcm(p.get_x()-1, p.get_y()+1, &points);
	jands_one_wcm(p.get_x()+1, p.get_y()+1, &points);

	return points;
}

//銀のwcm関数
std::vector<Point> kin_wcm(Point p){
	std::vector<Point> points;

	/*
	 *前方方向の移動可能判定
	 */
	jands_one_wcm(p.get_x()-1, p.get_y()-1, &points);
	jands_one_wcm(p.get_x(), p.get_y()-1, &points);
	jands_one_wcm(p.get_x()+1, p.get_y()-1, &points);

	/*
	 *横方向の移動可能判定
	 */
	jands_one_wcm(p.get_x()-1, p.get_y(), &points);
	jands_one_wcm(p.get_x()+1, p.get_y(), &points);

	/*
	 *後方方向の移動可能判定
	 */
	jands_one_wcm(p.get_x(), p.get_y()+1, &points);

	return points;
}

//飛車のwcm関数
std::vector<Point> hisha_wcm(Point p){
	std::vector<Point> points;

	/*
	 *左方向の移動可能判定
	 */
	for(int x = p.get_x()-1;x > 0;x--){
		if(!jands_one_wcm(x, p.get_y(), &points)) break;
	}

	/*
	 *左方向の移動可能判定
	 */
	for(int x = p.get_x()+1;x <= 9;x++){
		if(!jands_one_wcm(x, p.get_y(), &points)) break;
	}

	/*
	 *下方向の移動可能判定
	 */
	for(int y = p.get_y()+1;y <= 9;y++){
		if(!jands_one_wcm(p.get_y(), y, &points)) break;
	}

	/*
	 *上方向の移動可能判定
	 */
	for(int y = p.get_y()-1;y > 0;y--){
		if(!jands_one_wcm(p.get_y(), y, &points)) break;
	}

	return points;
}

//角のwcm関数
std::vector<Point> kaku_wcm(Point p){
	std::vector<Point> points;

	int x = p.get_x()-1, y = p.get_y()-1;
	/*
	 *右上方向の移動可能判定
	 */
      while(jands_one_wcm(x, y, &points)){
		x--;
		y--;
	}

	x = p.get_x()+1;
	y = p.get_y()-1;
	/*
	 *左上方向の移動可能判定
	 */
	while(jands_one_wcm(x, y, &points)){
		x++;
		y--;
	}

      x = p.get_x()-1;
	y = p.get_y()+1;
	/*
	 *右下方向の移動可能判定
	 */
	while(jands_one_wcm(x, y, &points)){
		x--;
		y++;
	}

	x = p.get_x()+1;
	y = p.get_y()+1;
	/*
	 *右下方向の移動可能判定
	 */
	while(jands_one_wcm(x, y, &points)){
		x++;
		y++;
	}

	return points;
}

//王将のwcm関数
std::vector<Point> ou_wcm(Point p){
	std::vector<Point> points;

	//前方方向の移動可能判定
	jands_one_wcm(p.get_x(), p.get_y()-1, &points);
	jands_one_wcm(p.get_x()-1, p.get_y()-1, &points);
	jands_one_wcm(p.get_x()+1, p.get_y()-1, &points);

	//横方向の移動可能判定
	jands_one_wcm(p.get_x()+1, p.get_y(), &points);
	jands_one_wcm(p.get_x()-1, p.get_y(), &points);

	//後方方向の移動可能判定
	jands_one_wcm(p.get_x(), p.get_y()+1, &points);
	jands_one_wcm(p.get_x()-1, p.get_y()+1, &points);
	jands_one_wcm(p.get_x()+1, p.get_y()+1, &points);

	return points;
}

std::vector<Point> target_move(Point p){
	move(p);
}
