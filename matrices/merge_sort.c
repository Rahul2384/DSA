#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, m;
    printf("Enter m \n");
    scanf("%d", &m);
    printf("Enter n \n");
    scanf("%d", &n);
    int a[m], b[n], i, j;
    printf("Enter a elements\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter b elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    int k = 0, l = m + n;
    i = 0, j = 0;
    int c[l];
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    for (i = 0; i < l; i++)
    {
        printf("%d\t", c[i]);
    }
    return 0;
}
