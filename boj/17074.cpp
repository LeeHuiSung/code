#include<bits/stdc++.h>
using namespace std;
int n,anw;
int in[200010];
bool seg[800000];
bool def(int now,int s,int e){
    if(s==e) return seg[now]=1;
    bool temp = (in[(s+e)/2] <= in[((s+e)/2)+1]);
    return seg[now]=(def(2*now,s,(s+e)/2)&def(2*now+1,(s+e)/2+1,e)&temp);
}
bool out(int now,int s,int e,int gs,int ge){
    if(gs<=s&&e<=ge) return seg[now];
    if(e<gs||ge<s) return 1;
    bool temp = (in[(s+e)/2] <= in[((s+e)/2)+1]);
    if(ge<(s+e)/2+1||(s+e)/2<gs) temp=1;
    return (out(2*now,s,(s+e)/2,gs,ge)&out(2*now+1,(s+e)/2+1,e,gs,ge)&temp);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    def(1,1,n);
    for(int i=2;i<n;i++) anw+=((out(1,1,n,1,i-1))&out(1,1,n,i+1,n)&(in[i-1]<=in[i+1]));
    anw+=out(1,1,n,1,n-1);
    anw+=out(1,1,n,2,n);
    cout<<anw;
}
