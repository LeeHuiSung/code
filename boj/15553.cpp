#include <bits/stdc++.h>
using namespace std;
int n,k,tmp,pre,anw,dis[100010];
int main(){
    cin>>n>>k;
    k=n-k;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(i!=0) dis[i]=tmp-pre-1;
        pre=tmp;
        anw++;
    }
    sort(dis+1,dis+n);
    for(int i=1;i<=k;i++) anw+=dis[i];
    cout<<anw;
}
