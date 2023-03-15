#include <stdio.h>

void InsertionSort(int arr[], int length){
    for (int j = 1; j <= length; j++)
    {
        int key = arr[j];
        int i = j - 1;

        // Insert arr[j] into the sorted sequence arr[1..j-1]
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }

        arr[i + 1] = key;
    }
    
}

int main()
{
    int len;
    printf("Enter the size of the array\n");
    scanf("%d", &len);

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        printf("Enter the Element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    InsertionSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}