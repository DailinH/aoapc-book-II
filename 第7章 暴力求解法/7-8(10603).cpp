#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 210;
struct Node
{
	int v[3];
	int dist = 0;
	bool operator<(const Node &b) const { //这里的const有什么特殊意义吗？
		return dist > b.dist; //这个函数实际上是对priority_queue起作用，重载了默认的func
	}
};

int ans[maxn];
int full[3];
int vis[maxn][maxn];
priority_queue<Node> q;
void updateAns(Node cur) {
	for (int i = 0; i < 3; i++) {
		if(ans[cur.v[i]]<0 || cur.dist < ans[cur.v[i]])
			ans[cur.v[i]] = cur.dist;
	}
}

void solve(int a, int b, int c, int d) {
	while (!q.empty())
		q.pop();
	full[0] = a;
	full[1] = b;
	full[2] = c;
	memset(vis, 0, sizeof(vis));
	memset(ans, -1, sizeof(ans));
	//初始化第一个节点
	Node init;
	init.v[0] = 0;
	init.v[1] = 0;
	init.v[2] = c;
	init.dist = 0;
	q.push(init);
	//对优先队列由大到小进行处理
	while (!q.empty()) {
		Node cur = q.top();
		q.pop();
		updateAns(cur);
		if (ans[d] >= 0)
			break;
		//尝试从i向j倒水
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				//若倒水invalid
				if (i == j || cur.v[i] == 0 || cur.v[j] == full[j])
					continue;
				//若可以倒水
				//注意不能直接修改cur！下一层循环仍然需要用到cur
				Node cur2;
				memcpy(&cur2, &cur, sizeof(cur));
				int delta = min(full[j], cur.v[i] + cur.v[j]) - cur.v[j];
				cur2.v[i] -= delta;
				cur2.v[j] += delta;
				cur2.dist += delta;
				if (!vis[cur2.v[0]][cur2.v[1]]) {
					q.push(cur2);
					vis[cur2.v[0]][cur2.v[1]] = 1;
				}
				//memcpy(&cur, &cur2, sizeof(cur2));
			}
		}
	}

	//输出结果
	//cout << d << endl;
	int i = d;
	while (i > 0) {
		if (ans[i] > 0) {
			cout << ans[i] << " " << i <<  endl;
			return;
		}
		i--;
	}
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int a, b, c, d;
		while (cin >> a >> b >> c >> d) {
			solve(a, b, c, d);
		}
	}
	return 0;
}