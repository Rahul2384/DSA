#include<stdio.h>
typedef struct 
{
    int row;
    int col;
    int value;
}sparse;

int main(){
    int n,i,j,cb;
    scanf("%d",&n);
    sparse a[n],b[n];
    for(i=0;i<=n;i++){
        scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);
    }
    int rt[a[0].col], sp[a[0].col];
    for(i=0;i<a[0].col;i++) rt[i] = 0;
    for(i=1;i<=a[0].value;i++){
        rt[a[i].col]++;
    }sp[0]=1;
    for(i=1;i<a[0].col;i++)
        sp[i] = sp[i-1]+rt[i-1];
    for(i=1;i<=a[0].value;i++){
        j = sp[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
    for(i=0;i<=n;i++){
        printf("%d %d %d",b[i].row,b[i].col,b[i].value);
        printf("\n");
    }
    return 0;
}