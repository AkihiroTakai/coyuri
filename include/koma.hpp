#ifndef KOMA_HPP
#define KOMA_HPP

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <string>
#include <vector>

enum KOMA_TYPE {
	EMPTY,
	HU, KYOUSHA, KEIMA, GIN, KIN, HISHA, KAKU, OU,
	EN_HU, EN_KYOUSHA, EN_KEIMA, EN_GIN, EN_KIN, EN_HISHA, EN_KAKU, EN_OU
};

class Point {
	/*
	 *座標の位置を保持する変数
	 */
	int X, Y;
public:
	/*
	 *コンストラクタ
	 */
	Point(int x, int y);
	Point();
	/*
	 *getter/setter
	 */
	int get_x();
	int get_y();
	void set_x(int x);
	void set_y(int y);
};

class Koma {

protected:
	/*
	 *駒の種類
	 */
	KOMA_TYPE Type;
	/*
	 *置かれている座標
	 */
	Point point;
public:
	/*
	 *コンストラクタ
	 */
	Koma(KOMA_TYPE type);
	/*
	 *setter/getter
	 */
	Point get_point();

	/*
	 *駒を指定する座標を移動させるメソッド
	 *必ずwhere_can_move関数を使って求めた座標に移動させること
	 */
	void move(Point p);
	/*
	 *駒が動ける座標をstd::vectorにして返すメソッド
	 */
	virtual std::vector<Point> where_can_move();

	/*
	 *駒が成るときに使うメソッド
	 */
	virtual Koma naru();
};

class HU : Koma {

public:
	std::vector<Point> where_can_move();
	Koma naru();

};

#endif
