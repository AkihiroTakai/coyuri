#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main(int argc, char **argv){

	Fl_Window *win = new Fl_Window(500, 500, "Coyuri");

	Fl_Box *box = new Fl_Box(120, 120, 250, 250, "Coyuri");

	win->end();
	win->show(argc, argv);
	Fl::run();

}
