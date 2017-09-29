#include < iostream > 
#include < sstream > 
#include < string > 
#include < cstring > 
using namespace std; 

const int maxn = 10000 + 10; 
int inOrder[maxn]; 
int postOrder[maxn]; 
int lchild[maxn]; 
int rchild[maxn]; 
int n; 
bool readList(int * a) {
	string tmpString; 
	if ( ! getline(cin, tmpString))return false; 
	stringstream ss(tmpString); 
	int x; 
	for (n = 0; ss >> x; n++) {
		a[n] = x; 
	}
//	return true;
	return n > 0; 
}

int buildTree(int l1, int r1, int l2, int r2) {
	if (l1 > r1)return 0; 
	int position = l1; 
	int root = postOrder[r2]; 
	for (int i = l1; i <= r1; i++) {
		if (inOrder[i] == root) {
			position = i; 
			break; 
		}
	}
	//left
	lchild[root] = buildTree(l1, position - 1, l2, l2 + position - l1 - 1); 
	rchild[root] = buildTree(position + 1, r1, l2 + position - l1, r2 - 1); 
	//最终遍历数组可以得到累计最大值
	return root; 
}
int best, best_sum; 

void bfs(int curNum, int sum) {
	//函数作用：
	sum + = curNum; 
	if ( ! lchild[curNum] &&  ! rchild[curNum]) {
		if (sum < best_sum || (sum == best_sum && curNum < best)) {
			best_sum = sum; 
			best = curNum; 
		}
	}
	if (lchild[curNum])bfs(lchild[curNum], sum); 
	if (rchild[curNum])bfs(rchild[curNum], sum); 
}
int main() {
	while (readList(inOrder) && readList(postOrder)) {
		memset(lchild, 0, sizeof(lchild)); 
		memset(rchild, 0, sizeof(rchild)); 
		buildTree(0, n - 1, 0, n - 1); 
		//best = ROOT;
		best = postOrder[n - 1]; 
		best_sum = 1000000000; 
		//ROOT为父结点
		//建立树以后，对树做遍历
		bfs(postOrder[n-1], 0); 
		cout << best << endl; 
	}
}
