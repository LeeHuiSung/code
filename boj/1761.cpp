#include<bits/stdc++.h>
using namespace std;
struct data{int v,dis;};
struct edge{int to,w;};
data dp[20][40010];
int dep[40010];
int n,m,q;
int tmf,tms,tmt;
vector<edge> d[40010];
void dfs(int now,int depth){
    dep[now]=depth;
    for(int i=0;i<d[now].size();i++) if(!dp[0][d[now][i].to].v){
        dp[0][d[now][i].to].dis=d[now][i].w;
        dp[0][d[now][i].to].v=now;
        dfs(d[now][i].to,depth+1);
    }
}
int main(){
    cin>>n;
    while((1<<m)<n) m++;
    for(int i=1;i<n;i++){
        cin>>tmf>>tms>>tmt;
        d[tmf].push_back((edge){tms,tmt});
        d[tms].push_back((edge){tmf,tmt});
    }
    dp[0][1]=(data){1,0};
    dfs(1,0);
    for(int j=1;j<=m;j++) for(int i=1;i<=n;i++){
        dp[j][i].v=dp[j-1][dp[j-1][i].v].v;
        if(dp[j-1][i].v==1) dp[j][i].dis=dp[j-1][i].dis;
        else dp[j][i].dis=dp[j-1][i].dis+dp[j-1][dp[j-1][i].v].dis;
    }
    cin>>q;
    while(q--){
        cin>>tmf>>tms;
        if(dep[tmf]<dep[tms]) swap(tmf,tms);
        tmt=dep[tmf]-dep[tms];
        int anw=0;
        for(int i=0;tmt;i++){
            if(tmt%2){
                anw+=dp[i][tmf].dis;
                tmf=dp[i][tmf].v;
            }
            tmt/=2;
        }
        if(tmf!=tms){
            for(int i=m;i>=0;i--){
                if(dp[i][tmf].v!=dp[i][tms].v){
                    anw+=dp[i][tmf].dis;
                    anw+=dp[i][tms].dis;
                    tmf=dp[i][tmf].v;
                    tms=dp[i][tms].v;
                }
            }
            anw+=dp[0][tmf].dis;
            anw+=dp[0][tms].dis;
        }
        printf("%d\n",anw);
    }
}
