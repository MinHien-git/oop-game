#pragma once

#include<iostream>
#include"Level.h"
#include<Windows.h>

using namespace std;

enum GAMESTATE {
	PAUSE,
	START,
	MENU,
	EXIT
};

class Game {
	GAMESTATE currentState = MENU;
	Level level;
	int score;
public:
	void Start();
	void Pause();
	void Exit();
	void SaveFile();
	void StartProgram();
	void Menu();
};
