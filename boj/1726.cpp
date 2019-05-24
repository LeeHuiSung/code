#include<bits/stdc++.h>
using namespace std;
struct point{int x,y,l;};
int n,m;
bool in[110][110];
int dis[110][110][6];
int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
point s,g;
queue<point> a;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        cin>>in[i][j];
        in[i][j]=!in[i][j];
    }
    cin>>s.y>>s.x>>s.l;
    cin>>g.y>>g.x>>g.l;
    a.push(s);
    memset(dis,-1,sizeof(dis));
    dis[s.y][s.x][s.l]=0;
    while(!a.empty()){
        point tmp=a.front(); a.pop();
        int dirpl,dirmi;
        if(tmp.l==1||tmp.l==2) dirpl=3,dirmi=4;
        else dirpl=1,dirmi=2;
        if(dis[tmp.y][tmp.x][dirmi]==-1){
            dis[tmp.y][tmp.x][dirmi]=dis[tmp.y][tmp.x][tmp.l]+1;
            a.push((point){tmp.x,tmp.y,dirmi});
        }
        if(dis[tmp.y][tmp.x][dirpl]==-1){
            dis[tmp.y][tmp.x][dirpl]=dis[tmp.y][tmp.x][tmp.l]+1;
            a.push((point){tmp.x,tmp.y,dirpl});
        }
        for(int i=1;i<=3;i++){
            point dtmp=tmp; dtmp.x+=(i*dx[dtmp.l]); dtmp.y+=(i*dy[dtmp.l]);
            if(1>dtmp.x||dtmp.x>m||1>dtmp.y||dtmp.y>n||dis[dtmp.y][dtmp.x][dtmp.l]!=-1);
            else if(!in[dtmp.y][dtmp.x]) break;
            else{
                dis[dtmp.y][dtmp.x][dtmp.l]=dis[tmp.y][tmp.x][dtmp.l]+1;
                a.push(dtmp);
            }
        }
    }
    cout<<dis[g.y][g.x][g.l];
}
