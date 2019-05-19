#include<bits/stdc++.h>
using namespace std;
int n,k;
bool used[160];
int in[160],dis[160];
queue<int> a;
int main(){
    cin>>n>>k; k++;
    for(int i=1;i<=n;i++){
        cin>>in[i];
        in[i]++;
    }
    a.push(1);
    used[1]=1;
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    while(!a.empty()){
        int tmp=a.front(); a.pop();
        if(!used[in[tmp]]){
            used[in[tmp]]=1;
            a.push(in[tmp]);
            dis[in[tmp]]=dis[tmp]+1;
        }
    }
    cout<<dis[k];
}
