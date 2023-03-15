#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[] = {1, 15, 30, 45, 60, 71, 80, 90};
	int size = 	8;
	BinarySearch(arr, size);
			
	return 0;
}

void BinarySearch(int array[], int length){
	int item; 
	int temp = 2;
	printf("Enter the value you want to search\n");
	scanf("%d", &item);
	
	int first = 0;
	int last = length-1;
	int mid = (first+last)/2;
	
	if(item == array[first]){
		printf("Item found at position 1\n");
		temp = 1;
	}
	
	else if(item == array[last]){
		printf("Item found at position %d\n", last);
		temp = 1;
	}
	
	
	else{
		while(first < last){
			if(item == array[mid]){
				printf("The item is found at %d in the array\n", mid);
				temp = 1;
				break;
			}
			
			else if(item > array[mid]){
				first = mid;
				mid =(first+last)/2;
			}
			
			else{
				last = mid;
				mid = (first+last)/2;
			}
		}	
		
	}
	
	if(temp == 2){
		printf("Item not found");
	}
}
