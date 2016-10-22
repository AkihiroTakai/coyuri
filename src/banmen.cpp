#include "../include/type.hpp"

KOMA_TYPE BANMEN::get_type(int x, int y){
	return banmen[x][y];
}

void BANMEN::set_type(int x, int y, KOMA_TYPE type){
	banmen[x][y] = type;
}

void BANMEN::copy_banmen(BANMEN *original){
	for(int x = 0;x < 9;x++){
		for(int y = 0;y < 9;y++){
			banmen[x][y] = original->get_type(x, y);
		}
	}
}

Point BANMEN::find_koma(KOMA_TYPE type){
	for(int x = 0;x < 9;x++)
		for(int y = 0;y < 9;y++)
			if(banmen[x][y] == type) return Point(x, y);
}

Node::Node(BANMEN *ban, Node *pare){
	banmen.copy_banmen(ban);
	parent = pare;
}

BANMEN *Node::get_banmen(){
	return &banmen;
}

std::vector<Node *> *Node::get_children(){
	return &children;
}
