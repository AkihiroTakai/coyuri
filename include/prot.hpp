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
bool ai_can_target(int x, int y);
bool jands_one_wcm(int x, int y, std::vector<Point> *points);
bool ai_jands_one_wcm(int x, int y, std::vector<Point> *points);
std::vector<Point> null_wcm(Point p);
std::vector<Point> hu_wcm(Point point);
std::vector<Point> kyousha_wcm(Point point);
std::vector<Point> keima_wcm(Point p);
std::vector<Point> gin_wcm(Point p);
std::vector<Point> kin_wcm(Point p);
std::vector<Point> hisha_wcm(Point p);
std::vector<Point> kaku_wcm(Point p);
std::vector<Point> ryu_wcm(Point p);
std::vector<Point> uma_wcm(Point p);
std::vector<Point> ou_wcm(Point p);
std::vector<Point> en_hu_wcm(Point point);
std::vector<Point> en_kyousha_wcm(Point point);
std::vector<Point> en_keima_wcm(Point p);
std::vector<Point> en_gin_wcm(Point p);
std::vector<Point> en_kin_wcm(Point p);
std::vector<Point> en_hisha_wcm(Point p);
std::vector<Point> en_kaku_wcm(Point p);
std::vector<Point> en_ou_wcm(Point p);
std::vector<Point> en_ryu_wcm(Point p);
std::vector<Point> en_uma_wcm(Point p);
void target_masu(Point p);
void target_clear();
void move(Point replace);
int EVAL(Node *node);
void PLAYER_EXPAND(Node *node);
void EXPAND(Node *node);
void ai_turn(Node *root);
Node *max(Node *node, int limit);
Node *min(Node *node, int limit);
void destroy_tree(Node *root);

#endif
