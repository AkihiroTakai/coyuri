#ifndef PROT_HPP
#define PROT_HPP

#include <FL/Fl.H>
#include "type.hpp"

void draw_koma(Fl_Widget* widget, void *v);
int ctoi(char ch);
void init();
void set_and_redraw(Point p, KOMA_TYPE type);
std::vector<Point> where_can_move(Point point, KOMA_TYPE type);
bool empty(int x, int y);
bool enemy(int x, int y);
bool my_koma(int x, int y);
bool can_target(int x, int y);
bool jands_one_wcm(int x, int y, std::vector<Point> *points);
std::vector<Point> hu_wcm(Point point);
std::vector<Point> kyousha_wcm(Point point);
std::vector<Point> keima_wcm(Point p);
std::vector<Point> gin_wcm(Point p);
std::vector<Point> kin_wcm(Point p);
std::vector<Point> hisha_wcm(Point p);
std::vector<Point> kaku_wcm(Point p);
std::vector<Point> ou_wcm(Point p);

#endif
