
#include<stdio.h>
int main()
{
    int n,i,j,e;
    printf("Enter the order of the square matrix\n");
    scanf("%d",&n);
    int no = ((n*(n+1))/2);
    int a[no],k=0;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if(i>=j)
            {
                printf("Enter the element\n");
                scanf("%d",&e);
                a[k] = e;
                k++;
            }
            
        }
        
    }
    
    // for(i=0;i<k;i++){
    //     printf("%d\t",a[i]);
    // }
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i<j)
            {
                printf("%d\t",0);
            }
            else
            {
                int l = (i*(i+1)/2)+j;
                printf("%d\t",a[l]);
            }
    
        }
        printf("\n");
        
    }
    
    return 0;
}



// #include<stdio.h>

// int main()
// {
//  	int i, j, rows, columns, a[10][10];

//  	printf("\n Please Enter Number of rows and columns  :  ");
//  	scanf("%d %d", &i, &j);

//  	printf("\n Please Enter the Matrix Elements \n");
//  	for(rows = 0; rows < i; rows++)
//   	{
//    		for(columns = 0;columns < j;columns++)
//     	{
//       		scanf("%d", &a[rows][columns]);
//     	}
//   	}

//  	for(rows = 0; rows < i; rows++)
//   	{
//   		printf("\n");
//    		for(columns = 0; columns < j; columns++)
//     	{
//     		if(rows >= columns)
//     		{
//     			printf("%d ", a[rows][columns]);
// 			}
// 			else
// 			{
// 				printf("0  ");
// 			}
//    	 	}
//   	}
//     return 0;
// }

// one d array
// #include <stdio.h>
// void store(int a[], int i, int j, int n)
// {
//     int ele = 1;
//     int  count = 1;
//     if (i > n - 1 || j > n - 1 || i < 0 || j < 0)
//     {
//         printf("Error");
//     }
//     else
//     {
//         if (i > j)
//         {
//             int loc = (i * (i + 1) / 2) + j;
//             a[loc] = ele;
//             //ele++;
//             count++;
//             printf("%d\t",a[loc]);
//         }
//         else
//         {
//             ele = 0;
//         }
//     }

    
//     // return ele;
// }
// int main()
// {
//     int n;

//     printf("Enter the order of the square matrix: ");
//     scanf("%d", &n);
//     int no = (n*(n+1))/2;
//     int a[no];
//     int i, j, e;
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             store(a, i, j, n);
//         }
//     }

//     for (i = 0; i < n; i++)
//     {
//         printf("%d\t", a[i]);
//     }
//     return 0;
// }
