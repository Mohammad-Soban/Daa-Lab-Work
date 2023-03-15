#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void MergeFunc(int arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[q + j + 1];
    }

    L[n1] = 2147483647;
    R[n2] = 2147483647;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int arr[], int p, int r){
    if(p<r){
        int q = floor((p+r)/2);

        MergeSort(arr, p, q); 
        MergeSort(arr, q+1, r);
        MergeFunc(arr, p, q, r);
    }
}

int main()
{
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        printf("Enter the value at index %d:- ", i);
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, len-1);

    for (int j = 0; j < len; j++)
    {
        printf("%d -- ", arr[j]);
    }
    
    return 0;
}
