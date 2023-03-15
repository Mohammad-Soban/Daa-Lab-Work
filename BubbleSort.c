#include <stdio.h>

void BubbleSort(int arr[], int len){
	int max, index, temp;
	for(int i = 0; i< len; i++){
		for (int j = 0; j<(len-i-1); j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= temp;
			}
		}		
	}
}

int main(){
	int len;
	printf("Enter the length of the array: ");
    scanf("%d", &len);

	int arr[len];
	for(int i=0; i<len; i++){
		printf("Enter the value at index %d ", i);
		scanf("%d", &arr[i]);
	}
	
	BubbleSort(arr, len);

	for(int i=0; i<len; i++){
		printf("%d -- ",arr[i]);
	}

	return 0;
}