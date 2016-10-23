#include "../include/value.hpp"
#include "../include/prot.hpp"
#include <iostream>
#include <FL/fl_ask.H>

void move(Point replace){
	std::cout << "move\n";
	
	if(replace.get_y() <= 3){
		if(fl_ask("成りますか？")){
			/*
			 *成る処理
			 */
			main_ban[9-replace.get_x()][replace.get_y()-1] = (KOMA_TYPE)(main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()]+6);
			main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()] = EMPTY;
			return;
		}
	}

	/*
	 *このときはmain_banを更新するだけ
	 */
	main_ban[9-replace.get_x()][replace.get_y()-1] = main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()];
	main_ban[TARGET_KOMA.get_x()][TARGET_KOMA.get_y()] = EMPTY;

}
