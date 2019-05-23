#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+3;
int n,k;
long long memo[1010][1010],anw;
long long f(int now,int cnt,int cons){
    if(cnt==0) return 1;
    if(now>cons) return 0;
    if(memo[now][cnt]!=-1) return memo[now][cnt];
    return memo[now][cnt]=(f(now+1,cnt,cons)+f(now+2,cnt-1,cons))%mod;
}
int main(){
    cin>>n>>k;
    memset(memo,-1,sizeof(memo));
    long long tmp=f(1,k-1,n-3);
    anw=tmp;
    memset(memo,-1,sizeof(memo));
    tmp=f(1,k,n-1);
    anw=(anw+tmp)%mod;
    cout<<anw;
}
