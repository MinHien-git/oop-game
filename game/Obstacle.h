#pragma once
#include<iostream>

using namespace std;

enum OBSTACLETYPE {
	CAR,TRUCK
};

class Obstacle {
	int gap;
	long speed;
public:
	Obstacle(int g, long s);
};