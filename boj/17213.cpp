#include<bits/stdc++.h>
using namespace std;
int n,m;
int memo[15][35];
int f(int now,int cnt){
    if(cnt==0) return 1;
    if(now>n) return 0;
    if(memo[now][cnt]!=-1) return memo[now][cnt];
    int RE=0;
    for(int i=cnt;i>=0;i--) RE+=f(now+1,i);
    return memo[now][cnt]=RE;
}
int main(){
    cin>>n>>m;
    m-=n;
    memset(memo,-1,sizeof(memo));
    cout<<f(1,m);
}
