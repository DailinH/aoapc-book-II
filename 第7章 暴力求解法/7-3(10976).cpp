#include <iostream> 
#include <queue>
using namespace std;
struct ans{
    long long x;
    int y;
};
int main(){
    int k;
    while(cin >> k){
        queue<ans> ansseq;
        // int tot = 0;
        for(int y = k+1; y<=2*k; y++){
            long long x = ((k*y)%(y-k) == 0? (k*y)/(y-k) : -1);
            if(x!= -1) {
                ans tmp;
                tmp.x = x;
                tmp.y = y;
                ansseq.push(tmp);
                // cout << "1/"<<k<<" = 1/"<<x << " + 1/" << y << endl; 
                // tot++;
            }
        }
        cout << ansseq.size() << endl;
        while(ansseq.size()){
            ans t = ansseq.front();
            ansseq.pop();
            cout << "1/"<<k<<" = 1/"<<t.x << " + 1/" << t.y << endl; 
            
        }
    }
}