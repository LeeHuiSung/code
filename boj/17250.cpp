#include <iostream>
#include<cstdio>
using namespace std;
int n,m;
int tmf,tms;
int ver[100010],ran[100010],par[100010];
int fi(int X){return (par[X]==X)?X:fi(par[X]);}
void un(int X,int Y){
	X=fi(X);
	Y=fi(Y);
	if(ran[Y]>ran[X]) par[X]=Y;
	else{
		par[Y]=X;
		if(ran[X]==ran[Y]) ran[X]++;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&ver[i]);
		par[i]=i;
	}
	while(m--){
		scanf("%d %d",&tmf,&tms);
		if(fi(tmf)==fi(tms)) printf("%d\n",ver[fi(tmf)]);
		else{
			int temp=ver[fi(tmf)]+ver[fi(tms)];
			un(tmf,tms);
			ver[fi(tmf)]=temp;
			printf("%d\n",temp);
		}
	}
}
