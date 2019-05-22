#include<bits/stdc++.h>
using namespace std;
struct data{int idx,dsp;};
int n,q,m;
int tmp,temp;
int dp[25][100010];
int dep[100010];
bool used[100010];
vector<int> d[100010];
void dfs(int now,int depth){
    dep[now]=depth;
    for(int i=0;i<d[now].size();i++) if(!dp[0][d[now][i]]){
        dp[0][d[now][i]]=now;
        dfs(d[now][i],depth+1);
    }
}
int main(){
    cin>>n;
    while((1<<m)<n) m++;
    for(int i=1;i<n;i++){
        scanf("%d %d",&tmp,&temp);
        d[tmp].push_back(temp);
        d[temp].push_back(tmp);
    }
    dp[0][1]=1;
    dfs(1,0);
    for(int j=1;j<=m;j++) for(int i=1;i<=n;i++) dp[j][i]=dp[j-1][dp[j-1][i]];
    cin>>q;
    while(q--){
        scanf("%d %d",&tmp,&temp);
        if(dep[tmp]<dep[temp]){
            int sw=tmp;
            tmp=temp;
            temp=sw;
        }
        int cha=dep[tmp]-dep[temp];
        for(int i=0;cha;i++){
            if(cha%2) tmp=dp[i][tmp];
            cha/=2;
        }
        if(tmp!=temp){
            for(int i=m;i>=0;i--){
                if(dp[i][tmp]!=dp[i][temp]){
                    tmp=dp[i][tmp];
                    temp=dp[i][temp];
                }
            }
            tmp=dp[0][tmp];
        }
        printf("%d\n",tmp);
    }
}
