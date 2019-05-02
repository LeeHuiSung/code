#include<bits/stdc++.h>
using namespace std;
int n,m,maxi;
int tmp,temp,temm;
int type,xf,xs,yf,ys;
int in[1030][1030];
int seg[4000][4000];
int ssinit(int con,int cham,int now,int s,int e){
    maxi=max(maxi,now);
    if(s==e) return seg[con][now]=in[cham][s];
    return seg[con][now]=ssinit(con,cham,2*now,s,(s+e)/2)+ssinit(con,cham,2*now+1,(s+e)/2+1,e);
}
void init(int now,int s,int e){
    if(s==e){
        ssinit(now,s,1,1,n);
        return;
    }
    init(2*now,s,(s+e)/2);
    init(2*now+1,(s+e)/2+1,e);
    for(int i=1;i<=maxi;i++) seg[now][i]=seg[2*now][i]+seg[2*now+1][i];
    return;
}
int sout(int con,int now,int s,int e){
    if(xf<=s&&e<=xs) return seg[con][now];
    if(e<xf||xs<s) return 0;
    return sout(con,2*now,s,(s+e)/2)+sout(con,2*now+1,(s+e)/2+1,e);
}
int fout(int now,int s,int e){
    if(yf<=s&&e<=ys) return sout(now,1,1,n);
    if(e<yf||ys<s) return 0;
    return fout(2*now,s,(s+e)/2)+fout(2*now+1,(s+e)/2+1,e);
}
int sup(int con,int cham,int now,int s,int e){
    if(s==e&&s==temp) return seg[con][now]=temm;
    if(s<=temp&&temp<=e) return seg[con][now]=sup(con,cham,2*now,s,(s+e)/2)+sup(con,cham,2*now+1,(s+e)/2+1,e);
    return seg[con][now];
}
void fup(int now,int s,int e){
    if(s==e&&s==tmp){
        sup(now,s,1,1,n);
        return;
    }
    if(s<=tmp&&tmp<=e){
        fup(2*now,s,(s+e)/2);
        fup(2*now+1,(s+e)/2+1,e);
        for(int i=1;i<=maxi;i++) seg[now][i]=seg[2*now][i]+seg[2*now+1][i];
    }
    return;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&in[i][j]);
    init(1,1,n);
    while(m--){
        /*for(int i=1;i<=maxi;i++){
            for(int j=1;j<=maxi;j++) printf("%02d ",seg[i][j]);
            printf("\n");
        }*/
        scanf("%d",&type);
        if(type){
            scanf("%d %d %d %d",&yf,&xf,&ys,&xs);
            printf("%d\n",fout(1,1,n));
        }
        else{
            scanf("%d %d %d",&tmp,&temp,&temm);
            fup(1,1,n);
        }
    }
}
