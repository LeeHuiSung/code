#include<bits/stdc++.h>
using namespace std;
struct data{int f,s; char e;};
int n,m;
data in[1010];
bool cmp(data A,data B){
    if(A.s==B.s) return A.f<B.f;
    return A.s<B.s;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) scanf("%d %d %c",&in[i].f,&in[i].s,&in[i].e);
    sort(in+1,in+m+1,cmp);
    for(int i=1;i<=m;i++) printf("%c",in[i].e);
}
