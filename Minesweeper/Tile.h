#pragma once
#define BLANK 0
#define BOMB 9
#define UNCLICK 10
#define FLAG 11
#define WRONG 12
#define BOOM 13
#define WALL -99
#include <string>
using namespace std;
class Tile {
public:
	bool clicked;
	bool flag;
	bool bomb;
	int val;

	Tile() {
		clicked = false;
		flag = false;
		bomb = false;
		val = -99;
	}
	string state() {
		if (clicked && !bomb) {
			return " " + to_string(val);
		}
		if (!clicked && flag) {
			return "в╣";
		}
		if (clicked && bomb) {
			return " *";
		}
		else {
			return "бс";
		}
	}
};

