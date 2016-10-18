#ifndef PROT_HPP
#define PROT_HPP

#include <FL/Fl.H>
#include "../include/koma.hpp"

void draw_koma(Fl_Widget* widget, void *v);
int ctoi(char ch);
void init();
void set_and_redraw(Point p, KOMA_TYPE type);

#endif
