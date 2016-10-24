#include "../include/value.hpp"
#include "../include/prot.hpp"
#include <iostream>
#include <FL/fl_ask.H>

void move(Point replace){
	std::cout << "move\n";

	if(replace.get_y() <= 3 && !(main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()] >= TOKIN && main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()] <= UMA)){
		if(fl_ask("成りますか？")){
			/*
			 *成る処理
			 */

			if(main_ban[9-replace.get_x()][replace.get_y()-1] != EMPTY){
				//手駒を取れたら
				PLAYER_TEGOMA.push_back(main_ban[9-replace.get_x()][replace.get_y()-1]);
				player_tegomas[PLAYER_TEGOMA.size()-1]->set_type(main_ban[9-replace.get_x()][replace.get_y()-1]);

			}

			set_and_redraw(Point(replace.get_x(), replace.get_y()),(KOMA_TYPE)(main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()]+6));
			set_and_redraw(Point(9-TARGET_KOMA.get_x(), TARGET_KOMA.get_y()+1), EMPTY);

			return;
		}
	}

	/*
	 *このときはmain_banを更新するだけ
	 */
	/*
	 *成る処理
	 */

	if(main_ban[9-replace.get_x()][replace.get_y()-1] != EMPTY){
		//手駒を取れたら
		PLAYER_TEGOMA.push_back(main_ban[9-replace.get_x()][replace.get_y()-1]);
	}
	set_and_redraw(Point(replace.get_x(), replace.get_y()), main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()]);
	set_and_redraw(Point(9-TARGET_KOMA.get_x(), TARGET_KOMA.get_y()+1), EMPTY);

}
