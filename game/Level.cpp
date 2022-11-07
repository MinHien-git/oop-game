#include"Level.h"

Level::Level() {
    player.setPoint(4,9);
}

Level::Level(int score) {
    currentLevel = score;
}

void Level::DrawGrid() {
    system("cls");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Level::VehicleLine(deque<int>& vect,int index) {
    vect[9] = 1;
    while (gameState == PROCESSING)
    {
        fflush(stdin);
        sleep_for(milliseconds(1000));
        vect.pop_front();
        /// gap bằng 2 do đi từ phải sang trái nên vect[9-2]
        /// Nếu đi từ trái sang phải thì index = gap - 1
        if (vect[9 - 3] == 1) {
            vect.push_back(1);
        }
        else {
            vect.push_back(0);
        }
        if (player.getY() == index) {
            int x = player.getX() - 1;
            grid[index][x] = 0;
            if(grid[index][x + 1] == 0)
                grid[index][x+1] = 2;
            else {
                gameState = ENDED;
                break;
            }
        }
    }
    cout << "Player got hit";
}

void Level::TruckLine(deque<int>& vect, int index)
{
    vect[9] = 1;
    vect[8] = 1;
    while (true)
    {
        sleep_for(milliseconds(1000));
        system("cls");
        vect.pop_front();
        /// gap bằng 2 do đi từ phải sang trái nên vect[9-2]
        /// Nếu đi từ trái sang phải thì index = gap - 1
        if (vect[9 - 3] == 1 && vect[9 - 2] == 1) {
            vect.push_back(1);
        }
        else if (vect[9 - 4] == 1 && vect[9 - 3] == 1) {
            vect.push_back(1);
        }
        else {
            vect.push_back(0);
        }

        if (player.getY() == index) {
            int x = player.getX() - 1;
            grid[index][x] = 0;
            if (grid[index][x + 1] == 0)
                grid[index][x + 1] = 2;
            else {
                gameState = ENDED;
                break;
            }
        }
    }
    cout << "Player got hit";
}

void Level::UpdateGrid() {
    while (gameState == PROCESSING)
    {
        fflush(stdin);
        sleep_for(milliseconds(900));
        DrawGrid();
    }
}

void Level::GenerateVehicle(int index) {
    VehicleLine(ref(grid[index]),index);
}


void Level::ClearPlayerOnGrid() {
    int x = player.getX();
    int y = player.getY();

    grid[y][x] = 0;
}

void Level::UpdatePlayerOnGrid() {
    int x = player.getX();
    int y = player.getY();

    grid[y][x]= 2;
}

void Level::HandlePlayerMovementOnGrid() {
    int c;
    int x = player.getX();
    int y = player.getY();
    while (gameState == PROCESSING) {
        c = 0;
        switch (c = _getch())
        {
            case 72:
                ClearPlayerOnGrid();
                y--;
                break;
            case 80:
                ClearPlayerOnGrid();
                y++;
                break;
            case 75:
                ClearPlayerOnGrid();
                x--;
                break;
            case 77:
                ClearPlayerOnGrid();
                x++;
                break;
        }
        player.setPoint(x, y);
        UpdatePlayerOnGrid();
    }
}

void Level::GenerateGrid() {
    thread line1(&Level::GenerateVehicle, this, 2);
    thread line2(&Level::GenerateVehicle, this, 4);
    thread line3(&Level::UpdateGrid, this);
    thread playerControl(&Level::HandlePlayerMovementOnGrid, this);

    line1.join();
    line2.join();
    line3.join();
    playerControl.join();
}

void Level::SavePlayer() {

}


//Spaw random obstacle line from start to end with the limit
//return array of int which will become line of obstacle
int* Level::DynamicSpawn(int start, int end,int limit = 4) {
    
}


bool Level::LevelIsComplete() {
    return isComplete;
}

bool Level::PlayerCompleteLevel() {
    return player.CompleteLevel();
}