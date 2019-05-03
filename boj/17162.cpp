#include<bits/stdc++.h>
using namespace std;
int q,mod,n,type;
stack<int> idx;
stack<int> cnt[110];
int main(){
    cin>>q>>mod;
    while(q--){
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&n);
            n=n%mod;
            cnt[n].push(idx.size()+1);
            idx.push(n);
        }
        else if(type==2){
            if(!idx.empty()){
                cnt[idx.top()].pop();
                idx.pop();
            }
        }
        else{
            bool chk=1;
            int anw=idx.size();
            for(int i=0;i<mod;i++){
                if(cnt[i].empty()) chk=0;
                else anw=min(cnt[i].top(),anw);
            }
            if(chk) printf("%d\n",idx.size()-anw+1);
            else printf("-1\n");
        }
    }
}
