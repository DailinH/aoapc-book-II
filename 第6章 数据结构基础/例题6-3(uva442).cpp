// 442 Matrix Chain multiplication
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=383
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

class Matrix
{
public:
	Matrix(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
//private:
	int x;
	int y;
};
int main()
{
	Matrix m[26];
	int numOfCharacters;
	while (cin >> numOfCharacters) {
		//初始化矩阵
		for (int i = 0; i < numOfCharacters; i++) {
			char C;
			int a, b;
			cin >> C >> a >> b;
			int seq = C - 'A';
			m[seq].x = a;
			m[seq].y = b;
		}
		//进行计算
		string expressions;
		stack<Matrix> s;
		while (cin >> expressions) {
			int len = expressions.length();
			int n = 0;//num in stack?
			int ans = 0;
			bool success = true;
			//bool end = false;
			while (n<len) {
				//逐个进栈
				if (isalpha(expressions[n])) {
					s.push(m[expressions[n] - 'A']);
				}
				//若遇见右括号则栈内二位出栈
				else if (expressions[n] == ')') {
					Matrix m2 = s.top();
					s.pop();
					Matrix m1 = s.top();
					s.pop();
					if (m1.y != m2.x) {
						success = false;
						break;
					}
					ans += m1.x*m1.y*m2.y;
					Matrix result(m1.x, m2.y);
					s.push(result);
				}
				n++;
			}
				//Matrix m2 = s.top();
				//s.pop();
				//if (!s.empty()) {
				//	Matrix m1 = s.top();
				//	s.pop();
				//	if (m1.y != m2.x) {
				//		success = false;
				//		break;
				//	}
				//	else ans += m1.x * m1.y * m2.x;
				//}

			if (!success) {
				cout << "error\n";
				continue;
			}
			else cout << ans << endl;
			
		}
	}
	return 0;
}
