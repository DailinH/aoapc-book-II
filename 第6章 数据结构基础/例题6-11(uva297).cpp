#include < iostream > 
#include < string > 
#include < cstring > 
using namespace std; 
int buff[32][32]; 
//const int maxn = 1030;
string cmds; 
int cnt; 

void draw(string s, int & p, int row, int col, int width) {
	char ch = s[p++]; 
	if (ch == 'p') {
		draw(s, p, row, col + width / 2, width / 2); 
		draw(s, p, row, col, width / 2); 
		draw(s, p, row + width / 2, col, width / 2); 
		draw(s, p, row + width / 2, col + width / 2, width / 2); 
	}
	else if (ch == 'f') {
		for (int i = row; i < row + width; i++) {
			for (int j = col; j < col + width; j++) {
				if (buff[i][j] == 0) {
					buff[i][j] = 1; 
					cnt++; 
				}
			}
		}
		return; 
	}

}

int main() {
	int T; 
	cin >> T; 
	while (T--) {
		cnt = 0; 
		string commands1, commands2; 
		memset(buff, 0, sizeof(buff)); 
		cin >> commands1; 
		int p = 0; 
		draw(commands1, p, 0, 0, 32); 
		p = 0; 
		cin >> commands2; 
		draw(commands2, p, 0, 0, 32); 
		cout << "There are " << cnt << " black pixels.\n"; 

	}
}
