#include<bits/stdc++.h>
using namespace std;
struct data{bool chk; int v;};
int T,n,m,in[510];
data dp[3][100010]; // i번째 기타까지 선택했을 때, 합의 나머지가 j인 최대 기타의 수
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>in[i];
            in[i]%=m;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0].chk=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                dp[1][j]=dp[0][j];
                int tmp=j-in[i];
                if(tmp<0) tmp+=m;
                if(dp[0][tmp].chk){
                    if(dp[1][j].chk) dp[1][j].v=max(dp[1][j].v,dp[0][tmp].v+1);
                    else{
                        dp[1][j]=dp[0][tmp];
                        dp[1][j].v++;
                    }
                }
            }
            for(int j=0;j<m;j++){
                dp[0][j]=dp[1][j];
                dp[1][j]=(data){0,0};
            }
        }
        printf("%d\n",dp[0][0].v);
    }
}
