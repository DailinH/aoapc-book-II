#include <iostream> 
using namespace std;
int maxn = 20;
void printResult(int cse, long long int result){
    cout << "Case #"<<cse << ": The maximum product is "<< result << ".\n\n";    
}
int main(){
    int len;
    int cse = 0;
    while(cin >> len){
        cse++;
        long long int a[maxn][maxn] = {0};//a[i][j]表示从i到j的乘积
        // int cresult = 1;
        for(int i = 0; i<len; i++){
            cin >> a[i][i];
        }
        for(int i = 0; i<len; i++){
            for(int j = i+1; j<len; j++){
                a[i][j] = a[i][j-1]*a[j][j];
            }
        }
        long long largest = 0;
        for(int i = 0; i<len; i++){
            for(int j = 0; j<len; j++){
                if(a[i][j]>largest) largest = a[i][j];
            }
        }
        printResult(cse, largest);
 
    }
}