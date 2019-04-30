#include<bits/stdc++.h>
using namespace std;
long long lb,ub=1e9;
int n,m;
int in[200010];
bool c(long long dist){
    int cnt=1,pre;
    pre=in[1];
    for(int i=2;i<=n;i++){
        if(pre+dist>in[i]);
        else{
            pre=in[i];
            cnt++;
        }
    }
    return cnt>=m;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>in[i];
    sort(in+1,in+1+n);
    while(ub-lb>1){
        long long mid=(ub+lb)/2;
        if(c(mid)) lb=mid;
        else ub=mid;
    }
    if(c(ub)) cout<<ub;
    else cout<<lb;
}
