#include<bits/stdc++.h>
using namespace std;
struct point{int x,y;};
int n,m;
char in[1010][1010];
int memo[1010][1010];
point rabbit;
int f(int nox,int noy){
    if(nox>m) return -1;
    if(memo[noy][nox]!=-1e9) return memo[noy][nox];
    int RE=-1,tmp;
    if(in[noy][nox]=='O') RE=0;
    for(int i=-1;i<=1;i++){
        if(noy+i<=n&&1<=noy+i&&in[noy+i][nox+1]!='#'){
            tmp=f(nox+1,noy+i);
            if(tmp!=-1){
                if(in[noy][nox]=='C') tmp++;
                RE=max(RE,tmp);
            }
        }
    }
    return memo[noy][nox]=RE;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        scanf(" %c",&in[i][j]);
        memo[i][j]=-1e9;
        if(in[i][j]=='R') rabbit=(point){j,i};
    }
    cout<<f(rabbit.x,rabbit.y);
}
