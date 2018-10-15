#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <array>
#include <optional>
#include <cctype>
using namespace std;


// С++ 17

/*
* TODO list
* A) KD-tree building
*  1) Implement median search mechanism Done
*  2) Apropriate Tree bulding process
*
* B) Range search
*
*/
// initial data

unsigned short int Dimensions;

// Basic structure

vector<vector<int>> initialData(11, vector<int>(Dimensions));

vector<pair<int, vector<int>>> serviceDataV2;

// service data strcuture
//vector<vector<int>> column(10, vector<int>(2));

vector<pair<int, int>> column;
vector<vector<pair<int, int>>> serviceData(11, vector<pair<int, int>>(Dimensions)); // pair: original index / value
vector<int> medians(Dimensions);
// Minimal depth sould correspond to number of dimenstions
int depth = Dimensions;
int heightOfTree(int n);

struct Node {
	pair<int, int> data;
	Node *left;
	Node *right;
};

vector<Node> kdTree;

// Tools

// sorting driver
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b);

// TODO: Provide alternate splitting methods by setting different option argument in mode

int splitDimmension(int plane, int depth);

std::optional<Node> kdTreeBuilder(int depth, int plane, int a, int b);

void addNode(vector<int> newNode);

// void preSort(vector<vector<int>> data);
void preSort();
void ConvertToServiceDS();
void Print2();
void Print3();
pair<int, int> getMedians(int boundA, int boundB, int plane);

// Last modifications
void ConvertToServiceDSv2();
void printData();
pair<int, vector<int>> Split(int startPoint, int endPoint, int dimension);

// Utils
void PrintVector();
int dim = 0;

int main() {
	// TODO: Clean up code
	Dimensions = 4;
	vector<int> test(8);
	//-------- Generate test data structure
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(10, 99);
	//--------
	cout << "Big Fantastic Start" << endl;
	// Generate test data
	for (int i = 0; i < initialData.size(); ++i) {
		vector<int> tmp(Dimensions);
		for (int j = 0; j < tmp.size(); ++j) {
			tmp.at(j) = dis(gen);
		}
		initialData.at(i) = tmp;
	}
	cout << "original data: " << endl;
	PrintVector();
	cout << "new data " << endl;
	//preSort();
	//PrintVector();
	ConvertToServiceDSv2();
	pair<int, vector<int>> med = Split(0, serviceDataV2.size(), 0);
	/*
	ConvertToServiceDS();
	Print2();
	int a = 0;
	int b = serviceData.size();	
	kdTreeBuilder(Dimensions, 0, a, b);
	*/
	cout << "Press Enter to continue..." << endl;
	getchar();
	return 0;
}

// vector<pair<int,int>> column;
// test method
void preSort() {

	for (int i = 0; i < initialData.size(); ++i) {
		vector<pair<int, int>> tmp;
		for (int j = 0; j < initialData[0].size(); ++j) {
			tmp.emplace_back(make_pair(i, initialData[i][j]));
		}
		serviceData.emplace_back(tmp);
	}

	std::sort(serviceData.begin(), serviceData.end(),
		[](const vector<pair<int, int>> &a, const vector<pair<int, int>> &b) -> bool {
		return (a[0].second < b[0].second);
	});
	/*
	for (int j = 0; j < initialData.size(); ++j) {
	column.emplace_back(make_pair(j,initialData[j][0])); // plane instead of 0
	}
	//  remove sortbysec to sort by first element
	std::sort(column.begin(), column.end(), sortbysec);
	median = column.at(column.size()/2).second;
	*/
}

void ConvertToServiceDS() {
	// TODO: there are should be way to convert in more elegant and efficient manner

	for (int i = 0; i < initialData[0].size(); ++i) {
		vector<pair<int, int>> col;
		for (int j = 0; j < initialData.size(); ++j) {
			col.emplace_back(make_pair(j, initialData[j][i]));
		}
		std::sort(col.begin(), col.end(),
			[](const pair<int, int> &a, const pair<int, int> &b) -> bool {
			return (a.second < b.second);
		});

		for (int line = 0; line < col.size(); ++line) {
			serviceData[line].emplace_back(col[line]);
		}
	}
}

