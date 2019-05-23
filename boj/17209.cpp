#include<bits/stdc++.h>
using namespace std;
int n,tmp,anw,cnt,ocnt;
bool adj[2010][2010],used[2010],chk[2010];
queue<int> a;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        scanf("%1d",&tmp);
        adj[i][j]|=tmp;
        adj[j][i]|=tmp;
    }
    for(int i=1;i<=n;i++) if(!used[i]){
        used[i]=1;
        a.push(i);
        cnt=ocnt=0;
        chk[i]=0;
        while(!a.empty()){
            cnt++;
            tmp=a.front(); a.pop();
            for(int j=1;j<=n;j++) if(adj[tmp][j]&&!used[j]){
                used[j]=1;
                a.push(j);
                chk[j]=!chk[tmp];
                if(chk[j]) ocnt++;
            }
        }
        anw+=max(ocnt,cnt-ocnt);
    }
    cout<<anw;
}
