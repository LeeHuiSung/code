#include<bits/stdc++.h>
using namespace std;
struct data{long long x,y,v; int idx;};
int n;
data in[500010];
long long prefix[500010];
bool cmpx(data A,data B){return A.x<B.x;}
bool cmpy(data A,data B){return A.y<B.y;}
bool cmpv(data A,data B){
    if(A.v==B.v) return A.idx<B.idx;
    return A.v<B.v;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&in[i].x,&in[i].y);
        in[i].idx=i;
    }
    sort(in+1,in+n+1,cmpx);
    for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+in[i].x;
    for(int i=1;i<=n;i++) in[i].v+=(((i-1)*in[i].x-prefix[i-1])+(prefix[n]-prefix[i]-(n-i)*in[i].x));
    sort(in+1,in+n+1,cmpy);
    for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+in[i].y;
    for(int i=1;i<=n;i++) in[i].v+=(((i-1)*in[i].y-prefix[i-1])+(prefix[n]-prefix[i]-(n-i)*in[i].y));
    sort(in+1,in+n+1,cmpv);
    cout<<in[1].idx;
}
