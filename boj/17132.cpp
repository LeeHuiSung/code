#include<bits/stdc++.h>
using namespace std;
typedef pair<long,long> p;
struct data{int to;};
struct edge{int f,t,w;};
int n;
long long anw;
edge in[100010];
p dp[100010];
int ver[100010];
int par[100010],ran[100010];
int fi(int X){return (par[X]==X)?X:fi(par[X]);}
void uni(int X,int Y){
    X=fi(X);
    Y=fi(Y);
    if(ran[Y]>ran[X]) par[X]=Y;
    else{
        if(ran[X]==ran[Y]) ran[X]++;
        par[Y]=X;
    }
}
bool cmp(edge A,edge B){return A.w>B.w;}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&in[i].f,&in[i].t,&in[i].w);
    }
    for(int i=1;i<=n;i++) par[i]=i;
    sort(in+1,in+n,cmp);
    for(int i=1;i<n;i++){
        dp[i].first=1+ver[fi(in[i].f)];
        dp[i].second=1+ver[fi(in[i].t)];
        long long tmp=ver[fi(in[i].f)]+ver[fi(in[i].t)]+1;
        uni(in[i].f,in[i].t);
        ver[fi(in[i].f)]=tmp;
        anw+=(dp[i].first*dp[i].second*in[i].w);
    }
    cout<<anw;
}
