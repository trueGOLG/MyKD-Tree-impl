#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <time.h>

using namespace std;


// initial data

unsigned short int Dimensions;

vector<vector<int>> initialData(10, vector<int>(Dimensions));

// tools

// TODO: Provide alternate splitting methods by setting different option argument in mode
int splitDimmension(int mode = 1, vector<int> dimensions = vector<int>());

void kdTreeBuilder(vector<vector<int>> data);

void addNode(vector<int> newNode);

//void preSort(vector<vector<int>> data);
void preSort();

// Utils

void PrintVector();

int main() {
    Dimensions = 4;
    vector<int> test(8);
    //--------
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 200);
    //--------
    cout << "Big Fantastic Start" << endl;

    for (int i = 0; i < initialData.size(); ++i) {
        vector<int> tmp(Dimensions);
        for (int j = 0; j < tmp.size(); ++j) {
            tmp.at(j) = dis(gen);
            //tmp.at(j) = rand_r(time(NULL));
        }
        initialData.at(i) = tmp;

    }



    preSort();
    PrintVector();
    return 0;
}

int splitDimmension(int mode, vector<int> plane) {




    return 0;
}
/*
void preSort(vector<vector<int>> data) {
    for (int i = 0; i < data.size(); ++i) {
        std::sort(data[i].begin(),data[i].end());
    }

}
*/

void preSort() {
    for (int i = 0; i < initialData.size(); ++i) {
        std::sort(initialData[i].begin(),initialData[i].end());
    }
}


void PrintVector() {
    for (int i = 0; i < initialData.size(); ++i) {
        for (int j = 0; j < initialData[j].size(); ++j) {
            cout << initialData[i][j] << " ";
        }
        cout << endl;
    }
}