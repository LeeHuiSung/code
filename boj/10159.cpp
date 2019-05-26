#include<bits/stdc++.h>
using namespace std;
int n,m,tmpf,tmps,cnt[110];
vector<int> h[110],l[110];
bool used[110][110];
queue<int> a;
int main(){
    cin>>n>>m;
    while(m--){
        cin>>tmpf>>tmps;
        h[tmpf].push_back(tmps);
        l[tmps].push_back(tmpf);
    }
    for(int i=1;i<=n;i++){
        used[i][i]=1;
        a.push(i);
        while(!a.empty()){
            int tmp=a.front(); a.pop();
            for(int j=0;j<h[tmp].size();j++) if(!used[i][h[tmp][j]]){
                used[i][h[tmp][j]]=1;
                a.push(h[tmp][j]);
            }
        }
        a.push(i);
        while(!a.empty()){
            int tmp=a.front(); a.pop();
            for(int j=0;j<l[tmp].size();j++) if(!used[i][l[tmp][j]]){
                used[i][l[tmp][j]]=1;
                a.push(l[tmp][j]);
            }
        }
        for(int j=1;j<=n;j++) if(used[i][j]) cnt[i]++;
    }
    for(int i=1;i<=n;i++) printf("%d\n",n-cnt[i]);
}
