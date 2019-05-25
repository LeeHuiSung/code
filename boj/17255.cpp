#include<bits/stdc++.h>
using namespace std;
struct opt{string v;};
bool operator<(opt A,opt B){return A.v.size()<B.v.size();}
string n;
int anw;
map<string,int> d;
priority_queue<opt> a;
int main(){
    cin>>n;
    a.push((opt){n});
    d[n]=1;
    while(!a.empty()){
        string tmp=a.top().v; a.pop();
        if(tmp.size()==1) anw+=d[tmp];
        else{
            string tmf,tms; tmf.clear(); tms.clear();
            for(int i=0;i<tmp.size()-1;i++) tmf.append(1,tmp[i]);
            for(int i=1;i<tmp.size();i++) tms.append(1,tmp[i]);
            if(d.find(tmf)==d.end()){
                d[tmf]=d[tmp];
                a.push((opt){tmf});
            }
            else d[tmf]+=d[tmp];
            if(tmf!=tms){
                if(d.find(tms)==d.end()){
                    d[tms]=d[tmp];
                    a.push((opt){tms});
                }
                else d[tms]+=d[tmp];
            }
        }
    }
    cout<<anw;
}
