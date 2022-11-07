#include"Game.h"

void Game::Start() {
	currentState = START;
	while(!level.LevelIsComplete())
		level.GenerateGrid();
	if (level.PlayerCompleteLevel())
	{
		score++;
	}
	// Quay ve mang hinh chinh hoac hoi player co choi lai hay k
}

void Game::Pause() {
	currentState = PAUSE;
}

void Game::Exit() {
	currentState = EXIT;
}

void Game::Menu() {
	currentState = MENU;
	int ch;
	while (ch = getch()) {
		switch (ch)
		{
			case 1:case2:case 3:
				break;
		}
	}
	system("cls");
	switch (ch)
	{
		case 1:
			Start();
			break;
		case 2:
			break;
		case 3:
			break;
	}
}

void Game::StartProgram() {
	while (currentState != EXIT) {
		
	}
	exit(3);
}