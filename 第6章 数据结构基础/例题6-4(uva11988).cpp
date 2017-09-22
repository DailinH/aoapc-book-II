//uva11988 - Broken Keyboard
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=3139

#include <iostream>
#include <cstring>
#define maxn 100000+10
using namespace std;
int main() {
	char text[maxn];
	while (cin >> text+1) {
		int cur = 0;
		int last = 0;
		int next[maxn];
		next[0] = 0;
		int len = strlen(text+1);
		for (int i = 1; i <= len; i++) {
			if (text[i] == '[') {
				cur = 0;
			}
			else if (text[i] == ']') {
				cur = last;
			}
			else {
				next[i] = next[cur];
				next[cur] = i;
				if (cur == last) last = i;
				cur = i;
			}
		}
		for (int i = next[0]; i!=0 ; i = next[i]) {
			cout << text[i];
			//cout << "-";
		}
		cout << endl;
	}

}

//

//
//int main() {
//	string text;
//	while (cin >> text) {
//		int curPos = 0;
//		int txtLen = text.length();
//		int sequences[2][maxn];
//		int seqNum = 0;//填充的数量
//		//对txt中每一个字符进行处理
//				for (int i = 0; i < txtLen; i++) {
//			if (text[i] == ']'  || (i== txtLen -1 && text[i+1] == '[')){//|| i == txtLen - 1) {
//				//if (i == txtLen - 1 && text[i] != ']') {
//				//	sequences[0][seqNum] = seqNum;
//				//	sequences[1][seqNum] = i;
//				//	seqNum++;
//				//	curPos++;
//
//				
//				if (curPos != seqNum) {
//					for (int j = 0; j < (seqNum - curPos); i++) {
//						sequences[0][j] += curPos;
//					}
//					curPos = seqNum;
//				}
//			}
//			else if (text[i] == '[') {
//				curPos = 0;
//			}
//			else {
//				sequences[0][seqNum] = curPos;
//				sequences[1][seqNum] = i;
//				seqNum++;
//				curPos++;
//			}
//		}
//		//对sequences进行排序
//		//sort(sequences[0], sequences[0] + seqNum);
//		for (int i = 0; i < seqNum; i++) {
//			for (int j = i; j < seqNum; j++) {
//				if (sequences[0][i] > sequences[0][j]) {
//					swap(sequences[0][i], sequences[0][j]);
//					swap(sequences[1][i], sequences[1][j]);
//				}
//			}
//		}
//		//for (int i = 0; i < txtLen; i++) {
//		//	if (text[i] == '[') {
//		//		curPos = 0;
//		//		sequences[seqNum][0] = 0;
//		//		sequences[seqNum][1] = i;
//		//		sequences[seqNum][2] = 2;
//		//		//seqNum++;
//
//		//	}
//		//	else if (text[i] == ']') {
//		//		curPos = seqNum;
//		//		sequences[seqNum][0] = seqNum;
//		//		sequences[seqNum][1] = i;
//		//		sequences[seqNum][2] = seqNum+1;
//		//		//seqNum++;
//		//	}
//		//	else {
//		//		//seqNum++;
//		//		curPos++;
//		//	}
//		//	seqNum++;
//		//	if (curPos < seqNum) {
//		//		for (int j = 0; j < seqNum-1; j++) {
//		//			if(sequences[j][0]>curPos)
//		//			sequences[j][0]++;
//		//			sequences[j][2]++;
//		//		}
//		//	}
//
//		//}
//		//输出sequences正常序列
//		for (int i = 0; i < seqNum; i++) {
//			cout << text[sequences[1][i]];
//		}
//		cout << endl;
//		
//	}
//}

