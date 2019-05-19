#include<bits/stdc++.h>
using namespace std;
int dp[80010];
int T,n;
int main(){
    cin>>T;
    for(int i=1;i<=80000;i++){
        dp[i]=dp[i-1];
        if(i%3==0||i%7==0) dp[i]+=i;
    }
    while(T--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
}
