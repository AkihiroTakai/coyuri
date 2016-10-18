#ifndef VALUE_HPP
#define VALUE_HPP

#include <vector>
#include <functional>
#include <FL/Fl_PNG_Image.H>
#include "../include/koma.hpp"

extern Fl_PNG_Image *images[17];
extern std::vector<std::function<std::vector<Point>(Point point)>> wcm_ftable;

#endif
