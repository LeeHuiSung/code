#include <bits/stdc++.h>
using namespace std;
int n,tmp;
long long anw;
long long seg[2000000];
int a[1000010],b[500010];
long long out(int now,int s,int e,int gos,int goe){
	if(gos<=s&&e<=goe) return seg[now];
	if(e<gos||goe<s) return 0;
	return out(2*now,s,(s+e)/2,gos,goe)+out(2*now+1,(s+e)/2+1,e,gos,goe);
}
long long up(int now,int s,int e,int idx){
	if(s==e&&s==idx) return seg[now]=1;
	if(idx<s||e<idx) return seg[now];
	return seg[now]=up(2*now,s,(s+e)/2,idx)+up(2*now+1,(s+e)/2+1,e,idx);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
		a[tmp]=i;
	}
	for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
		b[i]=a[tmp];
	}
	for(int i=1;i<=n;i++){
		anw+=out(1,1,n,b[i]+1,n);
		up(1,1,n,b[i]);
	}
	cout<<anw;
}
