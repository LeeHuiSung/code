#include<bits/stdc++.h>
using namespace std;
long long ub=1e9,lb=0;
int n,k;
int in[1000010];
bool c(long long t){
    long long RE=0;
    for(int i=1;i<=n;i++) if(t>in[i]) RE+=(t-in[i]);
    return RE<=k;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    while(ub-lb>1){
        long long m=(lb+ub)/2;
        if(c(m)) lb=m;
        else ub=m;
    }
    if(c(ub)) cout<<ub;
    else cout<<lb;
}
