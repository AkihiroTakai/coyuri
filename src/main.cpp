#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include "../include/koma.hpp"

const int IMAGE_SIDE = 45;
Fl_Box *ban[9][9];
Fl_PNG_Image *images[17];

void draw_koma(Fl_Widget* widget, void *v);
int ctoi(char ch);
void init();
void set_and_redraw(Point p, Fl_PNG_Image *image);

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
	
	init();

	win.end();
	win.show(argc, argv);

	return Fl::run();
}

void images_path_init(){
	/*
	 *駒が置かれていない
	 */
	images[EMPTY]   = new Fl_PNG_Image("/home/takai/Pictures/coyuri/ban.png");

	/*
	 *味方
	 */
	images[HU]      = new Fl_PNG_Image("/home/takai/Pictures/coyuri/hu.png");
	images[KYOUSHA] = new Fl_PNG_Image("/home/takai/Pictures/coyuri/kyousha.png");
	images[KEIMA]   = new Fl_PNG_Image("/home/takai/Pictures/coyuri/keima.png");
      images[GIN]     = new Fl_PNG_Image("/home/takai/Pictures/coyuri/gin.png");
	images[KIN]     = new Fl_PNG_Image("/home/takai/Pictures/coyuri/kin.png");
	images[HISHA]   = new Fl_PNG_Image("/home/takai/Pictures/coyuri/hisha.png");
	images[KAKU]    = new Fl_PNG_Image("/home/takai/Pictures/coyuri/kaku.png");
	images[OU]      = new Fl_PNG_Image("/home/takai/Pictures/coyuri/ou.png");

	/*
	 *敵側
	 */
	images[EN_HU]      = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_hu.png");
	images[EN_KYOUSHA] = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_kyousha.png");
	images[EN_KEIMA]   = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_keima.png");
	images[EN_GIN]     = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_gin.png");
	images[EN_KIN]     = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_kin.png");
	images[EN_HISHA]   = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_hisha.png");
	images[EN_KAKU]    = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_kaku.png");
	images[EN_OU]      = new Fl_PNG_Image("/home/takai/Pictures/coyuri/en_ou.png");
}


void put_koma_init(){
	/*
	 *味方
	 */
      set_and_redraw(Point(8, 8), images[KYOUSHA]);
	set_and_redraw(Point(7, 8), images[KEIMA]);
	set_and_redraw(Point(6, 8), images[GIN]);
	set_and_redraw(Point(5, 8), images[KIN]);
	set_and_redraw(Point(4, 8), images[OU]);
	set_and_redraw(Point(0, 8), images[KYOUSHA]);
	set_and_redraw(Point(1, 8), images[KEIMA]);
	set_and_redraw(Point(2, 8), images[GIN]);
	set_and_redraw(Point(3, 8), images[KIN]);
	set_and_redraw(Point(1, 7), images[HISHA]);
	set_and_redraw(Point(7, 7), images[KAKU]);
	for(int i = 0;i < 9;i++)
		set_and_redraw(Point(i, 6), images[HU]);

	/*
	 *的側
	 */
	set_and_redraw(Point(8, 0), images[EN_KYOUSHA]);
	set_and_redraw(Point(7, 0), images[EN_KEIMA]);
	set_and_redraw(Point(6, 0), images[EN_GIN]);
	set_and_redraw(Point(5, 0), images[EN_KIN]);
	set_and_redraw(Point(4, 0), images[EN_OU]);
	set_and_redraw(Point(0, 0), images[EN_KYOUSHA]);
	set_and_redraw(Point(1, 0), images[EN_KEIMA]);
	set_and_redraw(Point(2, 0), images[EN_GIN]);
	set_and_redraw(Point(3, 0), images[EN_KIN]);
	set_and_redraw(Point(1, 1), images[EN_HISHA]);
	set_and_redraw(Point(7, 1), images[EN_KAKU]);
	for(int i = 0;i < 9;i++)
		set_and_redraw(Point(i, 2), images[EN_HU]);

}

void init(){
	images_path_init();
	put_koma_init();
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

void set_and_redraw(Point p, Fl_PNG_Image *image){
	ban[p.get_x()][p.get_y()]->image(image);
	ban[p.get_x()][p.get_y()]->redraw();
}
