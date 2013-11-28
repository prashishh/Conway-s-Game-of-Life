#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<bool> game_space;
vector<bool> hash_game_space;
vector<bool> temp_game_space;

int IsLiveOrDead() {
    return bool(rand() % 2);
}

void createGameBoard() {
    for(int i = 0; i < 100; i++) {
        game_space.push_back(IsLiveOrDead());
    }
}

void printGameBoard(vector<bool> temp_space) {
    for(int i = 0; i < 100; i++) {
        if(i % 10 == 0)
            cout << "\n";
        cout  << temp_space[i] << " ";
    }
    cout << "\n";
}

int checkSurround(int cell, int bool_surround[]) {
    int count = 0;
    
    //cout << cell << ' ' << bool_surround << ' ' << game_space[cell-11] << endl;
    //cout << cell;
    
    //count
    if(bool_surround[0] == 1 && (cell-1-11) >= 0) {
        //cout << cell-1-11 << ' ';
       if (game_space[cell-1-11] == 1)
        count++;
    }
    
    if(bool_surround[1] == 1 && (cell-1-10) >= 0) {
        //cout << cell-1-10 << ' ';
        if (game_space[cell-1-10] == 1)
            count++;
    }
    
    if(bool_surround[2] == 1 && (cell-1-9) >= 0) {
        //cout << cell-1-9 << ' ';
        if (game_space[cell-1-9] == 1)
            count++;
    }
    
    if(bool_surround[3] == 1 && (cell-1+1) <= 100) {
        //cout << cell-1+1 << ' ';
        if (game_space[cell-1+1] == 1)
            count++;
    }
    
    if(bool_surround[4] == 1 && (cell-1+11) <= 100) {
        //cout << cell-1+11 << ' ';
        if (game_space[cell-1+11] == 1)
            count++;
    }
    
    if(bool_surround[5] == 1 && (cell-1+10) <= 100) {
        //cout << cell-1+10 << ' ';
        if (game_space[cell-1+10] == 1)
            count++;
    }
    
    if(bool_surround[6] == 1 && (cell-1+9) <= 100) {
        //cout << cell-1+9 << ' ';
        if (game_space[cell-1+9] == 1)
            count++;
    }
    
    if(bool_surround[7] == 1 && (cell-1-1) >= 0) {
        //cout << cell-1-1 << ' ';
        if (game_space[cell-1-1] == 1)
            count++;
    }
    
   // cout << count << ' ' << endl;
    
    return count;
}

bool checkconwayGameRules(int cell, bool T, bool R, bool B, bool L) {
    int surround[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    
    if(T) {
        surround[0] = 0;
        surround[1] = 0;
        surround[2] = 0;
    }
    
    if(R) {
        surround[2] = 0;
        surround[3] = 0;
        surround[4] = 0;
    }
    
    if(B) {
        surround[4] = 0;
        surround[5] = 0;
        surround[6] = 0;
    }
    
    if(L) {
        surround[0] = 0;
        surround[6] = 0;
        surround[7] = 0;
    }
    
    
    int count = checkSurround(cell, surround);
    bool rslt;
    
    if(count == 2)
        rslt = 1;
    else if(count > 2)
        rslt = 0;
    else if(count < 2)
        rslt = 0;
    
    return rslt;
    //cout << endl;
}

bool conwayGameRules(int cell) {
    bool R = false;
    bool L = false;
    bool T = false;
    bool B = false;
    
    if(cell <= 10)
        T = true;
    if(cell > 89)
        B = true;
    if(cell % 10 == 0)
        R = true;
    if((cell - 1) % 10 == 0)
        L = true;
    
    return checkconwayGameRules(cell, T, R, B, L);
}


void startGameOfLife() {
    for(int i = 1; i <= 100; i++) {
        if(conwayGameRules(i) == true)
            temp_game_space.push_back(1);
        else
            temp_game_space.push_back(0);
    }

    printGameBoard(temp_game_space);
}

int main() {
    createGameBoard();
    printGameBoard(game_space);
    startGameOfLife();
    return 0;
}