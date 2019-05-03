#include<bits/stdc++.h>
using namespace std;
int n,q,tmp,temp;
int in[200018];
long long seg[800010];
int realin[200010];
long long init(int now,int s,int e){
    if(s==e) return seg[now]=realin[s];
    return seg[now]=init(2*now,s,(s+e)/2)+init(2*now+1,(s+e)/2+1,e);
}
long long up(int now,int s,int e,int idx){
    if(idx<s||e<idx) return seg[now];
    if(s==e&&s==idx) return seg[now]=realin[tmp];
    return seg[now]=up(2*now,s,(s+e)/2,idx)+up(2*now+1,(s+e)/2+1,e,idx);
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    in[n+1]=in[1]; in[n+2]=in[2]; in[n+3]=in[3];
    for(int i=1;i<=n;i++) realin[i]=in[i]*in[i+1]*in[i+2]*in[i+3];
    init(1,1,n);
    while(q--){
        scanf("%d",&tmp);
        realin[tmp]*=-1;
        up(1,1,n,tmp);
        for(int loop=1;loop<4;loop++){
            tmp--;
            if(tmp<1) tmp=n;
            realin[tmp]*=-1;
            up(1,1,n,tmp);
        }
        printf("%lld\n",seg[1]);
    }
}
