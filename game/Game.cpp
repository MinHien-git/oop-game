#include"Game.h"

void Game::Start() {
	currentState = START;
	level.GenerateGrid();
}

void Game::Pause() {
	currentState = PAUSE;
}

void Game::Exit() {
	currentState = MENU;
}

void Game::End() {
	currentState = END;
}