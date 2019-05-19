#include<bits/stdc++.h>
using namespace std;
struct data{int w,c;};
int n,m;
data in[110];
int dp[110][10010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>in[i].w;
    for(int i=1;i<=n;i++) cin>>in[i].c;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(j-in[i].c>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-in[i].c]+in[i].w);
        }
    }
    for(int i=0;i<=10000;i++) if(dp[n][i]>=m){
        printf("%d",i);
        break;
    }
}
