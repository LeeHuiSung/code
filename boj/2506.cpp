#include <bits/stdc++.h>
using namespace std;
int n,tmp,anw;
bool temp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(temp) anw+=(++tmp);
        else tmp=0;
    }
    cout<<anw;
}
