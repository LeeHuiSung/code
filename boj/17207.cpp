#include<bits/stdc++.h>
using namespace std;
struct data{int v,idx;};
int nani[8][8];
int tim[8][8];
int rea[8][8];
data anw[8];
string out[8];
bool cmp(data A,data B){
    if(A.v==B.v) return A.idx>B.idx;
    return A.v<B.v;
}
int main(){
    for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) cin>>nani[i][j];
    for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) cin>>tim[i][j];
    for(int i=1;i<=5;i++){
        anw[i].idx=i;
        for(int j=1;j<=5;j++){
            for(int k=1;k<=5;k++) rea[i][j]+=(nani[i][k]*tim[k][j]);
            anw[i].v+=rea[i][j];
        }
    }
    out[1]="Inseo";
    out[2]="Junsuk";
    out[3]="Jungwoo";
    out[4]="Jinwoo";
    out[5]="Youngki";
    sort(anw+1,anw+6,cmp);
    cout<<out[anw[1].idx];
}
