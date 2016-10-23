#ifndef TYPE_HPP
#define TYPE_HPP

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <string>
#include <vector>

enum KOMA_TYPE {
	EMPTY, TARGET,
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

class Masu : public Fl_Box {
	int X, Y;
	int handle(int event);

public:
    	Masu(int x, int y, int width, int height);
	int get_x(){return X;}
	int get_y(){return Y;};
};

class BANMEN {
	KOMA_TYPE **banmen;
public:
	BANMEN();
	~BANMEN();
	KOMA_TYPE get_type(int x, int y);
	void set_type(int x, int y, KOMA_TYPE type);
	void copy_banmen(BANMEN *original);
	Point find_koma(KOMA_TYPE type);
};

class Node {

	BANMEN *banmen;
	Node *parent;
	std::vector<Node *> children;
	int evalue;

public:
	~Node();
	Node(BANMEN *ban, Node *pare);
	BANMEN *get_banmen();
	std::vector<Node *> *get_children();
	int get_evalue();
	void set_evalue(int value);

};

#endif
