#include<bits/stdc++.h>
using namespace std;
int n,gc,anw;
int in[100010];
int dis[100010];
int gcd(int A,int B){return (A%B)?gcd(B,A%B):B;}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    sort(in+1,in+1+n);
    for(int i=1;i<n;i++) dis[i]=in[i+1]-in[i];
    gc=dis[1];
    for(int i=2;i<n;i++) gc=gcd(gc,dis[i]);
    for(int i=1;i<n;i++) anw+=((dis[i]/gc)-1);
    cout<<anw;
}
