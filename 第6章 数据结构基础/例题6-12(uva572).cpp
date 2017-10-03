#include <iostream>
#include <cstring>
using namespace std;
const int maxn_m = 110;
const int maxn_n = 110;
char instructions[maxn_m][maxn_n];
int numbered[maxn_m][maxn_n];
int m, n;

void dfs(int a, int b, int count) {
	if (a < 0 || b < 0 || a >= m || b >= n) return;
	if (numbered[a][b] > 0 || instructions[a][b] == '*') return;
	numbered[a][b] = count;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			dfs(a + i, b + j, count);
		}
	}
}
int main() {
	while (cin >> m >> n && m!=0) {
		//输入部分
		memset(numbered, 0, sizeof(numbered));
		memset(instructions, 0, sizeof(instructions));
		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++) 
				cin >> instructions[i][j];
		//判断部分
		int cnt = 0;
		for(int i = 0; i<m ; i++){
			for (int j = 0; j < n; j++) {
				if(numbered[i][j] == 0 && instructions[i][j] == '@') dfs(i, j, ++cnt);
			}
		}
		//输出
		cout << cnt << endl;
	}
}