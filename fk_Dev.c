#include <stdio.h>

struct item
{
    int value;
    int weight;
    float ratio;
};

                                                                                                                                                              
float fraction (struct item items[], int n, int capacity){
    float totalValue = 0;
    
    for (int i = 0; i < n; i++)
    {
       if (capacity > 0 && items[i].weight <= capacity)
       {
           capacity = capacity - items[i].weight;
           totalValue = totalValue + items[i].value;
       }

       else if (capacity > 0)
       {
    
           totalValue = totalValue + (float)items[i].ratio * capacity; 
           capacity = 0;
       }

       else{
        break;
       }
    }
    
printf("%f \n",totalValue);
       return totalValue;

}

void main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct item items[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value and weight of item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    printf("Enter the capacity of the knapsack: ");
    int capacity;
    scanf("%d", &capacity);
    float totalValue = 0;
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                struct item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    totalValue= fraction(items, n, capacity);
   
}