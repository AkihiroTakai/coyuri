#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

const int IMAGE_SIDE = 45;
Fl_Box *ban[9][9];

void draw_koma(Fl_Widget* widget);

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

	Fl_Input* input = new Fl_Input(200, 640, 70, 30, "手:");
	Fl_Button* button = new Fl_Button(300, 630, 50, 50, "打つ");
	button->callback(draw_koma);

	win.end();
	win.show(argc, argv);

	return Fl::run();
}

void draw_koma(Fl_Widget* widget){
	ban[7][7]->image(new Fl_PNG_Image("/home/takai/Pictures/coyuri/kyousha.png"));
	ban[7][7]->redraw();
}
