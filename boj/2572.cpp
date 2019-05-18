#include<bits/stdc++.h>
using namespace std;
struct edge{int to;char w;};
int n,m,k,tmf,tms;
int memo[1010][510];
char in[1010],tmt;
vector<edge> d[510];
int f(int now,int ver){
    if(now>n) return 0;
    if(memo[now][ver]!=-1) return memo[now][ver];
    int RE=0,tmp=0;
    for(int i=0;i<d[ver].size();i++){
        tmp=f(now+1,d[ver][i].to);
        if(d[ver][i].w==in[now]) tmp++;
        RE=max(tmp,RE);
    }
    return memo[now][ver]=RE;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    memset(memo,-1,sizeof(memo));
    cin>>m>>k;
    while(k--){
        cin>>tmf>>tms>>tmt;
        d[tmf].push_back((edge){tms,tmt});
        d[tms].push_back((edge){tmf,tmt});
    }
    cout<<f(1,1)*10;
}
