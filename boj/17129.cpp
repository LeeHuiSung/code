#include<bits/stdc++.h>
using namespace std;
struct point{int x,y;};
int n,m,anw=-1;
string tt[3010];
int in[3010][3010];
bool used[3010][3010];
int dis[3010][3010];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
queue<point> a,b;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>tt[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        in[i][j]=tt[i][j-1]-'0';
        if(in[i][j]==2){
            a.push((point){j,i});
            used[i][j]=1;
            dis[i][j]=0;
        }
        else if(in[i][j]==3||in[i][j]==4||in[i][j]==5) b.push((point){j,i});
    }
    while(!a.empty()){
        point tmp=a.front(); a.pop();
        for(int i=0;i<4;i++){
            int nx=tmp.x+dx[i];
            int ny=tmp.y+dy[i];
            if(1>nx||1>ny||n<ny||m<nx||in[ny][nx]==1||used[ny][nx]);
            else{
                used[ny][nx]=1;
                dis[ny][nx]=1+dis[tmp.y][tmp.x];
                a.push((point){nx,ny});
            }
        }
    }
    while(!b.empty()){
        int temp=dis[b.front().y][b.front().x];
        if(temp!=0){
            if(anw==-1) anw=temp;
            else anw=min(anw,temp);
        }
        b.pop();
    }
    if(anw==-1) cout<<"NIE";
    else{
        printf("TAK\n");
        cout<<anw;
    }
}
