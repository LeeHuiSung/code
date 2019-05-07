#include<bits/stdc++.h>
using namespace std;
string in[110];
int v[110];
int n;
string m,anw;
int anf=-1,ans=-1;
int main(){
    cin>>m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i]>>v[i];
    for(int i=1;i<=n;i++){
        int gyup=0;
        for(int j=0;j<in[i].size();j++) if(m[gyup]==in[i][j]) gyup++;
        if(gyup==m.size()){
            if((anf==-1&&ans==-1)||(v[i]*ans>anf*(in[i].size()-gyup))){
                anf=v[i]; ans=in[i].size()-gyup;
                anw=in[i];
            }
        }
    }
    if(anf==-1&&ans==-1) cout<<"No Jam";
    else cout<<anw;
}
