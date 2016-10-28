#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include "../include/type.hpp"
#include "../include/prot.hpp"
#include <array>

const int IMAGE_SIDE = 70;
Masu *visual_ban[9][9];
Fl_Box *target_ban[9][9];
KOMA_TYPE main_ban[9][9];
Fl_PNG_Image *images[30];
Fl_PNG_Image *clear;
Point TARGET_KOMA;
Fl_Box *message;
Fl_Box *coyuri;
std::array<std::array<Tegoma *, 6>, 6> player_tegomas;
std::array<std::array<Tegoma *, 6>, 6> ai_tegomas;
KOMA_TYPE UTSU;
Point UTSU_KOMA;

std::vector<Point> (*wcm_ftable[])(Point point) = {
	null_wcm,
	NULL,
	hu_wcm,
	kyousha_wcm,
	keima_wcm,
	gin_wcm,
	kin_wcm,
	hisha_wcm,
	kaku_wcm,
	kin_wcm,
	kin_wcm,
	kin_wcm,
	kin_wcm,
	ryu_wcm,
	uma_wcm,
	ou_wcm,
	en_hu_wcm,
	en_kyousha_wcm,
	en_keima_wcm,
	en_gin_wcm,
	en_kin_wcm,
	en_hisha_wcm,
	en_kaku_wcm,
	en_kin_wcm,
	en_kin_wcm,
	en_kin_wcm,
	en_kin_wcm,
	en_ryu_wcm,
	en_uma_wcm,
	en_ou_wcm,
	tegoma_wcm
};

int main(int argc, char **argv){

	fl_register_images();
	Fl_Window win(1200, 1000, "Coyuri");

	UTSU = EMPTY;

      for(int y = 1;y <= 9;y++){
		for(int x = 1;x <= 9;x++){
			/*
			 *visual_banのためのboxを確保
			 */
			Masu *fl_box = new Masu(x*IMAGE_SIDE, y*IMAGE_SIDE, IMAGE_SIDE, IMAGE_SIDE);
			Masu *targ_box = new Masu(x*IMAGE_SIDE, y*IMAGE_SIDE, IMAGE_SIDE, IMAGE_SIDE);

                  /*
			 *画像は最初何も入れない
			 */
			fl_box->image(NULL);
			targ_box->image(NULL);
			/*
			 *裏で動く盤面変数はすべてEMPTYで初期化
			 */
			main_ban[x-1][y-1]   = EMPTY;
			/*
			 *visual_banにNULLの画像が入ったboxを代入していく
			 */
			visual_ban[x-1][y-1] = fl_box;
			target_ban[x-1][y-1] = targ_box;
		}
	}
	for(int y = 0;y < 6;y++){
		for(int x = 0;x < 6;x++){
			player_tegomas[x][y] = new Tegoma(70*x+749, 70*y+500, 70, 70, x, y, EMPTY);
			player_tegomas[x][y]->image(images[EMPTY]);
		}
	}
	for(int y = 0;y < 6;y++){
		for(int x = 0;x < 6;x++){
			ai_tegomas[x][y] = new Tegoma(70*x+749, 70*y+49, 70, 70, x, y, EMPTY);
			ai_tegomas[x][y]->image(images[EMPTY]);
		}
	}

	clear = new Fl_PNG_Image("/home/takai/Pictures/coyuri/clear.png");
	init();
	Fl_Button *next = new Fl_Button(600, 750, 50, 50, "next");
	next->callback(AI_START);

	message = new Fl_Box(300, 800, 300, 50, "将棋は初めてなのでお手柔らかにお願いしますね。");

	//coyuri = new Fl_Box(50, 700, 300, 300);
	//coyuri->image(new Fl_PNG_Image("/home/takai/Downloads/Untitled.png"));
	win.end();
	win.show(argc, argv);

	return Fl::run();
}

/*
 *charからintへ変換
 */
int ctoi(char ch){
	if('0' <= ch && ch <= '9') return (ch-'0');
	else return -1;
}
