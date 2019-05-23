#include<bits/stdc++.h>
using namespace std;
struct data{int v;bool chk;};
data in[100010];
int n;
int re[100010],ord[100010];
int seg[400000];
bool cmp(data A,data B){return A.v<B.v;}
int up(int now,int s,int e,int idx){
    if(s==e&&s==idx) return seg[now]=0;
    if(idx<s||e<idx) return seg[now];
    return seg[now]=up(2*now,s,(s+e)/2,idx)+up(2*now+1,(s+e)/2+1,e,idx);
}
int out(int now,int s,int e,int gs,int ge){
    if(gs<=s&&e<=ge) return seg[now];
    if(e<gs||ge<s) return 0;
    return out(2*now,s,(s+e)/2,gs,ge)+out(2*now+1,(s+e)/2+1,e,gs,ge);
}
int  def(int now,int s,int e){
    if(s==e) return seg[now]=1;
    return seg[now]=def(2*now,s,(s+e)/2)+def(2*now+1,(s+e)/2+1,e);
}
bool c(int t,int com){
    int RE=out(1,1,n,1,t);
    return RE>=com;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&in[i].v);
    for(int i=1;i<=n;i++) scanf("%d",&ord[i]);
    sort(in+1,in+1+n,cmp);
    def(1,1,n);
    for(int i=n;i>=1;i--){
        int lb=1,ub=n,idx;
        while(ub-lb>1){
            int mid=(lb+ub)/2;
            if(c(mid,ord[i]+1)) ub=mid;
            else lb=mid;
        }
        if(c(lb,ord[i]+1)) idx=lb;
        else idx=ub;
        up(1,1,n,idx);
        re[i]=in[idx].v;
    }
    for(int i=1;i<=n;i++) printf("%d\n",re[i]);
}
