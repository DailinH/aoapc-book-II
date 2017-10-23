#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	while(cin>>n&& n){
		long long res = 0;
		long long last = 0;
		int tmp = 0;
		for(int i = 0; i<n; i++){
			cin >> tmp;
			last+= tmp;
			res += abs(last);
		}
		cout << res << endl;
	}
}
