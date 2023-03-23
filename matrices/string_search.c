#include<stdio.h>
void main(){
    char s[20],p[20];
    scanf("%s",s);
    int i,c=0;
    getchar();
    printf("Enter pattern:");
    scanf("%s",p);
    for(i=0;s[i+1]!='\0';i++){
        if(s[i]=='i' && s[i+1]=='s') printf("Found"); c=1;
    }
    if (c==0) printf("Not Found");
}