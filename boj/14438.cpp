#include<bits/stdc++.h>
using namespace std;
int n,m;
int type,tmp,temp;
int in[100010];
int seg[400000];
int init(int now,int s,int e){
    if(s==e) return seg[now]=in[s];
    return seg[now]=min(init(2*now,s,(s+e)/2),init(2*now+1,(s+e)/2+1,e));
}
int out(int now,int s,int e,int gs,int ge){
    if(gs<=s&&e<=ge) return seg[now];
    if(e<gs||ge<s) return 1e9;
    return min(out(2*now,s,(s+e)/2,gs,ge),out(2*now+1,(s+e)/2+1,e,gs,ge));
}
int up(int now,int s,int e,int idx,int v){
    if(s==e&&s==idx) return seg[now]=v;
    if(idx<s||e<idx) return seg[now];
    return seg[now]=min(up(2*now,s,(s+e)/2,idx,v),up(2*now+1,(s+e)/2+1,e,idx,v));
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    init(1,1,n);
    cin>>m;
    while(m--){
        scanf("%d %d %d",&type,&tmp,&temp);
        if(type==1) up(1,1,n,tmp,temp);
        else printf("%d\n",out(1,1,n,tmp,temp));
    }
}
