#include<bits/stdc++.h>
using namespace std;
struct dia{double w,c;};
int t,n;
dia in[210];
bool can[210][210];
int dp[210];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>in[i].w>>in[i].c;
        memset(can,0,sizeof(can));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(in[i].w<in[j].w&&in[i].c>in[j].c) can[j][i]=1;
            }
        }
        memset(dp,0,sizeof(dp));
        int anw=1;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++) if(can[i][j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            anw=max(anw,dp[i]);
        }
        printf("%d\n",anw);
    }
}
