#include<bits/stdc++.h>
using namespace std;
int n;
int in[110];
long long dp[110][30];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    dp[1][in[1]]=1;
    for(int i=2;i<n;i++) for(int j=0;j<=20;j++){
        if(j+in[i]<=20) dp[i][j]+=dp[i-1][j+in[i]];
        if(j-in[i]>=0) dp[i][j]+=dp[i-1][j-in[i]];
    }
    cout<<dp[n-1][in[n]];
}
