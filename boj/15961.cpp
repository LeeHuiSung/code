#include<bits/stdc++.h>
using namespace std;
int n,d,k,c,anw,tmcnt;
int in[3003010];
int cnt[3010];
int main(){
    cin>>n>>d>>k>>c;
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    for(int i=n+1;i<n+k;i++) in[i]=in[i-n];
    for(int i=1;i<k;i++){
        if(cnt[in[i]]==0) tmcnt++;
        cnt[in[i]]++;
    }
    for(int i=k;i<n+k;i++){
        cnt[in[i-k]]--;
        if(cnt[in[i-k]]==0) tmcnt--;
        if(cnt[in[i]]==0) tmcnt++;
        cnt[in[i]]++;
        if(cnt[c]==0) anw=max(anw,tmcnt+1);
        else anw=max(anw,tmcnt);
    }
    cout<<anw;
}
