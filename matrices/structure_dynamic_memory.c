#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    char name[30];
    int rno;
}student;
int main()
{
    int n=5;
    student *s = (student *)malloc(n*sizeof(student));
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter name\n");
        scanf("%s",(s+i)->name);
        printf("Enter rollno\n");
        scanf("%d",&(s+i)->rno);
    }
    for(i=0;i<n;i++)
    {
        printf("name: %s\n",*(s+i)->name);
        printf("rollno: %d\n",s[i].rno);
    }
    return 0;
}