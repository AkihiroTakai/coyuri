#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include "../include/type.hpp"
#include "../include/prot.hpp"

const int IMAGE_SIDE = 70;
Masu *visual_ban[9][9];
Fl_Box *target_ban[9][9];
KOMA_TYPE main_ban[9][9];
Fl_PNG_Image *images[18];
Fl_PNG_Image *clear;
Point TARGET_KOMA;

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
	ou_wcm
};

int main(int argc, char **argv){

	fl_register_images();
	Fl_Window win(740, 900, "Coyuri");

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
	clear = new Fl_PNG_Image("/home/takai/Pictures/coyuri/clear.png");
	init();
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
