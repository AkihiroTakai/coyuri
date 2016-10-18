#ifndef PROT_HPP
#define PROT_HPP

#include <FL/Fl.H>
#include "type.hpp"

void draw_koma(Fl_Widget* widget, void *v);
int ctoi(char ch);
void init();
void set_and_redraw(Point p, KOMA_TYPE type);
std::vector<Point> where_can_move(Point point, KOMA_TYPE type);
std::vector<Point> hu_wcm(Point point);

#endif
