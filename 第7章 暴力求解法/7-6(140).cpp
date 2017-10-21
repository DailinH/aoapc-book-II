#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
//#include <sstream>
//#include <vector>
using namespace std;
int graph[10][10];
char result[100];
int n;//涉及字母个数
string cmds;
void read_cmds(string cmds, int &n) {
	int sum[8] = { 0 };
	int cur_origin = cmds[0];
	for (int i = 0; i < cmds.length(); i++) {
		if (cmds[i] == ';')
			continue;
		else if (cmds[i] == ':')
			cur_origin = cmds[i-1];
		else {
			sum[cmds[i] - 'A'] = 1;
			if (cur_origin != cmds[i]) {
				graph[cur_origin-'A'][cmds[i]] = 1;
				graph[cmds[i]][cur_origin-'A'] = 1;

			}
		}
			
	}
	for (int i = 0; i < 8; i++)
		n += sum[i];
}
int main() {
	while (cin >> cmds && cmds != "#") {
		memset(graph, 0, sizeof(graph));
		for (int i = 0; i < 8; i++)
			result[i] = 'A' + i;
		int n = 0, tot_s = 80;
		read_cmds(cmds,n);
		while (next_permutation(result, result + n)){

			for (int i = 0; i < 8; i++) {
				cout << result[i] << " ";
			}
			cout << endl;
		}
	}
}
//void read_cmds(string cmds, int &n) { // read and input commands
//
//}
//void dfs(char* result, int cur) {
//	if (cur == n) {
//
//	}
//
//}
//int main() {
//	string cmds;
//	stringstream tmp;
//	while (cin >> cmds && cmds != "#") {
//		memset(graph, -1, sizeof(graph));
//		read_cmds(cmds,n);
//		dfs(result,0);
//
//	}
//}