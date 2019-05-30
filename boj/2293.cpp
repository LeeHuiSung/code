#include<bits/stdc++.h>
using namespace std;
int n,m;
int in[110];
long long dp[10010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>in[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(j-in[i]>=0) dp[j]+=dp[j-in[i]];
    }
    cout<<dp[m];
}
