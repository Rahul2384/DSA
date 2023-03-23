#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int value;
} sparse;

int main()
{
    int n, i, j, cb;
    printf("Enter the no.of non zero values\n");
    scanf("%d", &n);
    sparse a[n], b[n];
    for (i = 0; i <= n; i++)
    {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }
    b[0].value = a[0].value;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    
    if (n > 0)
    {
        cb = 1;
        for (i = 0; i < a[0].col; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[j].col == i)
                {
                    b[cb].row = a[j].col;
                    b[cb].col = a[j].row;
                    b[cb].value = a[j].value;
                    cb++;
                }
            }
        }
    }
    for (i = 0; i <= n; i++)
    {
        printf("%d %d %d", b[i].row, b[i].col, b[i].value);
        printf("\n");
    }

    // no.of non zero values in 3rd row.
    int count = 0;
    for ( i = 1; i <= n; i++)
    {
        if(a[i].row == 2) count++;
    }
    printf("%d",count);
    
    return 0;
}