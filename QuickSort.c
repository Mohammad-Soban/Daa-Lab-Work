#include <stdio.h>

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (a[j] <= x)
        {
            i = i + 1;
            
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;

    return i + 1;
}


void quicksort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}



int main()
{
    int a[] = { 2,5,15,45,4,215,85,35 };
    int n = 8;

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}