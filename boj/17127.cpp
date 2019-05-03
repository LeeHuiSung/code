#include<bits/stdc++.h>
using namespace std;
int n,anw;
int fi=1,se=1,th=1,fo=1;
int in[15];
int mul[15];
int main(){
    cin>>n;
    mul[0]=1;
    for(int i=1;i<=n;i++){
        cin>>in[i];
        mul[i]=mul[i-1]*in[i];
    }
    for(int i=1;i<=n-3;i++){
        fi*=in[i];
        se=1;
        for(int j=i+1;j<=n-2;j++){
            se*=in[j];
            th=1;
            for(int k=j+1;k<=n-1;k++){
                th*=in[k];
                fo=mul[n]/mul[k];
                anw=max(anw,fi+se+th+fo);
            }
        }
    }
    cout<<anw;
}
