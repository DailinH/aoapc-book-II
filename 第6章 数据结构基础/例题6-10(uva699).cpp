#include < iostream > 
#include < cstring > 
using namespace std; 
const int maxn = 100000 + 10; 
int sum[maxn]; 

void build(int position) {
	int v; 
	cin >> v; 
	if (v == -1)return; 
	sum[position] + = v; 
	build(position - 1); 
	build(position + 1); 
}
bool init() {
	int v; 
	cin >> v; 
	if (v == -1)return false; 
	memset(sum, 0, sizeof(sum)); 
	int pos = maxn / 2; 
	sum[pos] + = v; 
	build(pos - 1); 
	build(pos + 1); 
	return true; 
}
int main() {
	int cse = 0; 
	while (init()) {
		cse++; 
		cout << "Case " << cse << ":\n"; 
		int i = 0; 
		while (true) {
			if ( ! sum[i]) {
				i++; 
			}
			else break; 
		}
		cout << sum[i]; 
		for (int k = i + 1; sum[k] > 0; k++) {
			cout << " " << sum[k]; 
		}
		cout << endl << endl; 
	}
}