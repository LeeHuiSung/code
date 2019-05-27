#include<bits/stdc++.h>
using namespace std;
struct edge{int to,w;};
int n,k,tmf,tms,tmt;
int val[1010];
int adj[1010][1010];
int main(){
    cin>>n>>k;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) adj[i][j]=1e9;
    for(int i=0;i<=n;i++) adj[i][i+1]=1,adj[i+1][i]=0;
    while(k--){
        cin>>tmf>>tms>>tmt;
        adj[tmf-1][tms]=min(adj[tmf-1][tms],tmt);
        adj[tms][tmf-1]=-tmt;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++) if(adj[j][i]+adj[i][k]<adj[j][k]) adj[j][k]=adj[j][i]+adj[i][k];
        }
    }
    for(int i=0;i<=n;i++) if(adj[i][i]<0){
        cout<<"NONE";
        return 0;
    } adj[0][0]=0;
    for(int i=1;i<=n;i++){
        if(adj[0][i]==adj[0][i-1]) printf("-");
        else printf("#");
    }
}
