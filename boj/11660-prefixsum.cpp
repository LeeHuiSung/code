#include<bits/stdc++.h>
using namespace std;
int n,m,tmp;
int xf,yf,xs,ys;
int in[1030][1030];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin>>tmp;
        in[i][j]=in[i-1][j]+in[i][j-1]+tmp-in[i-1][j-1];
    }
    while(m--){
        scanf("%d %d %d %d",&yf,&xf,&ys,&xs);
        printf("%d\n",in[ys][xs]-in[ys][xf-1]-in[yf-1][xs]+in[yf-1][xf-1]);
    }
}
