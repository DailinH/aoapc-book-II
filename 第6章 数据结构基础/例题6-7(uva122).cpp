#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
	Node(int val = -1) {//用-1表示未赋值的节点
		left = NULL;
		right = NULL;
		v = val;
	};
	Node* left;
	Node* right;
	int v;
};
Node *start;
void create_node(string nd) {
	int num = 0;
	bool isnum = false;
	Node *cur = start;
	for (int i = 0; i < nd.length(); i++) {
		if (nd[i] == '(') {
			isnum = true;
			continue;
		}
		if (nd[i] == ',') {
			isnum = false;
			continue;
		}
		if (isnum) {
			num *= 10;
			num += nd[i] - '0';
			continue;
		}
		if (nd[i] == ')') {
			cur->v = num;
			//cout << num;
			return;
		}
		if (nd[i] == 'L') {
			if (!cur->left)
				cur->left = new Node;
			cur = cur->left;
		}
		if (nd[i] == 'R') {
			if (!cur->right)
				cur->right = new Node;
			cur = cur->right;
		}
	}
}
queue<Node*> res;
void bfs(Node *s) {
	res.push(s);
	bool first = true;
	while (!res.empty()) {
		Node *tmp = res.front();
		if (first == true) {
			cout << tmp->v;
			first = false;
		}
		else 
			cout <<" "<< tmp->v;
		res.pop();
		if (tmp->left)
			res.push(tmp->left);
		if (tmp->right)
			res.push(tmp->right);
	}
}
bool valid_dfs(Node *s) {
	if (s->v == -1)
		return false;
	if (s->left)
		if (!valid_dfs(s->left))
			return false;
	if (s->right)
		if (!valid_dfs(s->right))
			return false;
	return true;
}

int main() {
	while (true) {
		string nd;
		start = new Node;
		while (cin >> nd  && nd != "()") {
			create_node(nd);//初始化树
		}
		if(valid_dfs(start))
			bfs(start);//打印树节点
		else cout << "not complete";
		cout << endl;
		delete start;
	}
}


////////////////////////////////正确解答//////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
	Node(int val = -1) {//用-1表示未赋值的节点
		left = NULL;
		right = NULL;
		v = val;
	};
	Node* left;
	Node* right;
	int v;
};
Node *start;
bool create_node(string nd) {
	int num = 0;
	bool isnum = false;
	Node *cur = start;
	for (int i = 0; i < nd.length(); i++) {
		if (nd[i] == '(') {
			isnum = true;
			continue;
		}
		if (nd[i] == ',') {
			isnum = false;
			continue;
		}
		if (isnum) {
			num *= 10;
			num += nd[i] - '0';
			continue;
		}
		if (nd[i] == ')') {
			if (cur->v != -1)
				return false;
			cur->v = num;
			//cout << num;
			return true;
		}
		if (nd[i] == 'L') {
			if (!cur->left)
				cur->left = new Node;
			cur = cur->left;
		}
		if (nd[i] == 'R') {
			if (!cur->right)
				cur->right = new Node;
			cur = cur->right;
		}
	}
}
//vector<int> ans;
bool validity = true;
void bfs(Node *s, vector<int> &ans) {
	queue<Node*> res;
	res.push(s);
	//bool first = true;
	while (!res.empty()) {
		Node *tmp = res.front();
		res.pop();
		if (tmp->v == -1) {
			validity = false;
			return;
		}
		ans.push_back(tmp->v);
		//if (first == true) {
		//	cout << tmp->v;
		//	first = false;
		//}
		//else 
		//	cout <<" "<< tmp->v;
		if (tmp->left)
			res.push(tmp->left);
		if (tmp->right)
			res.push(tmp->right);
	}
	return;
}
//bool valid_dfs(Node *s) {
//	if (s->v == -1)
//		return false;
//	if (s->left)
//		if (!valid_dfs(s->left))
//			return false;
//	if (s->right)
//		if (!valid_dfs(s->right))
//			return false;
//	return true;
//}

int main() {
	string nd;
	string firstnd;
	while (cin >> firstnd) {
		vector<int> ans;
		start = new Node;
		validity = true;
		create_node(firstnd);
		while (cin >> nd  && nd != "()") {
			if (!create_node(nd))//初始化树
			{
				validity = false;
				//break;
			}
		}
		if(validity) bfs(start,ans);//打印树节点
		if(!validity) cout << "not complete";
		else {
			cout << ans[0];
			for (int i = 1; i < ans.size(); i++) {
				cout << " " << ans[i];
			}
		}
		cout << endl;
		delete start;
	}
}