#include <iostream>
using namespace std;
char printchar(int n){
	if(n<26)
		return 'A'+n;
	else
		return 'a'+n-26;
}
int main(){
//要求：
//	如果上下/左右/前后相邻，则为adjacent
//	建立n个国家，两两之间相连
	int n;
	while(cin >> n){
		cout << 2 << " " << n << " " << n << endl;
		for(int i = 0; i<n ;i++){
			cout << printchar(i);
			for(int j = 1; j<n; j++){
				cout << printchar(i);
			}
			cout << endl;
		}
		cout << endl;
		for(int i = 0; i<n ;i++){
			char c = printchar(0);
			cout << c;
			for(int j = 1; j<n; j++){
				cout << printchar(j);
			}
			cout << endl;
		}	
//		cout << endl;
	}
}
