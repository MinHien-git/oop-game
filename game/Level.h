#pragma once
#include <iostream>
#include <deque>
#include<thread>
#include<chrono>
#include<Windows.h>
#include"Player.h"
#include <conio.h>
#include<string>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

enum INGAMESTATE {
    PAUSED,
    PROCESSING,
    ENDED,
};

class Level {
    deque<deque<int>> grid = deque<deque<int>>(10, deque<int>(10, 0));
    Player player;
    INGAMESTATE gameState = PROCESSING;
    string playerName;
    int currentLevel = 0;
    bool isComplete = false;
public:
    Level();
    Level(int score);

    void DrawGrid();    
    void VehicleLine(deque<int>& vect,int index);
    void TruckLine(deque<int>& vect, int index);
    void UpdateGrid();
    void GenerateVehicle(int index);
    void GenerateGrid();
    void ClearPlayerOnGrid();
    void UpdatePlayerOnGrid();
    void HandlePlayerMovementOnGrid();
    void SavePlayer();

    int* DynamicSpawn(int start,int end,int limit);
    
    bool LevelIsComplete();
    bool PlayerCompleteLevel();
};