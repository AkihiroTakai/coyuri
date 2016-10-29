#ifndef VALUE_HPP
#define VALUE_HPP

#include <vector>
#include <array>
#include <functional>
#include <FL/Fl_PNG_Image.H>
#include "type.hpp"

extern Fl_PNG_Image *images[30];
extern Fl_PNG_Image *coyuri_images[4];
extern std::vector<Point> (*wcm_ftable[])(Point point);
extern KOMA_TYPE (*naru_ftable[])();
extern KOMA_TYPE main_ban[9][9];
extern Point TARGET_KOMA;
extern Fl_Box *target_ban[9][9];
extern Masu *visual_ban[9][9];
extern Fl_Box *message;
extern Fl_Box *coyuri;
extern std::vector<KOMA_TYPE> AI_TEGOMA;
extern std::vector<KOMA_TYPE> PLAYER_TEGOMA;
extern std::array<std::array<Tegoma *, 6>, 6> player_tegomas;
extern std::array<std::array<Tegoma *, 6>, 6> ai_tegomas;
extern KOMA_TYPE UTSU;
extern Point UTSU_KOMA;
extern bool player_finish_flag;
extern bool ai_finish_flag;

#endif
