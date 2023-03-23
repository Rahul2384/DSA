#include<stdio.h>
typedef struct 
{
    int x;
    int y;
}point;
int main()
{
    int *p;
    point p1;
    printf("Enter the coordinates\n");
    scanf("%d%d",&p1.x,&p1.y);
    // p = &p1;
    // printf("%d %d",p->x,p->y);
    return 0;
}