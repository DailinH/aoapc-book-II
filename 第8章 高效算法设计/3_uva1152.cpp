#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 4010;
int A[maxn];
int B[maxn];
int C[maxn];
int D[maxn];
bool binarySearch(int tgt, int b, int e){
	int mid = b+(e-b)/2;
	if(b == e && D[b]!= tgt)
		return false;
	if(tgt == D[mid])
		return true;
	else if(tgt < D[mid])
		return binarySearch(tgt,b,mid-1);
	else 
		return binarySearch(tgt,mid+1,e);

}

int main(){
	int T,num;
	cin >> num;
	while( num-- ){
		cin >> T;
		int cnt = 0;
		for(int i = 0; i<T; i++)
			cin >> A[i] >> B[i] >> C[i] >> D[i];
//		sort(a,a+T);
//		sort(b,b+T);
//		sort(c,c+T);
		sort(D,D+T);
		for(int i = 0; i<T; i++){
			for(int j = 0; j<T; j++){
				for(int k = 0; k<T; k++){
					int cmp = A[i]+B[j]+C[k];
					if(binarySearch(-cmp,0,T))
						cnt++;
//						cout <<"("<< A[i] <<" "<< B[j] <<" "<< C[k] <<" "<< 0-cmp<<")\n";
				}
			}
		}
		cout << cnt << endl<<endl;
	}
}
