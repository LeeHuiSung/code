#include<bits/stdc++.h>
using namespace std;
struct point{int x,y,ord;};
const long long mod=1e9+7;
int n,cnt;
long long anw;
long long seg[800000];
point in[200010];
stack<int> pre;
bool cmp1(point A,point B){return A.x<B.x;}
bool cmp2(point A,point B){return A.y>B.y;}
long long up(int now,int s,int e,int idx){
    if(s==e&&s==idx) return seg[now]=seg[now]+1;
    if(idx<s||e<idx) return seg[now];
    return seg[now]=up(2*now,s,(s+e)/2,idx)+up(2*now+1,(s+e)/2+1,e,idx);
}
long long out(int now,int s,int e,int gs,int ge){
    if(gs<=s&&e<=ge) return seg[now];
    if(ge<s||e<gs) return 0;
    return out(2*now,s,(s+e)/2,gs,ge)+out(2*now+1,(s+e)/2+1,e,gs,ge);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i].x>>in[i].y;
    sort(in+1,in+n+1,cmp1);
    for(int i=1;i<=n;i++){
        if(i==1||in[i].x!=in[i-1].x) cnt++;
        in[i].ord=cnt;
    } cnt++;
    sort(in+1,in+n+1,cmp2);
    for(int i=1;i<=n;i++){
        if(i!=1&&in[i].y!=in[i-1].y){
            while(!pre.empty()){
                up(1,1,cnt,pre.top());
                pre.pop();
            }
        }
        long long tmp=((out(1,1,cnt,in[i].ord+1,cnt))*(out(1,1,cnt,1,in[i].ord-1)))%mod;
        anw=(anw+tmp)%mod;
        pre.push(in[i].ord);
    }
    cout<<anw;
}
