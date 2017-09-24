//679 - Dropping Balls
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=620

#include < iostream > 
using namespace std; 
int main() {
	int cases; 
	while (cin >> cases) {
		while (cases) {
			int depth, I; 
			cin >> depth; 
			if (depth != -1) {
				int tot = 1 << depth; 
				cin >> I; 
				long long k = 1; 
				bool GoOn = true; 
				for (int i = 0; i < depth-1; i++) {
					if (I % 2) {
						I = (I + 1)/2; 
						k = k * 2; 
					}
					else {
						I /= 2; 
						k = k * 2 + 1; 
					}
				}
				cout << k << endl; 
			}
			else break; 
		}
	}
}