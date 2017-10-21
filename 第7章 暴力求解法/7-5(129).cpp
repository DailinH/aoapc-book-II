#include <iostream>
#include <string>
// #include <cstring>
using namespace std;
int n, L;
string ans;
bool Hard(string a){//判断是否为困难子串
    int l = a.length();
    for(int i = 1; i<= l/2; i++){//长度为i的后缀
        for(int j = 0; j<i; j++){
            if(a[l - i + j] == a[l-2*i+j])
                return false;
        }
    }
    return true;
}
void dfs(int cur){
    if(cur == n){
        for(int i = 1; i<=ans.length(); i++){
            cout << ans[i-1];
            if(i % 4) cout << " ";
        }
        cout << endl;
        cout << ans.length();
        return;
    }
    for(int i = 0; i<L; i++){
        char *a = 'A' + i;
        ans+= a;
        if(Hard(ans))
            dfs(cur+1);
        ans=ans.substr(0,ans.length()-1);
    }
}


int main(){
    while(cin>> n >> L && n && L){
        //第n个序列，共L个字母中选择；
        dfs(0);
    }
}