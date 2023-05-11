#include <iostream>
#include <fstream>
using namespace std;

char g_map[100][100];

void printMap(int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << g_map[i][j];
		}
		cout << endl;
	}
}

void floodFill(int x, int y, char prev_color, char new_color, int w, int h) {
	if(x<0 || x>w-1) return;
	if(y<0 || y>h-1) return;

	char current_color = g_map[y][x];
	if(current_color != prev_color) return;

	printMap(w, h);

	g_map[y][x] = new_color;
	floodFill(x+1, y, prev_color, new_color, w, h);
	floodFill(x-1, y, prev_color, new_color, w, h);
	floodFill(x, y+1, prev_color, new_color, w, h);
	floodFill(x, y-1, prev_color, new_color, w, h);

}

class Pos {
public:
	int x;
	int y;
	Pos(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

#include <list>

void floodFill2(int _x, int _y, char prev_color, char new_color, int w, int h) {
	//list에 클래스를 넣을때는 복사해서 넣으므로 복사 생성자를 부른다.
	//이 코드에서는 동적할당이 없기 때문에 복사생성자를 따로 손 볼 필요 없다.
	list<Pos> pts;
	pts.push_back(Pos(_x,_y));

	while (!pts.empty()) {
		//list.push_back() : list 맨 뒤에 삽입
		//list.push_front() : list 맨 앞에 삽입
		//list.pop_back() : list 맨 뒤의 요소 삭제
		//list.pop_front() : list 맨 앞의 요소 삭제
		//list.back() : list 맨 뒤의 value 리턴
		//list.front() : list 맨 앞의 value 리턴
		//list.begin() : 맨 앞의 요소 iterator
		//list.end() : 맨 뒤의 요소 iterator
		Pos p = pts.back();
		pts.pop_back();

		if(p.x<0 || p.x>w-1) continue;
		if(p.y<0 || p.y>h-1) continue;
		char current_color = g_map[p.y][p.x];
		if(current_color != prev_color) continue;

		g_map[p.y][p.x] = new_color;

		cout<<"list size : "<<pts.size()<<endl;
		printMap(w, h);
		pts.push_back(Pos(p.x+1, p.y));
		pts.push_back(Pos(p.x-1, p.y));
		pts.push_back(Pos(p.x, p.y+1));
		pts.push_back(Pos(p.x, p.y-1));
	}
}

int main() {
	ifstream fin;
	fin.open("Map.txt");


	int W, H;
	fin >> W >> H;
	cout << W << ", " << H << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			fin>>g_map[i][j];
		}
	}
	
	/*floodFill(10, 7, g_map[10][7], 'o', W, H);*/
	floodFill2(10, 7, g_map[10][7], 'o', W, H);
	


	printMap(W, H);

	fin.close();


}