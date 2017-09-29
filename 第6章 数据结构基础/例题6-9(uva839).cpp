#include < iostream > 
using namespace std; 
int cases; 
bool solve(int & w) {
	int w1, l1, w2, l2; 
	cin >> w1 >> l1 >> w2 >> l2; 
	bool b1 = true, b2 = true; 
	if ( ! w1)
		b1 = solve(w1); 
	if ( ! w2)
		b2 = solve(w2); 
	w = w1 + w2; //修改天平目前的总重量！这一步一定不能少！
	return
		(b1 && b2 && (w1 * l1 == w2 * l2)); 
}
int main() {
	int cases, W; 
	cin >> cases; 
	while (cases--) {
		if (solve(W)) {
			cout << "YES\n"; 
		}
		else cout << "NO\n"; 
		if (cases)cout << endl; 
	}
}