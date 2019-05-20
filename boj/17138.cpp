#include<bits/stdc++.h>
using namespace std;
struct data{int l,r,m,v;};
int n,q,w;
int a,b;
int in[250010];
data seg[1000000];
data def(int now,int s,int e){
    if(s==e) return seg[now]=(data){0,0,0,1};\
    def(2*now,s,(s+e)/2);
    def(2*now+1,(s+e)/2+1,e);
    data RE=(data){seg[2*now].v+seg[2*now+1].l,seg[2*now].r+seg[2*now+1].v,seg[2*now].r+seg[2*now+1].l,seg[2*now].v+seg[2*now+1].v};
    int tmp=2;
    if(in[(s+e)/2]+in[(s+e)/2+1]<=w) tmp=1;
    RE.l=min(RE.l,seg[2*now].l+seg[2*now+1].m+tmp);
    RE.r=min(RE.r,seg[2*now].m+seg[2*now+1].r+tmp);
    RE.m=min(RE.m,seg[2*now].m+seg[2*now+1].m+tmp);
    RE.v=min(RE.v,seg[2*now].l+seg[2*now+1].r+tmp);
    return seg[now]=RE;
}
data up(int now,int s,int e,int idx){
    if(s==e) return seg[now];
    if(idx<s||e<idx) return seg[now];
    up(2*now,s,(s+e)/2,idx);
    up(2*now+1,(s+e)/2+1,e,idx);
    data RE=(data){seg[2*now].v+seg[2*now+1].l,seg[2*now].r+seg[2*now+1].v,seg[2*now].r+seg[2*now+1].l,seg[2*now].v+seg[2*now+1].v};
    int tmp=2;
    if(in[(s+e)/2]+in[(s+e)/2+1]<=w) tmp=1;
    RE.l=min(RE.l,seg[2*now].l+seg[2*now+1].m+tmp);
    RE.r=min(RE.r,seg[2*now].m+seg[2*now+1].r+tmp);
    RE.m=min(RE.m,seg[2*now].m+seg[2*now+1].m+tmp);
    RE.v=min(RE.v,seg[2*now].l+seg[2*now+1].r+tmp);
    return seg[now]=RE;
}
int main(){
    cin>>n>>q>>w;
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    def(1,1,n);
    int out=seg[1].v;
    int temp=2;
    if(in[1]+in[n]<=w) temp=1;
    out=min(out,temp+seg[1].m);
    printf("%d\n",out);
    while(q--){
        scanf("%d %d",&a,&b);
        in[a]=b;
        up(1,1,n,a);
        out=seg[1].v;
        temp=2;
        if(in[1]+in[n]<=w) temp=1;
        out=min(out,temp+seg[1].m);
        printf("%d\n",out);
    }
}
