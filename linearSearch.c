#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[] = {32, 43, 55, 76, 78, 12, 457, 91};
	int size = 	8;
	LinearSearch(arr, size);
			
	return 0;
}

void LinearSearch(int array[], int length){
	int item; 
	int temp = 2;
	printf("Enter the value you want to search\n");
	scanf("%d", &item);
	for(int i = 0; i<length; i++){
		if(item == array[i]){
			printf("The item %d is found at location %d in the array\n", item, i);
			temp = 1;
			break;
		}
	}
	
	if(temp == 2){
		printf("Item not found");
	}
}
