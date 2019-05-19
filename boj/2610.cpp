#include<bits/stdc++.h>
using namespace std;
struct data{int idx,v; bool sel;};
struct op{int v;};
bool operator<(op A,op B){return A.v>B.v;}
int n,m,cnt;
int tmf,tms;
int dis[110][110];
bool used[110][110],selec[110];
int par[110],ran[110];
data opt[110];
vector<int> d[110];
queue<int> a;
priority_queue<op> out;
bool cmp(data A,data B){return A.v<B.v;}
int fi(int X){return (par[X]==X)?par[X]:fi(par[X]);}
void un(int X,int Y){
    X=fi(X);
    Y=fi(Y);
    if(ran[X]<ran[Y]) par[X]=Y;
    else{
        par[Y]=X;
        if(ran[X]==ran[Y]) ran[X]++;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) par[i]=i;
    while(m--){
        cin>>tmf>>tms;
        un(tmf,tms);
        d[tmf].push_back(tms);
        d[tms].push_back(tmf);
    }
    for(int i=1;i<=n;i++){
        if(!selec[fi(i)]){
            selec[fi(i)]=1;
            cnt++;
        }
        a.push(i);
        used[i][i]=1;
        while(!a.empty()){
            tmf=a.front(); a.pop();
            for(int j=0;j<d[tmf].size();j++) if(!used[i][d[tmf][j]]){
                used[i][d[tmf][j]]=1;
                dis[i][d[tmf][j]]=dis[i][tmf]+1;
                a.push(d[tmf][j]);
            }
        }
        tms=0;
        for(int j=1;j<=n;j++) tms=max(tms,dis[i][j]);
        opt[i]=(data){i,tms,0};
    }
    memset(selec,0,sizeof(selec));
    sort(opt+1,opt+n+1,cmp);
    for(int i=1;i<=n;i++) if(!selec[fi(opt[i].idx)]){
        selec[fi(opt[i].idx)]=1;
        out.push((op){opt[i].idx});
    }
    printf("%d\n",cnt);
    while(!out.empty()){
        printf("%d\n",out.top().v);
        out.pop();
    }
}
