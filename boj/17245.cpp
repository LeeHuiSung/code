#include<bits/stdc++.h>
using namespace std;
long long lb=0,ub=10000000;
int n;
long long sum;
int in[1010][1010];
bool c(int t){
    long long RE=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) RE+=min(t,in[i][j]);
    if(sum%2) return RE>(sum/2);
    return RE>=(sum/2);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin>>in[i][j];
        sum+=in[i][j];
    }
    while(ub-lb>1){
        int m=(ub+lb)/2;
        if(c(m)) ub=m;
        else lb=m;
    }
    if(c(lb)) cout<<lb;
    else cout<<ub;
}
