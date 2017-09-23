//uva12657 - Boxes in a Line
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=4395

#include < iostream > 
#include < cstring > 
#define MAXN 100000 + 10
using namespace std; 

int Left[MAXN]; 
int Right[MAXN]; 

void Link(int & X, int & Y) {
	Right[X] = Y; 
	Left[Y] = X; 
}
int main() {
	int boxNum, cmdNum; 
	int cse = 0; 
	while (cin >> boxNum >> cmdNum) {
		cse++; 
		//memset(Left, 0, sizeof(Left));
		//memset(Right, 0, sizeof(Right));

		//int BoxSequences[MAXN] = { 0 };
		for (int i = 1; i <= boxNum; i++) {
			Left[i] = i - 1; 
			Right[i] = (i + 1) % (boxNum + 1); 
		}
		Left[0] = boxNum; 
		Right[0] = 1; 
		int cmds, X, Y; 
		bool inv = false; 
		while (cmdNum--) {
			cin >> cmds; 
			if (cmds == 4)inv =  ! inv; 
			else {
				cin >> X >> Y; 
				if (cmds == 3 && Right[Y] == X)swap(X, Y); 
				if (inv && cmds != 3)cmds = 3 - cmds; 
				if (cmds == 1 && Left[Y] == X)continue; 
				if (cmds == 2 && Right[Y] == X)continue; 
				int LX = Left[X], LY = Left[Y], RX = Right[X], RY = Right[Y]; 
				if (cmds == 1) {
					Link(LX, RX); 
					Link(LY, X); 
					Link(X, Y); 
				}
				else if (cmds == 2) {
					Link(LX, RX); 
					Link(X, RY); 
					Link(Y, X); 
				}
				else if (cmds == 3) {
					if (RX == Y) {
						Link(LX, Y); 
						Link(Y, X); 
						Link(X, RY); 
					}
					else {
						Link(LX, Y); 
						Link(Y, RX); 
						Link(LY, X); 
						Link(X, RY); 
					}
				}
			}
			int S = 0; 
			//for (int i = 1; i <= boxNum; i++) {
			//	S = Right[S];
			//	cout << S <<" ";
			//	}
			}
		//cout << endl;
		long long ans = 0; 
		/*if (inv) {
			int Start;
			for (int i = 1; i <= boxNum; i++) {
				if (!Right[i]) {
					Start = i;
					break;
				}
			}
			ans += Start;
			for (int i = 0; i < boxNum; i+=2) {
				Start = Left[Left[Start]];
				ans += Start;
			}
		}
		else {
			int Start;
			for (int i = 1; i <= boxNum; i++) {
				if (!Left[i]) {
					Start = i;
					break;
				}
			}
			ans += Start;
			for (int i = 0; i < boxNum; i += 2) {
				Start = Right[Right[Start]];
				ans += Start;
			}

		}*/
		int Start = 0; 
		for (int i = 1; i <= boxNum; i++) {
			Start = Right[Start]; 
			//cout << i << " : " << Start << endl;
			if (i % 2 == 1) {
				//cout << "ans += " << Start << endl;
				ans +  = Start; 
			}
		}
		if (inv && boxNum % 2 == 0) {
			//cout << "Do!";
			ans = (long long)boxNum * (boxNum + 1)/2 - ans; 
		}
		cout << "Case " << cse << ": " << ans << endl; 
	}
	return 0; 
}

