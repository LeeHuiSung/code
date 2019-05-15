#include<bits/stdc++.h>
using namespace std;
int ax,ay,dx,dy;
int memo[55][55][55][55];
int f(int sx,int sy,int ex,int ey){
    if(dx<sx&&ey<=dy) return 0;
    if(memo[sx][sy][ex][ey]!=-1) return memo[sx][sy][ex][ey];
    if(sx==dx+1&&sy<=dy){
        if(dy<ey) return memo[sx][sy][ex][ey]=f(sx,dy+1,ex,ey);
        return 0;
    }
    else if(ey==dy&&sx<=dx&&dx<ex) return memo[sx][sy][ex][ey]=f(sx,sy,dx,ey);
    else if((ex<=dx||dy<sy)&&(ex-sx==ey-sy)) return 1;
    else{
        int RE=1e9;
        for(int i=sx;i<ex;i++) RE=min(RE,f(sx,sy,i,ey)+f(i+1,sy,ex,ey));
        for(int i=sy;i<ey;i++) RE=min(RE,f(sx,sy,ex,i)+f(sx,i+1,ex,ey));
        return memo[sx][sy][ex][ey]=RE;
    }
}
int main(){
    cin>>ay>>ax>>dy>>dx;
    dx = ax-dx;
    memset(memo,-1,sizeof(memo));
    cout<<f(1,1,ax,ay);
}
