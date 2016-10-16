#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include "../include/koma.hpp"

const int IMAGE_SIDE = 45;
Fl_Box *ban[9][9];

void draw_koma(Fl_Widget* widget, void *v);
int ctoi(char ch);
void init();

int main(int argc, char **argv){

	fl_register_images();
	Fl_Window win(610, 700, "Coyuri");

	Fl_PNG_Image img("/home/takai/Pictures/coyuri/ban.png");

      for(int y = 0;y < 9;y++){
		for(int x = 0;x < 9;x++){
			Fl_Box *fl_box = new Fl_Box(x*IMAGE_SIDE, y*IMAGE_SIDE, x*IMAGE_SIDE+70, y*IMAGE_SIDE+70);
			fl_box->image(img);
			ban[x][y] = fl_box;
		}
	}

	Fl_Input *input = new Fl_Input(200, 640, 70, 30, "手:");
	Fl_Button *button = new Fl_Button(300, 630, 50, 50, "打つ");

	void* v[] = {input};
	button->callback(draw_koma, v);

	win.end();
	win.show(argc, argv);

	return Fl::run();
}

void init(){
	
}

/*
 *駒を描画する関数
 */
void draw_koma(Fl_Widget* widget, void *v){
      std::string input = ((Fl_Input*)((void**)v)[0])->value();
	int x, y;
	x = ctoi(input.c_str()[0]);
	y = ctoi(input.c_str()[1]);
	ban[x-1][y-1]->image(new Fl_PNG_Image("/home/takai/Pictures/coyuri/kyousha.png"));
	ban[x-1][y-1]->redraw();
}

/*
 *charからintへ変換
 */
int ctoi(char ch){
	if('0' <= ch && ch <= '9') return (ch-'0');
	else return -1;
}
