#include"Player.h"
#include"Level.h"

Player::Player() {
    currentX = 0;
    currentY = 0;
}

Player::Player(int x,int y) {
    currentX = x;
    currentY = y;
}

int Player::getX() {
    return currentX;
}

int Player::getY() {
    return currentY;
}

void Player::setPoint(int x,int y) {
    currentX = x;
    currentY = y;
}

void Player::PlayerMovement()
{
    int c;
    while (true) {
        c = 0;
        switch (c == getchar())
        {
        case 72:
            currentY++;
            break;
        case 80:
            currentY--;
            break;
        case 77:
            currentX--;
            break;
        case 75:
            currentX++;
            break;
        }

        this->setPoint(currentX, currentY);
    }
}

void Player::Destroy() {
    isDestroy = true;
}

bool Player::CompleteLevel() {
    return isDestroy;
}