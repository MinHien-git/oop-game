#pragma once
#include <iostream>
#include <deque>
#include<thread>
#include<chrono>
#include<Windows.h>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

class Player {
    int currentX;
    int currentY;
public:
    Player();
    Player(int x, int y);
   
    int getX();
    int getY();
    void setPoint(int x,int y);
    void PlayerMovement();
    
};