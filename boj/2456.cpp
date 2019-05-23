#include<bits/stdc++.h>
using namespace std;
struct data{int v,tcnt,scnt,idx;};
int n,tmf,tms,tmt;
data in[5];
bool cmp(data A,data B){
    if(A.v==B.v){
        if(A.tcnt==B.tcnt) return A.scnt>B.scnt;
        return A.tcnt>B.tcnt;
    }
    return A.v>B.v;
}
int main(){
    cin>>n;
    in[1].idx=1; in[2].idx=2; in[3].idx=3;
    while(n--){
        cin>>tmf>>tms>>tmt;
        in[1].v+=tmf;
        in[2].v+=tms;
        in[3].v+=tmt;
        if(tmf==3) in[1].tcnt++;
        else if(tms==3) in[2].tcnt++;
        else in[3].tcnt++;
        if(tmf==2) in[1].scnt++;
        else if(tms==2) in[2].scnt++;
        else in[3].scnt++;
    }
    sort(in+1,in+4,cmp);
    if(in[1].v==in[2].v&&in[1].tcnt==in[2].tcnt&&in[1].scnt==in[2].scnt) printf("0 %d",in[1].v);
    else printf("%d %d",in[1].idx,in[1].v);
}
