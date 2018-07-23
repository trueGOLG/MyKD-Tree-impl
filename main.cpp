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
vector<vector<pair<int,int>>> serviceData;
vector<int> medians;
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

int splitDimmension(int plane, int depth);

void kdTreeBuilder(vector<vector<int>> data, int depth);

void addNode(vector<int> newNode);

// void preSort(vector<vector<int>> data);
void preSort();
void preSort2();
void Print2();
void getMedians();
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
    std::uniform_int_distribution<> dis(10, 99);

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

    //preSort();
    //PrintVector();
    preSort2();
    Print2();
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

// Delete this coments
// vector<vector<pair<int,int>>> serviceData;

void preSort2() {
    for (int i = 0; i < initialData.size(); ++i) {
        vector<pair<int,int>> tmp;
        for (int j = 0; j < Dimensions; ++j) {
            tmp.emplace_back(make_pair(i, initialData.at(i).at(j))); // first origin Index , second - value
        }
        serviceData.emplace_back(tmp);
    }
}

// Delete this coments
// vector<pair<int,int>> column;
// vector<vector<pair<int,int>>> serviceData;

/*
 vector<
    [0] vector<[0]pair<int,int>, [1] pair<int,int>, [2] pair<int,int> ...  [j] pair<int,int> >,

    [1] vector<[0]pair<int,int>, [1] pair<int,int>, [2] pair<int,int> ...  [j] pair<int,int> >,

    [2] vector<[0]pair<int,int>, [1] pair<int,int>, [2] pair<int,int> ...  [j] pair<int,int> >,
    .
    .
    .
    [i] vector<[0]pair<int,int>, [1] pair<int,int>, [2] pair<int,int> ...  [j] pair<int,int> >

    >

 */
void getMedians() {
    for (int i = 0; i < serviceData.size(); ++i) {
        for (int j = 0; j < serviceData[0].size(); ++j) {
            std::sort(serviceData[i].begin(), serviceData[i].end(), sortbysec);
        }
        // TODO: Put statement as argument of medians.push_back()
        int med = serviceData.at(serviceData.size()/2)[i].second;
        medians.push_back(med);
    }
}

int splitDimmension(int plane, int depth) {

    for (int space = 0; space < depth; ++space) {

    }

    for (int j = 0; j < initialData.size(); ++j) {
        column.emplace_back(make_pair(j,initialData[j][0]));
    }
    //  remove sortbysec to sort by first element
    std::sort(column.begin(), column.end(), sortbysec);

    median = column.at(column.size()/2).second;

    return 0; // Index of median
}

void Print2() {
    for (int i = 0; i < serviceData.size(); ++i) {
        cout<< "i: "<< i;
        for (int j = 0; j < serviceData[j].size(); ++j) {
            cout << " V: " << serviceData[i][j].second;
        }
        cout  << endl;
    }

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
    //int median = splitDimmension(plane);



}



