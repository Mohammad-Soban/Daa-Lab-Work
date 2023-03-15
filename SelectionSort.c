#include <stdio.h>

void SelectionSort(int arr[], int len){
	int min, index, temp;
	for(int i = 0; i< (len-1); i++){
		min = arr[i];
		temp = arr[i];
		for (int j = i; j<len; j++){
			if(arr[j] < min){
				min = arr[j];
				index = j;
			}
		}
		
		arr[i] = min;
		arr[index] = temp;
		
	}
}


int main(){
	int len;
	printf("Enter the length\n");
	scanf("%d", &len);
	
	int arr[len];
	for(int i=0; i<len; i++){
		printf("Enter the value at index %d ", i);
		scanf("%d", &arr[i]);
	}
	
	SelectionSort(arr, len);

	for(int i=0; i<len; i++){
		printf("%d -- ",arr[i]);
	}

		return 0;
}