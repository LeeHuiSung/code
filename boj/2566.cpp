#include<bits/stdc++.h>
using namespace std;
int n,m,anw,tmp;
int main(){
    for(int i=1;i<=9;i++) for(int j=1;j<=9;j++){
        cin>>tmp;
        if(anw<tmp){
            anw=tmp;
            n=i;
            m=j;
        }
    }
    cout<<anw<<endl<<n<<" "<<m;
}
