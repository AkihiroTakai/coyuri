#ifndef VALUE_HPP
#define VALUE_HPP

#include <vector>
#include <functional>
#include <FL/Fl_PNG_Image.H>
#include "type.hpp"

extern Fl_PNG_Image *images[17];
extern std::vector<Point> (*wcm_ftable[])(Point point);
extern KOMA_TYPE main_ban[9][9];
extern Point TARGET_KOMA;

#endif
