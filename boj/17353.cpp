#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define ROF(i,a,b) for(int i=int(b);i>=int(a);i--)
#define pb push_back
using namespace std;
struct data{long long cnt,v;};
int n,q,tmf,tms,type;
data lazy[400000];
long long in[100010];
void u_lazy(int now,int s,int e){
    if(s==e){
        in[s]+=lazy[now].v;
        lazy[now]=(data){0,0};
        return;
    }
    int mid=(s+e)/2;
    lazy[2*now]=(data){lazy[2*now].cnt+lazy[now].cnt,lazy[2*now].v+lazy[now].v};
    lazy[2*now+1]=(data){lazy[2*now+1].cnt+lazy[now].cnt,lazy[2*now+1].v+lazy[now].v+lazy[now].cnt*(mid+1-s)};
    lazy[now]=(data){0,0};
    return;
}
void up(int now,int s,int e,int gs,int ge){
    if(gs<=s&&e<=ge){
        lazy[now]=(data){lazy[now].cnt+1,lazy[now].v+s-gs+1};
        return;
    }
    if(ge<s||e<gs) return;
    up(2*now,s,(s+e)/2,gs,ge);
    up(2*now+1,(s+e)/2+1,e,gs,ge);
}
long long out(int now,int s,int e,int idx){
    if(lazy[now].cnt) u_lazy(now,s,e);
    if(idx<s||e<idx) return 0;
    if(s==e) return in[s];
    return out(2*now,s,(s+e)/2,idx)+out(2*now+1,(s+e)/2+1,e,idx);
}
int main(){
    cin>>n;
    FOR(i,1,n) scanf("%lld",&in[i]);
    cin>>q;
    while(q--){
        scanf("%d %d",&type,&tmf);
        if(type==1){
            scanf("%d",&tms);
            up(1,1,n,tmf,tms);
        }
        else printf("%lld\n",out(1,1,n,tmf));
    }
}
