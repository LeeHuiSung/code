#include<bits/stdc++.h>
using namespace std;
int w,h,n,m,t,anx,any;
int main(){
    cin>>w>>h>>n>>m>>t;
    n+=t;
    m+=t;
    if((n/w)%2) anx=w-n%w;
    else anx=n%w;
    if((m/h)%2) any=h-m%h;
    else any=m%h;
    printf("%d %d",anx,any);
}
