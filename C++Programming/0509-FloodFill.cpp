#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("Map.txt");

	char map[100][100];

	int W, H;
	fin >> W >> H;
	cout << W << ", " << H << endl;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			fin >> map[i][j];
			cout << map[i][j];
		}
		cout << endl;
	}

	fin.close();
}