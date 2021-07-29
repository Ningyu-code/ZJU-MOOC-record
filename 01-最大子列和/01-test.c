#include<stdio.h>
int seqsum(int a[],int n);
int main(){
    int a[100000],n,i;
    int maxseqsum;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    maxseqsum=seqsum(a,n);
    printf("%d",maxseqsum);
    return 0;
}

int seqsum(int a[],int n){
    int thisseq=0,maxseq=0;
    int i;
    for(i=0;i<n;i++){
        thisseq+=a[i];
        if(thisseq<=0) thisseq=0;
        else{
            if(thisseq>maxseq) maxseq=thisseq;
        }
    }
    return maxseq;
}