// vector<pair<int, vector<int>>> serviceDataV2;
void ConvertToServiceDSv2() {
	for (int i = 0; i < initialData.size(); i++)
	{
		serviceDataV2.emplace_back(make_pair(i, initialData[i]));
	}
}
void printData() {
	for (int j = 0; j < serviceDataV2.size(); j++)
	{
		cout << "index: " << serviceDataV2[j].first;
		for (int n = 0; n < serviceDataV2[0].second.size(); n++)
		{
			cout << " data: " << serviceDataV2[0].second[n];
		}
		cout << endl;
	}
}

pair<int, vector<int>> Split(int startPoint, int endPoint, int dimension) {
	/*
	vector<pair<int, vector<int>>> column;
	for (int i = startPoint; i < endPoint; i++)
	{
		column.emplace_back(make_pair(i, initialData[i][dimension]));
	}
	// Sort some range in particular dimension
	std::sort(column.begin(), column.end(),
		[](const pair<int, int> &a, const pair<int, int> &b) -> bool {
		return (a.second < b.second);
	});
	*/
	std::sort(serviceDataV2.begin(), serviceDataV2.end(),
		[&](const pair<int, vector<int>> &a, pair<int, vector<int>> &b) -> bool {
		return (a.second[dimension] < b.second[dimension]);
	});
	// Test
	for (int  j = 0; j < serviceDataV2.size(); j++)
	{
		cout << "index: " << serviceDataV2[j].first;
		for (int n = 0; n < serviceDataV2[0].second.size(); n++)
		{
			cout << " data: " << serviceDataV2[j].second[n];
		}
		cout << endl;
	}
	//
	return serviceDataV2[serviceDataV2.size() / 2];
}

// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
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

// Very basic technic for median
pair<int, int> getMedians(int boundA, int boundB, int plane) {
	// TODO: Keep in mind that there are can be other plain splitting strategies
	return serviceData.at((boundA + boundB) / 2)[plane];
}



std::optional<Node> kdTreeBuilder(int depth, int plane, int a, int b) {
	if (plane == Dimensions + 1) {
		plane = 0;
	}
	if (!(a > b) || !(depth == 0)) {

		return std::nullopt;
	}
	Node node;
	std::optional<Node> optNode;
	
	optNode->data.first = getMedians(a, b, plane).first;		
	optNode->data.second = getMedians(a, b, plane).second;

	std::optional<Node> lNode = kdTreeBuilder(depth - 1, plane + 1, a, node.data.second);

	std::optional<Node> rNode = kdTreeBuilder(depth - 1, plane + 1, node.data.second + 1, b);

	return node;
}


int heightOfTree(int n) {
	int h = 1;
	while (h < n) {
		h *= 2;
	}
	return h;
}

int splitDimmension(int plane, int depth) {

	for (int space = 0; space < depth; ++space) {

	}
	for (int j = 0; j < initialData.size(); ++j) {
		column.emplace_back(make_pair(j, initialData[j][0]));
	}
	//  remove sortbysec to sort by first element
	std::sort(column.begin(), column.end(), sortbysec);

	//median = column.at(column.size()/2).second;

	return 0; // Index of median
}

void Print2() {
	for (int i = 0; i < serviceData.size(); ++i) {
		for (int j = 0; j < serviceData[j].size(); ++j) {
			if (serviceData[i][j].first < 10) {
				cout << "  s: " << serviceData[i][j].first << " Val: " << serviceData[i][j].second << char(186);
			}
			else {
				cout << " s: " << serviceData[i][j].first << " Val: " << serviceData[i][j].second << char(186);
			}

		}
		cout << endl;
	}
}
// without index
void Print3() {
	for (int i = 0; i < serviceData.size(); ++i) {
		for (int j = 0; j < serviceData[j].size(); ++j) {
			cout << serviceData[i][j].second << " ";
		}
		cout << endl;
	}
}


void PrintVector() {
	for (int i = 0; i < initialData.size(); ++i) {
		for (int j = 0; j < initialData[j].size(); ++j) {
			cout << initialData[i][j] << " ";
		}
		cout << " <- Index " << i << endl;
	}
	/*
	cout << "--------------" << endl;
	cout << "0 Dimension" << endl;
	cout << "--------------" << endl;


	for (int k = 0; k < column.size(); ++k) {
	cout << column[k].second << " - " << column[k].first << endl;
	}

	cout << "--------------" << endl;
	cout << "median = " << median << endl;
	*/

}

void BuilderUtil(vector<vector<int>> data, int depth, int dimension) {


}




