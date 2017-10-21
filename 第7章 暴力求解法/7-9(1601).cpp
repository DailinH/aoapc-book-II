#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct Grid {
	int x;
	int y;
	char val;
};
int width, height, num;
vector<Grid> G;

bool input_graph() {
	cin >> width >> height >> num;
	cin.ignore();
	if (!width)
		return false;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j <= height; j++) {
			char v;
			v = getchar();
			if (v == '\n')
				continue;
			if (v == '#')
				continue;
			else {
				Grid new_grid;
				new_grid.x = i;
				new_grid.y = j;
				new_grid.val = v;
				G.push_back(new_grid);
				//cout << "count!" << endl;
			}
		}
	}
	//cout << "input finished" << endl;
	return true;
}

int main() {
	while (input_graph()) {
		cout << "true" << endl;
		for (int i = 0; i < G.size(); i++) {
			cout << G[i].x << " " << G[i].y << " " << G[i].val << endl;
		}
	}
	
}