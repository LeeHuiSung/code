#include <bits/stdc++.h>
using namespace std;
int n;
int dp[5010];
int main(){
    cin>>n;
    dp[3]=dp[5]=1;
    for(int i=6;i<=n;i++){
        if(dp[i-5]!=0) dp[i]=dp[i-5]+1;
        if(dp[i-3]!=0){
            if(dp[i]!=0) dp[i]=min(dp[i],dp[i-3]+1);
            else dp[i]=dp[i-3]+1;
        }
    }
    if(dp[n]) cout<<dp[n];
    else cout<<"-1";
}
