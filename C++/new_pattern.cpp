#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <time.h>
#include <map>

using namespace std;

int global_fitness = 20000;
vector<string> global_game_space;
vector<int> init_game_space;
vector<int> game_space;
vector<string> hash_game_space;
vector<int> temp_game_space;
vector< vector<int> > ga_game_space;
map <int, string> final_game_space;
int rule1 = 0;
int rule2 = 0;
int rule3 = 0;
// decide if cell is live or dead
int IsLiveOrDead() {
    return bool(rand() % 2);
}

// decide if to mutate or cross over
int mutateOrCross() {
    return bool(rand() % 2);
}

// creates the initial gameboard for each game
// gets called only once per game
void createGameBoard() {
    cout << "\nBoard Created..";
    game_space.clear();     // clear the global game space
    for(int i = 0; i < 100; i++) {
        game_space.push_back(IsLiveOrDead());
    }
    
    init_game_space = game_space;   // store initial game board as game_space changes in each generration
    
    // store the game board in 0s and 1s in hash_game_space
    // to check if game exists or not
    string temp = "";
    for(vector<int>::iterator i = game_space.begin(); i != game_space.end(); ++i) {
        temp += to_string(*i);
    }
    hash_game_space.push_back(temp);

}

// print the game board in 10X10
void printGameBoard(vector<int> temp_space) {
    for(int i = 0; i < 100; i++) {
        if(i % 10 == 0)
            cout << "\n";
        cout  << temp_space[i] << " ";
    }
    cout << "\n";
}

// finds the surrounding living cell and counts them
int checkSurround(int cell, int bool_surround[]) {
    int count = 0;
    
    if(bool_surround[0] == 1 && (cell-11) >= 0) {
        //cout << cell-1-11 << ' ';
       if (game_space[cell-11] == 1)
        count++;
    }
    
    if(bool_surround[1] == 1 && (cell-10) >= 0) {
        //cout << cell-1-10 << ' ';
        if (game_space[cell-10] == 1)
            count++;
    }
    
    if(bool_surround[2] == 1 && (cell-9) >= 0) {
        //cout << cell-1-9 << ' ';
        if (game_space[cell-9] == 1)
            count++;
    }
    
    if(bool_surround[3] == 1 && (cell+1) <= 100) {
        //cout << cell-1+1 << ' ';
        if (game_space[cell+1] == 1)
            count++;
    }
    
    if(bool_surround[4] == 1 && (cell+11) <= 100) {
        //cout << cell-1+11 << ' ';
        if (game_space[cell+11] == 1)
            count++;
    }
    
    if(bool_surround[5] == 1 && (cell+10) <= 100) {
        //cout << cell-1+10 << ' ';
        if (game_space[cell+10] == 1)
            count++;
    }
    
    if(bool_surround[6] == 1 && (cell+9) <= 100) {
        //cout << cell-1+9 << ' ';
        if (game_space[cell+9] == 1)
            count++;
    }
    
    if(bool_surround[7] == 1 && (cell-1) >= 0) {
        //cout << cell-1-1 << ' ';
        if (game_space[cell-1] == 1)
            count++;
    }
    
   // cout << count << ' ' << endl;
    return count;
}

