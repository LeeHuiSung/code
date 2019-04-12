#include<bits/stdc++.h>
using namespace std;
struct opt{int idx; long long v;};
long long dp[200010],anw=-1e18;
int n,d;
int in[200010];
deque<opt> a;
int main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>in[i];
    for(int i=1;i<=n;i++){
        while(!a.empty()&&i-a.front().idx>d) a.pop_front();
        if(a.empty()) dp[i]=in[i];
        else dp[i]=a.front().v+in[i];
        if(dp[i]>0){
            while(!a.empty()&&a.back().v<=dp[i]) a.pop_back();
            a.push_back((opt){i,dp[i]});
        }
        anw=max(anw,dp[i]);
    }
    cout<<anw;
}
