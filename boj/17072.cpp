#include<bits/stdc++.h>
using namespace std;
int n,m;
int R[410][410],G[410][410],B[410][410];
int f(int RED,int GREEN,int BLUE){return 2126*RED+7152*GREEN+722*BLUE;}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>R[i][j]>>G[i][j]>>B[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tmp = f(R[i][j],G[i][j],B[i][j]);
            if(tmp<510000) printf("#");
            else if(tmp<1020000) printf("o");
            else if(tmp<1530000) printf("+");
            else if(tmp<2040000) printf("-");
            else printf(".");
        }
        printf("\n");
    }
}
