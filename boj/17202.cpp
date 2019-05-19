#include<bits/stdc++.h>
using namespace std;
int tempo,T=14;
int tmp[20],temp[20];
void same(){
    for(int i=1;i<=16;i++){
        tmp[i]=temp[i];
        temp[i]=0;
    }
}
int main(){
    for(int i=1;i<=8;i++){
        scanf("%01d",&tempo);
        tmp[2*i-1]=tempo;
    }
    for(int i=1;i<=8;i++){
        scanf("%01d",&tempo);
        tmp[2*i]=tempo;
    }
    while(T--){
        for(int i=1;i<=2+T;i++) temp[i]=(tmp[i+1]+tmp[i])%10;
        same();
    }
    printf("%d%d",tmp[1],tmp[2]);
}
