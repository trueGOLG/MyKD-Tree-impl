#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// initial data

unsigned short int Dimensions;

vector<vector<int>> initialData;

// tools

int splitDimmension(vector<int> dimensions);

void kdTreeBuilder(vector<vector<int>> data);

void addNode(vector<int> newNode);

void preSort(vector<vector<int>> data);

int main() {
    initialData.resize(Dimensions);
    cout << "Big Fantastic Start" << endl;

    return 0;
}

int splitDimmension(vector<int> plane) {




    return 0;
}

void preSort(vector<vector<int>> data) {
    for (int i = 0; i < data.size(); ++i) {
        std::sort(data[i].begin(),data[i].end());
    }

}