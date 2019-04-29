#include<bits/stdc++.h>
using namespace std;
struct data{int x,y,v;};
int n,m;
int in[110][110];
int cnt[110][110];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
queue<data> a;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++){
        scanf("%01d",&in[i][j]);
        cnt[i][j]=1e9;
    }
    cnt[1][1]=0;
    a.push((data){1,1,0});
    while(!a.empty()){
        int nx=a.front().x,ny=a.front().y,nv=a.front().v; a.pop();
        for(int i=0;i<4;i++){
            int tx=nx+dx[i],ty=ny+dy[i];
            if(tx>m||tx<1||ty>n||ty<1);
            else{
                bool chk=1;
                if(in[nx][ny]==1){if(cnt[tx][ty]<=(nv+1)) chk=0;}
                else if(cnt[tx][ty]<=nv) chk=0;
                if(chk){
                    if(in[nx][ny]==1){
                        cnt[tx][ty]=nv+1;
                        a.push((data){tx,ty,nv+1});
                    }
                    else{
                        cnt[tx][ty]=nv;
                        a.push((data){tx,ty,nv});
                    }
                }
            }
        }
    }
    cout<<cnt[m][n];
}
