#include<bits/stdc++.h>
using namespace std;
struct point{int x,y;};
int T;
int w,h,dcnt;
int in[25][25];
int dis[15][25][25];
int dist[15][15];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bool used[15][25][25];
int memo[15][4100];
point dirt[15];
queue<point> a;
int f(int now,int bit){
    if(bit==((1<<(dcnt))-1)) return 0;
    if(memo[now][bit]!=-1) return memo[now][bit];
    int RE=1e9;
    for(int i=1;i<dcnt;i++){
        if((bit)&(1<<i));
        else{
            int tmp=f(i,bit|(1<<i));
            if(tmp!=1e9) tmp+=dist[now][i];
            if(dist[now][i]==1e9) tmp=1e9;
            RE=min(RE,tmp);
        }
    }
    return memo[now][bit]=RE;
}
int main(){
    while(1){
        cin>>h>>w;
        if(w==0&&h==0) break;
        dcnt=1;
        for(int i=0;i<=12;i++) for(int j=1;j<=20;j++) for(int l=1;l<=20;l++) dis[i][j][l]=1e9;
        memset(memo,-1,sizeof(memo));
        memset(used,0,sizeof(used));
        for(int i=1;i<=w;i++) for(int j=1;j<=h;j++){
            scanf(" %c",&in[i][j]);
            if(in[i][j]=='o'){
                dirt[0]=(point){i,j};
            }
            else if(in[i][j]=='*'){
                dirt[dcnt++]=(point){i,j};
            }
        }
        for(int i=0;i<dcnt;i++){
            a.push(dirt[i]);
            dis[i][dirt[i].x][dirt[i].y]=0;
            used[i][dirt[i].x][dirt[i].y]=1;
            while(!a.empty()){
                point temp=a.front(); a.pop();
                for(int j=0;j<4;j++){
                    if(temp.x+dx[j]<1||temp.x+dx[j]>w||temp.y+dy[j]<1||temp.y+dy[j]>h||in[temp.x+dx[j]][temp.y+dy[j]]=='x'||used[i][temp.x+dx[j]][temp.y+dy[j]]);
                    else{
                        dis[i][temp.x+dx[j]][temp.y+dy[j]]=dis[i][temp.x][temp.y]+1;
                        used[i][temp.x+dx[j]][dy[j]+temp.y]=1;
                        a.push((point){temp.x+dx[j],temp.y+dy[j]});
                    }
                }
            }
            for(int j=0;j<dcnt;j++) dist[i][j]=dis[i][dirt[j].x][dirt[j].y];
        }
        int anw=f(0,1);
        if(anw==1e9) printf("-1\n");
        else printf("%d\n",anw);
    }
}
