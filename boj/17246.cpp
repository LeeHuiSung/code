#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int tmf,tms,tmt;
int adj[210][210];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) adj[i][j]=1e9;
    while(m--){
        cin>>tmf>>tms>>tmt;
        adj[tmf][tms]=tmt;
        adj[tms][tmf]=tmt;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++) if(adj[j][i]+adj[i][k]<adj[j][k]){
                adj[j][k]=adj[j][i]+adj[i][k];
            }
        }
    }
    cin>>q;
    while(q--){
        scanf("%d %d",&tmf,&tms);
        if(adj[tmf][tms]!=1e9) printf("%d\n",adj[tmf][tms]);
        else printf("-1\n");
    }
}
