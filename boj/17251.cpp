#include <iostream>
#include <algorithm>
using namespace std;
int n;
int in[1000010],red[1000010],blue[1000010];
int rcnt,bcnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&in[i]);
	for(int i=1;i<=n;i++) red[i]=max(red[i-1],in[i]);
	for(int i=n;i>=1;i--) blue[i]=max(blue[i+1],in[i]);
	for(int i=1;i<n;i++){
		if(red[i]>blue[i+1]) rcnt++;
		else if(blue[i+1]>red[i]) bcnt++;
	}
	if(rcnt==bcnt) cout<<"X";
	else if(rcnt>bcnt) cout<<"R";
	else cout<<"B";
}
