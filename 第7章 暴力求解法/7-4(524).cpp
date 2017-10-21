#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 20;
int mkr[maxn];
int cnt[maxn];
bool isPrime(int p) {
	if (p <= 3 || p == 5 || p == 7 || p == 11 || p == 13 || p == 17 || p == 19 || p == 23 || p == 29 || p == 31)
		return true;
	return false;
}
void primeRing(int n, int cur) {
	if (n == 1) {
		cout << "1" << endl;
		return;
	}
	if (cur == n) {//output
		if (!isPrime(1 + mkr[n - 1]))
			return;
		for (int i = 0; i<n - 1; i++) {
			cout << mkr[i] << " ";
		}
		cout << mkr[n - 1] << endl;
		return;
	}
	for (int i = 2; i<=n; i++) {
		if (cnt[i])
			continue;
		else if (isPrime(i + mkr[cur - 1])) {
			mkr[cur] = i;
			cnt[i] = 1;
			primeRing(n, cur + 1);
			cnt[i] = 0;
		}
	}

}

int main() {
	int n;
	int cases = 0;
	while (cin >> n) {
		memset(mkr, 0, sizeof(mkr));
		memset(cnt, 0, sizeof(cnt));
		mkr[0] = 1;
		cnt[1] = 1;
		if (cases != 0) cout << endl;
		cout << "Case " << ++cases << ":\n";
		primeRing(n, 1);
		//cout << endl;
	}
}