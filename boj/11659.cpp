#include<bits/stdc++.h>
using namespace std;
int n,m;
int type,tmp,temp;
int in[100010];
int seg[400000];
int init(int now,int s,int e){
    if(s==e) return seg[now]=in[s];
    return seg[now]=init(2*now,s,(s+e)/2)+init(2*now+1,(s+e)/2+1,e);
}
int out(int now,int s,int e,int gs,int ge){
    if(gs<=s&&e<=ge) return seg[now];
    if(e<gs||ge<s) return 0;
    return out(2*now,s,(s+e)/2,gs,ge)+out(2*now+1,(s+e)/2+1,e,gs,ge);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    init(1,1,n);
    while(m--){
        scanf("%d %d",&tmp,&temp);
        printf("%d\n",out(1,1,n,tmp,temp));
    }
}
