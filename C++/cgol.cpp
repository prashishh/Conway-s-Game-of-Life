//#include <boost/algorithm/string/join.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
#include <map>

using namespace std;

int global_fitness = 20000;
int iterations = 3;
int global_count = 0;
vector<string> global_game_space;
vector<bool> init_game_space;
vector<bool> game_space;
vector<string> hash_game_space;
vector<bool> temp_game_space;
vector <int, int> final_game_space;

int IsLiveOrDead() {
    return bool(rand() % 2);
}

void createGameBoard() {
    srand( (unsigned)time(NULL));
    game_space.clear();
    for(int i = 0; i < 100; i++) {
        game_space.push_back(IsLiveOrDead());
    }
    init_game_space = game_space;
    string temp = "";
    
    for(vector<bool>::iterator i = game_space.begin(); i != game_space.end(); ++i) {
        //cout << to_string(*i);
        temp += to_string(*i); // this will print all the contents of *features*
    }
    hash_game_space.push_back(temp);

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

void mutation(string gene) {
    int position = rand() % 100;
    if(gene[position] == '1')
        gene[position] = '0';
    else
        gene[position] = '1';
}

void crossover(string gene1, string gene2) {
    int position = rand() % 100;
    string temp1 = "";
    string temp2 = "";
    
    for(int i = 0; i < 100; i++){
        if(i < position){
            temp1 += gene1[i];
            temp2 += gene2[i];
        } else {
            temp1 += gene2[i];
            temp2 += gene1[i];
        }
    }
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

string convertToString(vector<bool> space) {
    string temp = "";
    
    for(vector<bool>::iterator i = space.begin(); i != space.end(); ++i) {
        //cout << to_string(*i);
        temp += to_string(*i); // this will print all the contents of *features*
    }
    
    return temp;
}

string startGameOfLife() {
    temp_game_space.clear();
    for(int i = 1; i <= 100; i++) {
        if(conwayGameRules(i) == true)
            temp_game_space.push_back(1);
        else
            temp_game_space.push_back(0);
    }
    
    game_space = temp_game_space;
    
    return convertToString(temp_game_space);

}

void checkGlobalFitness(int fitness) {
    if(fitness < global_fitness) {
        global_fitness = fitness;
        cout << "\nNew Fitness = " << global_fitness;
    }
        
}

void startGame() {
    int count = 1;
    string temp_numb;
    hash_game_space.clear();
    srand( (unsigned)time(NULL));

    //temp_numb = startGameOfLife();
    //cout << temp_numb;
    while(1) {
        temp_numb = startGameOfLife();
        //cout << temp_numb;
        if( find(hash_game_space.begin(), hash_game_space.end(), temp_numb) == hash_game_space.end() || count == 1) {
            hash_game_space.push_back(temp_numb);
            count++;
            //cout << count << endl;
        
        /*
        for(vector<string>::iterator i = hash_game_space.begin(); i != hash_game_space.end(); ++i) {
            cout << *i << "\n";
           // temp += to_string(*i);
        }
        */
            
        } else {
            cout << "\nGame Ended at " << count;
            checkGlobalFitness(count);
           // global_game_space.push_back(convertToString(init_game_space));
            final_game_space[convertToString(init_game_space)] = count;
           // printGameBoard(game_space);
            break;
        }
        
        if (count == 20000) {
            cout << "\nGame Timeout: Generation > 20000";
            break;
        }
    }
}

void startGA() {
    int count = 0;
    while(count < iterations) {
        cout << "\n\nBeginning new game..";
        createGameBoard();
        //printGameBoard(game_space);
        startGame();
        count++;
    }
}

/*
for(vector<string>::iterator i = global_game_space.begin(); i != global_game_space.end(); ++i) {
    cout << *i << "\n";
    // temp += to_string(*i); // this will print all the contents of *features*
 }
*/
int main() {
    startGA();
    
    cout << global_fitness << "\n";
   // cout << global_game_space.size() << "\n";
    cout << final_game_space.size();
    return 0;
}




