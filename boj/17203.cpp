#include<bits/stdc++.h>
using namespace std;
int n,q,qs,qe;
int in[1010];
int cha[1010];
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>in[i];
    for(int i=1;i<n;i++) cha[i]=abs(in[i+1]-in[i])+cha[i-1];
    while(q--){
        cin>>qs>>qe;
        if(qe-1<qs) printf("0\n");
        else printf("%d\n",cha[qe-1]-cha[qs-1]);
    }
}