// check the surrounding cells for game of life rules (4 rules)
bool checkconwayGameRules(int cell, bool T, bool R, bool B, bool L) {
    // initializes all the surrounding cell
    int surround[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    
    // makes the surrounding cells false according to location of the cell
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
    
    // counts living cells
    int count = checkSurround(cell-1, surround);
    bool rslt;
    
    // game of life rules
    if(count == rule1)
        rslt = 1;
    else if(count > rule2)
        rslt = 0;
    else if(count < rule3)
        rslt = 0;
    
    return rslt;
}

// checks location of cell and finds the surrounding cell if it is living or dead
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

// store the game board in 0s and 1s in hash_game_space
string convertToString(vector<int> space) {
    string temp = "";
    for(vector<int>::iterator i = space.begin(); i != space.end(); ++i) {
        temp += to_string(*i);
    }
    return temp;
}

// convert string of 0s and 1s to vector
vector<int> convertToVector(string space) {
    vector<int> temp;
    for (int i = 0; i < space.size(); i++) {
        temp.push_back(space[i] - '0');
    }
    return temp;
}

// finds the cells in each generation
// creates a game_space for each generation
string startGameOfLife() {
    temp_game_space.clear();    // clears the temp game space; initialized in each generation
    for(int i = 1; i <= 100; i++) {
        if(conwayGameRules(i) == true)
            temp_game_space.push_back(1);   // living cell
        else
            temp_game_space.push_back(0);   // dead cell
    }
    
    game_space = temp_game_space;   // changes the game_space of new generation
    return convertToString(temp_game_space);    // returns in the form on 0s and 1s

}

// checks the global fitness value of each game
void checkGlobalFitness(int fitness) {
    if(fitness < global_fitness) {
        global_fitness = fitness;
        cout << "New Fitness = " << global_fitness;
    }
        
}

// let the game begin
void startGame() {
    cout << "\nBeginning new game..";
    int count = 1;
    string temp_numb;
    hash_game_space.clear();    // clears after each game; hash_space stores 0s and 1s of each generation to find repeated states or loops
    srand( (unsigned)time(NULL));
    
    // loop until game_space is repeated i.e. same state in hash_space
    // find loop or end points
    while(1) {
        temp_numb = startGameOfLife();
        if( find(hash_game_space.begin(), hash_game_space.end(), temp_numb) == hash_game_space.end() || count == 1) {
            hash_game_space.push_back(temp_numb);   // pushes into hash_game_space if not found
            count++;
        } else {    // end game after same state is found
            cout << "\nGame Ended at " << count << endl;
            checkGlobalFitness(count);
            final_game_space.insert(make_pair(count, convertToString(init_game_space)));
            break;
        }
        
        // timeout to save time
        if (count == 15000) {
            cout << "\nTimeout: Generation > 15000" << endl;
            break;
        }
    }
}

// mutation rules
// pushes into global game space
void mutation(string gene) {
    int position = rand() % 100;
    if(gene[position] == '1')
        gene[position] = '0';
    else
        gene[position] = '1';
    
    cout << "\n\nGenes by Mutation\n";
    cout << gene << endl;
    ga_game_space.push_back(convertToVector(gene));
}

// cross over rules
// pushes into global game space
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
    cout << "\n\nGenes by Crossing Over\n";
    cout << temp1 << endl;
    cout << temp2 << endl;
    
    ga_game_space.push_back(convertToVector(temp1));
    ga_game_space.push_back(convertToVector(temp2));
    
}

// state GA
void startGA() {
    
    ga_game_space.clear();
    global_game_space.clear();
    // pick gamespace with best fitness values
    // half
    vector<string> temp_game;
    for (map<int, string>::iterator i = final_game_space.begin(); i != final_game_space.end(); i++)
        temp_game.push_back(i->second);
    
    cout << "\n\nNew genes " << endl;
    for(vector<string>::iterator j = temp_game.begin(); j != temp_game.begin()+floor(temp_game.size()/3); j++) {
        cout << "\n" << (*j);
        global_game_space.push_back(*j);
        ga_game_space.push_back(convertToVector(*j));
    }
    // mutate or cross
    // add to the new states to the main game_space
    vector<string> temp = global_game_space;
    global_game_space.clear();
    for(int k = 0; k < temp.size(); k++) {
        if(mutateOrCross() == 1)
            mutation(temp[int(rand() % temp.size())]);
        else
            crossover(temp[int(rand() % temp.size())], temp[int(rand() % temp.size())]);
    }
    
    cout << "\n\nNew space " << ga_game_space.size();
    
    game_space.clear();
    for(int z = 0; z < ga_game_space.size(); z++) {
       
        
        game_space = ga_game_space[z];
        /*
        printGameBoard(ga_game_space[z]);
        printGameBoard(game_space);
        */
        
        startGame();
        
        if(global_fitness < 1000) {
            cout << "Live if surrounding cell > " << rule1 << endl;
            cout << "Die if surrounding cell < " << rule2 << endl;
            cout << "Die if surrounding cell = " << rule3 << endl;
            
            cout << "Ended after " << global_fitness << " generation" << endl;
            cout << "Intial State: ";
            printGameBoard(init_game_space);
            cout << "Final State: ";
            printGameBoard(game_space);
            break;
        }
            
    }
    
}

int main() {
    // generate random rule
    srand( (unsigned)time(NULL));
    rule1 = rand() % 8;
    rule2 = rand() % 8;
    rule3 = rand() % 8;
    
    // loops until 10 unique game spaces are found
    while(final_game_space.size() < 10) {
        createGameBoard();
        startGame();
    }
    startGA();
    while(global_fitness > 1000)
        startGA();
    
    
    /*
    cout << "\n" << global_fitness << "\n";
    // cout << global_game_space.size() << "\n";
    cout << final_game_space.size() << endl;
    
    for (std::map<int, string>::iterator i = final_game_space.begin(); i != final_game_space.end(); i++)
    {
        cout << i->first << "\n";
    }
    
    cout << global_game_space.size() << endl;
    
    for (std::vector<string>::iterator m = global_game_space.begin(); m != global_game_space.end(); m++)
    {
        cout << *m << "\n";
    }
 

    cout << global_game_space.size() << endl;
    
    for (std::vector<string>::iterator m = global_game_space.begin(); m != global_game_space.end(); m++)
    {
        cout << *m << "\n";
    }
     */
    
    return 0;
}




