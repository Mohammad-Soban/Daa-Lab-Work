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

    InsertElement(10, arr);

    Heap_Sort(arr, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d - ", arr[i]);
    }

    return 0;
}
