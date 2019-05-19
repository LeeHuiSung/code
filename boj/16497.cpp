#include<bits/stdc++.h>
using namespace std;
int cnt[40];
int n,k;
int a,b,anw;
int main(){
    cin>>n;
    while(n--){
        cin>>a>>b;
        for(int i=a;i<b;i++) cnt[i]++;
    }
    cin>>k;
    for(int i=1;i<=31;i++) anw=max(anw,cnt[i]);
    cout<<(anw<=k);
}
