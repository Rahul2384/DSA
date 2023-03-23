#include<stdio.h>
int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int max = n1>n2?n1:n2;
    int i,j,a[max],b[max],c[max];
    for(i=max;i>=0;i--){
        printf("x^%d:",i);
        scanf("%d",&a[i]);
    }
    for(i=max;i>=0;i--){
        printf("x^%d:",i);
        scanf("%d",&b[i]);
    }
    for(i=max;i>=0;i--){
        c[i]=a[i]+b[i];
    }
    for(i=0;i<=max;i++){
        printf("%dx^%d+",c[i],i);
    }
    return 0;
}