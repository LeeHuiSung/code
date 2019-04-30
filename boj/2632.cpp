#include<bits/stdc++.h>
using namespace std;
int g,n,m,tmp,anw;
int cnt[2000010];
int fsum[1010],ssum[1010];
int main(){
    cin>>g>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        fsum[i]=fsum[i-1]+tmp;
    }
    for(int i=1;i<=m;i++){
        cin>>tmp;
        ssum[i]=ssum[i-1]+tmp;
    }
    cnt[fsum[n]]=1;
    for(int i=1;i<=n;i++) for(int l=1;l<n;l++){
        if(i+l-1>n) cnt[fsum[n]-fsum[i-1]+fsum[i+l-1-n]]++;
        else cnt[fsum[i+l-1]-fsum[i-1]]++;
    }
    cnt[0]=1;
    if(g>=ssum[m]) anw+=cnt[g-ssum[m]];
    for(int i=1;i<=m;i++) for(int l=1;l<m;l++){
        int val=0;
        if(i+l-1>m) val=ssum[m]-ssum[i-1]+ssum[i+l-1-m];
        else val=ssum[i+l-1]-ssum[i-1];
        if(g>=val) anw+=cnt[g-val];
    }
    cout<<anw+cnt[g];
}
