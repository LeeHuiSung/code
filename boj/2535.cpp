#include<bits/stdc++.h>
using namespace std;
struct data{int c,nu,v;};
int n,tmp;
data in[110];
int cnt[110];
bool cmp(data A,data B){return A.v>B.v;}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i].c>>in[i].nu>>in[i].v;
    sort(in+1,in+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(tmp==3) break;
        if(cnt[in[i].c]<2){
            cnt[in[i].c]++;
            tmp++;
            printf("%d %d\n",in[i].c,in[i].nu);
        }
    }
}
