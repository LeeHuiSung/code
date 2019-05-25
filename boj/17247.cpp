#include<bits/stdc++.h>
using namespace std;
struct point{int x,y;};
int n,m;
int tmp,cnt;
point ones[5];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        cin>>tmp;
        if(tmp) ones[cnt++]=(point){i,j};
    }
    cout<<abs(ones[0].x-ones[1].x)+abs(ones[0].y-ones[1].y);
}
