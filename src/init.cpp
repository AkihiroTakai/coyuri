#include "../include/value.hpp"
#include "../include/type.hpp"
#include "../include/prot.hpp"

void images_path_init(){
	/*
	 *駒が置かれていない
	 */
	images[EMPTY]   = new Fl_PNG_Image("/home/takai/Pictures/coyuri/ban.png");
	images[TARGET]  = new Fl_PNG_Image("/home/takai/Pictures/coyuri/target.png");

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

/*
 *駒ｗｐ初期位置に配置する関数
 */
void put_koma_init(){
	for(int y = 1;y <= 9;y++){
		for(int x = 1;x <= 9;x++){
		      set_and_redraw(Point(x, y), EMPTY);
		}
	}
	/*
	 *味方
	 */
      set_and_redraw(Point(9, 9), KYOUSHA);
	set_and_redraw(Point(8, 9), KEIMA);
	set_and_redraw(Point(7, 9), GIN);
	set_and_redraw(Point(6, 9), KIN);
	set_and_redraw(Point(5, 9), OU);
	set_and_redraw(Point(1, 9), KYOUSHA);
	set_and_redraw(Point(2, 9), KEIMA);
	set_and_redraw(Point(3, 9), GIN);
	set_and_redraw(Point(4, 9), KIN);
	set_and_redraw(Point(2, 8), HISHA);
	set_and_redraw(Point(8, 8), KAKU);
	for(int i = 1;i <= 9;i++)
		set_and_redraw(Point(i, 7), HU);

	/*
	 *的側
	 */
	set_and_redraw(Point(9, 1), EN_KYOUSHA);
	set_and_redraw(Point(8, 1), EN_KEIMA);
	set_and_redraw(Point(7, 1), EN_GIN);
	set_and_redraw(Point(6, 1), EN_KIN);
	set_and_redraw(Point(5, 1), EN_OU);
	set_and_redraw(Point(1, 1), EN_KYOUSHA);
	set_and_redraw(Point(2, 1), EN_KEIMA);
	set_and_redraw(Point(3, 1), EN_GIN);
	set_and_redraw(Point(4, 1), EN_KIN);
	set_and_redraw(Point(8, 2), EN_HISHA);
	set_and_redraw(Point(2, 2), EN_KAKU);
	for(int i = 1;i <= 9;i++)
		set_and_redraw(Point(i, 3), EN_HU);

}

/*
 *初期化を行う関数
 */
void init(){
	images_path_init();
	put_koma_init();
	Fl_Box *gyou = new Fl_Box(100, 20, 550, 65, "九         　八　           七　            六             五             四           　三             　二　            一");
	Fl_Box *suji = new Fl_Box(650, 70, 110, 610, "1\n\n\n\n\n2\n\n\n\n\n3\n\n\n\n\n4\n\n\n\n\n5\n\n\n\n\n6\n\n\n\n\n7\n\n\n\n\n8\n\n\n\n\n9");
}
