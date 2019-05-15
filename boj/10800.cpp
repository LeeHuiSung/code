#include<bits/stdc++.h>
using namespace std;
struct data{int c,w,idx,v;};
struct p{int c,w;};
int n,st;
int sum[200010];
data in[200010];
stack<p> lazy;
bool cmp1(data A,data B){return A.w<B.w;}
bool cmp2(data A,data B){return A.idx<B.idx;}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d %d",&in[i].c,&in[i].w);
    for(int i=1;i<=n;i++) in[i].idx=i;
    sort(in+1,in+n+1,cmp1);
    for(int i=1;i<=n;i++){
        if(i!=1&&in[i].w!=in[i-1].w){
            while(!lazy.empty()){
                st+=lazy.top().w;
                sum[lazy.top().c]+=lazy.top().w;
                lazy.pop();
            }
        }
        in[i].v=st-sum[in[i].c];
        lazy.push((p){in[i].c,in[i].w});
    }
    sort(in+1,in+1+n,cmp2);
    for(int i=1;i<=n;i++) printf("%d\n",in[i].v);
}
