// Algorithm for max heapify

/*
Max_Heapify(A, i)
{
    l = 2i
    r = 2i + 1 
    if l <= A.heap_size and A[l] > A[i]
    {
        largest = l
    } else {
        largest = i
    }

    if r <= A.heap_size and A[r] > A[largest]
    {
        largest = r
    }

    if largest != i
    {
        exchange A[i] with A[largest]
        Max_Heapify(A, largest)
    }

}
*/


// Algorith for Building a max heap

/*
Build_Max_Heap(A)
{
    A.heap_size = A.length
    for i = floor(A.length/2) to 0
    {
        Max_Heapify(A, i)
    }
}
*/

// C language Code for performing Max_Heapify and Build_Max_Heap...


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Max_Heapify(int arr[], int i, int length){
    int l = (2*i) + 1;
    int r = (2*i) + 2;
    int largest;
    
    if (l < length && arr[l] > arr[i])
    {
        largest = l;
    } else {
        largest = i;
    }

    if (r < length && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        Max_Heapify(arr, largest, length);
    }

}

void Build_Max_Heap(int arr[], int length){
    int heap_size = length;

    for (int i = floor(length/2); i >= 0; i--)
    {
        Max_Heapify(arr, i, length);
    }
    
}

int main()
{
    int arr[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = sizeof(arr)/sizeof(arr[0]);

    Build_Max_Heap(arr, length);

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}