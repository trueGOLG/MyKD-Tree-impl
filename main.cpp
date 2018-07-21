#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <array>
using namespace std;

/*
 * TODO list
 * A) KD-tree building
 *  1) Implement median search mechanism Done
 *  2)
 *
 * B) Range search
 *
 */
// initial data

unsigned short int Dimensions;

// Basic structure

vector<vector<int>> initialData(11, vector<int>(Dimensions));

// service data strcuture
//vector<vector<int>> column(10, vector<int>(2));
vector<pair<int,int>> column;
// Minimal depth sould correspond to number of dimenstions
int depth = Dimensions;

struct Node {
    int index;
    int originalIndex;
    Node *parent;
    Node *left;
    Node *righ;
};

vector<Node> Tree;


// Tools

// sorting driver
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b);

// TODO: Provide alternate splitting methods by setting different option argument in mode

int splitDimmension(int plane);

void kdTreeBuilder(vector<vector<int>> data, int depth);

void addNode(vector<int> newNode);

// void preSort(vector<vector<int>> data);
void preSort();

// Utils

void PrintVector();




int dim = 0;

int median = 0;


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


/*
void preSort(vector<vector<int>> data) {
    for (int i = 0; i < data.size(); ++i) {
        std::sort(data[i].begin(),data[i].end());
    }
}
*/

// Driver function to sort the vector elements
// by second element of pairs


void preSort() {
    for (int i = 0; i < initialData.size(); ++i) {
        std::sort(initialData[i].begin(), initialData[i].end());
    }

    for (int j = 0; j < initialData.size(); ++j) {
        //column.push_back(make_pair(j,initialData[j][0])); // plane instead of 0
        column.emplace_back(make_pair(j,initialData[j][0]));
    }
    //  remove sortbysec to sort by first element
    std::sort(column.begin(), column.end(), sortbysec);

    median = column.at(column.size()/2).second;

}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

void PrintVector() {
    for (int i = 0; i < initialData.size(); ++i) {
        for (int j = 0; j < initialData[j].size(); ++j) {
            cout << initialData[i][j] << " ";
        }
        cout << " <- Index " << i << endl;
    }
    cout << "--------------" << endl;
    cout << "0 Dimension" << endl;
    cout << "--------------" << endl;


    for (int k = 0; k < column.size(); ++k) {
        cout << column[k].second << " - " << column[k].first << endl;
    }

    cout << "--------------" << endl;
    cout << "median = " << median << endl;

}

void BuilderUtil(vector<vector<int>> data, int depth, int dimension) {



}

void kdTreeBuilder(vector<vector<int>> data, int depth) {
    int dep = 0;
    int plane = 0;
    int median = splitDimmension(plane);



}



int splitDimmension(int plane) {





    return 0; // Index of median
}