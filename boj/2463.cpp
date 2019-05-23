#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9;
struct edge{int to,fr; long long w;};
long long anw;
int n,m;
long long rsum,sum,tmp,ver[100010];
int par[100010],ran[100010];
edge in[100010];
int fi(int X){return (X==par[X])?par[X]:fi(par[X]);}
void un(int X,int Y){
    X=fi(X);
    Y=fi(Y);
    if(ran[Y]>ran[X]) par[X]=Y;
    else{
        par[Y]=X;
        if(ran[X]==ran[Y]) ran[X]++;
    }
}
bool cmp(edge A,edge B){return A.w>B.w;}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) par[i]=i,ver[i]=1;
    for(int i=1;i<=m;i++){
        scanf("%d %d %lld",&in[i].fr,&in[i].to,&in[i].w);
        rsum+=in[i].w;
    }
    sort(in+1,in+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(fi(in[i].fr)!=fi(in[i].to)){
            tmp=ver[fi(in[i].fr)]*ver[fi(in[i].to)]*(rsum-sum);
            ver[fi(in[i].fr)]+=ver[fi(in[i].to)];
            ver[fi(in[i].to)]=ver[fi(in[i].fr)];
            un(in[i].fr,in[i].to);
            anw=(anw+tmp)%mod;
        }
        sum+=in[i].w;
    }
    cout<<anw;
}
