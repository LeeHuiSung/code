#include<bits/stdc++.h>
using namespace std;
struct data{int c,g;};
int n,m,k;
int memo[110][310][310];
data in[110];
int f(int now,int che,int gam){
    if(now>n) return 0;
    if(memo[now][che][gam]!=-1) return memo[now][che][gam];
    int RE=f(now+1,che,gam);
    if(che>=in[now].c&&gam>=in[now].g) RE=max(RE,f(now+1,che-in[now].c,gam-in[now].g)+1);
    return memo[now][che][gam]=RE;
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>in[i].c>>in[i].g;
    memset(memo,-1,sizeof(memo));
    cout<<f(1,m,k);
}
