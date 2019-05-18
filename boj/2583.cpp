#include <bits/stdc++.h>
using namespace std;
struct point{int x,y;};
int n,m,k,sx,sy,ex,ey,cnt;
int anw[10010];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bool in[110][110];
queue<point> a;
int main(){
    cin>>n>>m>>k; //nÀÌ Çà
    while(k--){
        cin>>sx>>sy>>ex>>ey; //x±â ¾â
        for(int i=sy+1;i<=ey;i++) for(int j=sx+1;j<=ex;j++) in[i][j]=1;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!in[i][j]){
        a.push((point){j,i});
        in[i][j]=1;
        int tmp=0;
        while(!a.empty()){
            tmp++;
            point temp=a.front(); a.pop();
            for(int k=0;k<4;k++){
                point next=temp; next.x+=dx[k]; next.y+=dy[k];
                if(next.x<1||next.y<1||m<next.x||n<next.y||in[next.y][next.x]);
                else{
                    in[next.y][next.x]=1;
                    a.push(next);
                }
            }
        }
        anw[cnt++]=tmp;
    }
    sort(anw,anw+cnt);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++) printf("%d ",anw[i]);
}
