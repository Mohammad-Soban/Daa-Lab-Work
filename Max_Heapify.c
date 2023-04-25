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


/* Algorithm for Heap Sort --- 

Heap_external_Maximum(array){

if(array.heap_size < 1){
    error "heap underflow"
}

else{
    max = array[0];
    arr[0] = arr[array.heap_size - 1];
    array.heap_size = array.heap_size - 1;

    Max_Heapify(array, 0);
    return max;
}

}*/


// Heap Sort Algorithm
/*
Heap_Sort(int arr){
    Build_Max_Heap(arr);
    for i = arr.length to 1
    {
        exchange arr[0] with arr[i]
        arr.heap_size = arr.heap_size - 1
        Max_Heapify(arr, 0)
    }
}
*/ 



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

int Heap_Extract_Max(int arr[], int length){
    int max = arr[0];
    arr[0] = arr[length - 1];
    length = length - 1;
    Max_Heapify(arr, 0, length);
    return max;
}

// Function to perform Heap Sort.
void Heap_Sort(int array[], int length){
    Build_Max_Heap(array, length);
    for (int i = length - 1; i >= 1; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        length = length - 1;
        Max_Heapify(array, 0, length);
    }   
}

void InsertElement(int element, int arr[]){
    int length = sizeof(arr)/sizeof(arr[0]);
    arr[length] = element;
    Build_Max_Heap(arr, length);
}


int main()
{
    int length;
    printf("Enter the number of elements you want to enter");
    scanf("%d", &length);
    int arr[length];

    for (int i = 0; i < length; i++)
    {
        printf("Enter the %d element of the array:- ", i);
        scanf("%d", &arr[i]);
    }
      
    Heap_Sort(arr, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d - ", arr[i]);
    }

    return 0;
}
