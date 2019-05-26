#include<bits/stdc++.h>
using namespace std;
struct data{int x;bool v,chk;};
int m,n,sum,anw=1e9,tmp;
data anwidx;
data dp[25][25][40010];
int in[25][25];
int prefix[25][25];
stack<int> a;
int main(){
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin>>in[i][j];
        sum+=in[i][j];
    }
    for(int i=n;i>=1;i--) for(int j=1;j<=n;j++) prefix[i][j]=prefix[i+1][j]+in[i][j];
    for(int j=1;j<=n;j++){
        for(int i=n+1;i>=1;i--){
            for(int t=0;t<=40000;t++){
                dp[i][j][t]=dp[i+1][j][t]; dp[i][j][t].chk=0;
                if(j==1){if(prefix[i][j]==t) dp[i][j][t]=(data){i,1,1};}
                else if(prefix[i][j]<=t&&!dp[i][j][t].v){
                    if(dp[i][j-1][t-prefix[i][j]].v) dp[i][j][t]=(data){i,1,1};
                }
            }
        }
    }
    for(int i=0;i<=40000;i++) if(dp[1][n][i].v){
        if(anw>abs(sum-i-i)){
            anw=abs(sum-i-i);
            anwidx=dp[1][n][i];
            tmp=i;
        }
    }
    printf("%d\n",anw);
    while(anwidx.x!=0){
        if(anwidx.chk){
            a.push(m+1-anwidx.x);
            n--;
            tmp-=prefix[anwidx.x][n+1];
            anwidx=dp[anwidx.x][n][tmp];
        }
        else anwidx=dp[anwidx.x][n][tmp];
    }
    while(!a.empty()){
        printf("%d ",a.top());
        a.pop();
    }
}
