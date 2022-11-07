#pragma once

#include<iostream>
#include"Level.h"

using namespace std;

enum GAMESTATE {
	PAUSE,
	START,
	END,
	MENU
};

class Game {
	GAMESTATE currentState = MENU;
	Level level;
	void Start();
	void Pause();
	void Exit();
	void End();
};
