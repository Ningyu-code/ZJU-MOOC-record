#include<stdio.h>
#define N 100000
void main(){
	int K,n,a[N],i,Sum=0,ThisSum=0;
	scanf("%d",&K);
	for(n=0;n<=K-1;n++){
		scanf("%d",&a[n]);
	}
	for(i=0;i<=K-1;i++){
		ThisSum+=a[i];
		if(ThisSum<=0) ThisSum = 0;
		else{
			if(ThisSum > Sum) Sum = ThisSum;
		}
	}
	printf("%d",Sum);
}
