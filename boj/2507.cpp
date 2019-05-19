#include<bits/stdc++.h>
using namespace std;
struct data{int lo,v,t,mto,mre;};
const int mod=1e3;
int n;
int memo[510][510];
data ver[510];
int f(int fv,int sv,int k){
    if(memo[fv][sv]==-1){
        if(k==n) return (ver[fv].lo+ver[fv].v>=ver[k].lo)&&(ver[sv].lo>=ver[k].lo-ver[k].v);
        memo[fv][sv]=f(fv,sv,k+1);
        if(ver[fv].v+ver[fv].lo>=ver[k].lo) memo[fv][sv]=(memo[fv][sv]+f(k,sv,k+1))%mod;
        if(ver[k].t&&ver[sv].lo>=ver[k].lo-ver[k].v) memo[fv][sv]=(memo[fv][sv]+f(fv,k,k+1))%mod;
    }
    return memo[fv][sv];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ver[i].lo>>ver[i].v>>ver[i].t;
    memset(memo,-1,sizeof(memo));
    cout<<f(1,1,2);
}
