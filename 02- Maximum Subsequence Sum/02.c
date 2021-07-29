#include<stdio.h>
int seqsum(int a[],int n,int *j1,int *j2); 
int main(){
    int a[100000],n,i;
    int maxseqsum;
    int *j1,*j2;
    int head=0,end=0;
    j1=&head;                                       //最大子列的首尾
    j2=&end;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    maxseqsum=seqsum(a,n,j1,j2);
    printf("%d %d %d",maxseqsum,a[head],a[end]);
    return 0;
}

int seqsum(int a[],int n,int *j1,int *j2){
    int thisseq=0,maxseq=0;
    int i,head=0,end=0;
    int fu=0,fu2=0,aim;
    for(i=0;i<n;i++){
        if(a[i]>=0){
            fu=1;
            if(a[i]==0) aim=i;
        }
        if(a[i]>0) fu2=1;
    }
    if(fu==0){
        *j1=0;
        *j2=n-1;
        return maxseq;
    }
    if(fu2==0){
        *j1=aim;
        *j2=aim;
        return maxseq;
    }
    for(i=0;i<n;i++){                               //按顺序过一遍
        thisseq+=a[i];                              //子列每次+最新的元素
        if(thisseq>=0){
            end=i;
            if(thisseq>maxseq){
                maxseq=thisseq;
                *j1=head;
                *j2=end;
            }
        }
        else{
            thisseq=0;
            head=i+1;
        }
    }
    return maxseq;
}
