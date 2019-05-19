#include<bits/stdc++.h>
using namespace std;
int n;
bool chk=1;
string in;
int main(){
    cin>>n;
    cin>>in;
    for(int i=1;i<in.size();i++) if(in[i-1]==in[i]) chk=0;
    if(chk) cout<<"Yes";
    else cout<<"No";
}
