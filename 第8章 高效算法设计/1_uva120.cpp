#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
//翻转0...k
const int maxn = 35;
int a[maxn];

void flip(int k){
	for(int i = 0; 2*i< k; i++){
		swap(a[i],a[k-i]);
	}
}
int main(){
	string s;
	while(getline(cin,s)){
		cout << s ;
		memset(a,0,sizeof(a));
		stringstream ss(s);
		int len = 0;
		while(ss>>a[len])
			len++;
//		cout << a[0];
//		for(int i = 1; i<len; i++)
//			cout << " "<< a[i];
		cout << endl;
		for(int i = len-1; i>0; i--){
			int mx = max_element(a,a+i+1)-a;
			if(mx == i)
				continue;
			//令最大值处于第i位上
			if(mx > 0){
				flip(mx);
				cout << len - mx << " ";
				//翻转后最大值处于0位上
			}
			flip(i);
			//再度翻转后最大值处于i位上，目的达成
			cout << len - i << " ";
		}
		cout << "0\n";
	}
}
