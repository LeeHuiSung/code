#include<bits/stdc++.h>
using namespace std;
int n,m;
int in[1000010];
long long ub=1e9,lb;
bool c(long long v){
    long long cnt=0;
    for(int i=1;i<=n;i++) if(in[i]>v) cnt+=(in[i]-v);
    return cnt>=m;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>in[i];
    while(ub-lb>=2){
        long long mid=(lb+ub)/2;
        if(c(mid)) lb=mid;
        else ub=mid;
    }
    if(c(ub)) printf("%lld",ub);
    else printf("%lld",lb);
}
