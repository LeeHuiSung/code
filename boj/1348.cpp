#include<bits/stdc++.h>
using namespace std;
struct point{int x,y;};
struct edge{int to,cap,rev;};
int n,m;
int lb=0,ub=250000;
int ccnt,pcnt;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char in[55][55];
point car[110],park[110];
int dist[110][110];
int dis[110][55][55];
bool used[110][55][55];
bool visit[220];
queue<point> a;
void make_c(vector<edge> *d,int A,int B,int v){
    d[A].push_back((edge){B,v,d[B].size()});
    d[B].push_back((edge){A,0,d[A].size()-1});
}
int dfs(vector<edge> *d,int now,int goal,int v){
    if(now==goal) return v;
    visit[now]=1;
    for(int i=0;i<d[now].size();i++){
        if(!visit[d[now][i].to]&&d[now][i].cap>0){
            int val=dfs(d,d[now][i].to,goal,min(v,d[now][i].cap));
            if(val>0){
                d[now][i].cap-=val;
                d[d[now][i].to][d[now][i].rev].cap+=val;
                return val;
            }
        }
    }
    return 0;
}
int flow(vector<edge> *d){
    int RE=0;
    while(1){
        memset(visit,0,sizeof(visit));
        int val=dfs(d,0,205,1e9);
        if(val<=0) return RE;
        RE+=val;
    }
}
bool c(int t){
    vector<edge> da[220];
    for(int i=0;i<ccnt;i++) for(int j=0;j<pcnt;j++) if(dist[i][j]<=t) make_c(da,i+1,100+j+1,1);
    for(int i=0;i<ccnt;i++) make_c(da,0,i+1,1);
    for(int j=0;j<pcnt;j++) make_c(da,100+j+1,205,1);
    int val=flow(da);
    return val==ccnt;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        cin>>in[i][j];
        if(in[i][j]=='C') car[ccnt++]=(point){i,j};
        else if(in[i][j]=='P') park[pcnt++]=(point){i,j};
    }
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<ccnt;i++){
        used[i][car[i].x][car[i].y]=1;
        a.push(car[i]);
        dis[i][car[i].x][car[i].y]=0;
        while(!a.empty()){
            point tmp=a.front(); a.pop();
            for(int j=0;j<4;j++) if((0<tmp.x+dx[j]&&tmp.x+dx[j]<=n&&0<tmp.y+dy[j]&&tmp.y+dy[j]<=m)&&(in[tmp.x+dx[j]][tmp.y+dy[j]]!='X')&&!used[i][tmp.x+dx[j]][tmp.y+dy[j]]){
                dis[i][tmp.x+dx[j]][tmp.y+dy[j]]=dis[i][tmp.x][tmp.y]+1;
                used[i][tmp.x+dx[j]][tmp.y+dy[j]]=1;
                a.push((point){tmp.x+dx[j],tmp.y+dy[j]});
            }
        }
        for(int j=0;j<pcnt;j++) dist[i][j]=dis[i][park[j].x][park[j].y];
    }
    for(int i=0;i<ccnt;i++){
        for(int j=0;j<pcnt;j++) if(dist[i][j]==-1) dist[i][j]=1e9;
    }
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(c(mid)) ub=mid;
        else lb=mid;
    }
    if(c(lb)) cout<<lb;
    else if(c(ub)) cout<<ub;
    else cout<<"-1";
}
