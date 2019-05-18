#include <bits/stdc++.h>
using namespace std;
int len,anw,T=3;
string in;
int main(){
    while(T--){
        cin>>in;
        anw=0;
        for(int i=0;i<in.size();i++){
            if(i==0||in[i-1]!=in[i]) len=0;
            len++;
            anw=max(anw,len);
        }
        cout<<anw<<endl;
    }
}
