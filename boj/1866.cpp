#include<bits/stdc++.h>
using namespace std;
int n,t,h;
int in[3010];
int dp[3010][10010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    cin>>t>>h;
    sort(in+1,in+1+n);
    dp[1][10001]=dp[1][0]=t*in[1];
    for(int i=1;i<=10000;i++){
        dp[1][i]=min(h+t*in[1],h+t*abs(in[1]-i));
        dp[1][10001]=min(dp[1][10001],dp[1][i]);
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=10000;j++){
            dp[i][j]=min(dp[i-1][j]+t*in[i],min(dp[i-1][j]+t*abs(in[i]-j),min(dp[i-1][10001]+h+t*in[i],dp[i-1][10001]+h+t*abs(in[i]-j))));
            if(j==0||dp[i][10001]>dp[i][j]) dp[i][10001]=dp[i][j];
        }
    }
    cout<<dp[n][10001];
}
