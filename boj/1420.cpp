#include<bits/stdc++.h>
using namespace std;
struct edge{int tox,toy,cap,rev;};
vector<edge> d[210][210];
int n,m,sx,sy,gx,gy;
bool chk=0;
bool used[210][210];
char in[110][110];
void make_c(int Ax,int Ay,int Bx,int By,int v){
    d[Ax][Ay].push_back((edge){Bx,By,v,d[Bx][By].size()});
    d[Bx][By].push_back((edge){Ax,Ay,0,d[Ax][Ay].size()-1});
}
int dfs(int nox,int noy,int v){
    if(nox==gx&&noy==gy) return v;
    used[nox][noy]=1;
    for(int i=0;i<d[nox][noy].size();i++){
        if(!used[d[nox][noy][i].tox][d[nox][noy][i].toy]&&d[nox][noy][i].cap>0){
            int val=dfs(d[nox][noy][i].tox,d[nox][noy][i].toy,min(d[nox][noy][i].cap,v));
            if(val>0){
                d[nox][noy][i].cap-=val;
                d[d[nox][noy][i].tox][d[nox][noy][i].toy][d[nox][noy][i].rev].cap+=val;
                return val;
            }
        }
    }
    return 0;
}
int flow(){
    int RE=0;
    while(1){
        memset(used,0,sizeof(used));
        int val=dfs(sx,sy,1e9);
        if(val<=0) return RE;
        RE+=val;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>in[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(in[i][j]=='K'&&(in[i-1][j]=='H'||in[i+1][j]=='H'||in[i][j-1]=='H'||in[i][j+1]=='H')){
            cout<<"-1";
            return 0;
        }
        if(in[i][j]=='.'){
            make_c(i,j,i+100,j+100,1);
            if(in[i-1][j]=='.'){
                make_c(100+i,100+j,i-1,j,1);
                make_c(99+i,100+j,i,j,1);
            }
            if(in[i][j-1]=='.'){
                make_c(100+i,100+j,i,j-1,1);
                make_c(100+i,99+j,i,j,1);
            }
        }
        else if(in[i][j]=='K'){
            if(in[i-1][j]=='.'){
                make_c(i,j,i-1,j,1);
                make_c(99+i,100+j,i,j,1);
            }
            if(in[i+1][j]=='.'){
                make_c(i,j,i+1,j,1);
                make_c(101+i,100+j,i,j,1);
            }
            if(in[i][j-1]=='.'){
                make_c(i,j,i,j-1,1);
                make_c(100+i,99+j,i,j,1);
            }
            if(in[i][j+1]=='.'){
                make_c(i,j,i,j+1,1);
                make_c(100+i,101+j,i,j,1);
            }
            sx=i; sy=j;
        }
        else if(in[i][j]=='H'){
            if(in[i-1][j]=='.') make_c(99+i,100+j,i,j,1);
            if(in[i+1][j]=='.') make_c(101+i,100+j,i,j,1);
            if(in[i][j-1]=='.') make_c(100+i,99+j,i,j,1);
            if(in[i][j+1]=='.') make_c(100+i,101+j,i,j,1);
            gx=i; gy=j;
        }
    }
    cout<<flow();
}
