#include<bits/stdc++.h>
using namespace std;
struct data{int pal,v;};
int T,n,m,in[15];
bool used[5010][500];
queue<data> a;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++) cin>>in[i];
        memset(used,0,sizeof(used));
        a.push((data){0,0});
        used[0][0]=1;
        int anw=-1;
        while(!a.empty()){
            data tmp=a.front(); a.pop();
            for(int i=1;i<=m;i++){
                if(tmp.v+in[i]<=500&&tmp.pal+tmp.v+in[i]<=n&&!used[tmp.pal+tmp.v+in[i]][tmp.v+in[i]]){
                    a.push((data){tmp.pal+tmp.v+in[i],tmp.v+in[i]});
                    used[tmp.pal+tmp.v+in[i]][tmp.v+in[i]]=1;
                }
            }
        }
        for(int i=0;i<=500;i++) if(used[n][i]) anw=i;
        printf("%d\n",anw);
    }
}
