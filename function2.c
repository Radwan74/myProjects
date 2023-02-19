#include<stdio.h>
#define MAX 100
void scanArr(int arr[],int lenght);
int findLargest(int arr[], int lenght);

int main(void)
{
    int arr[MAX];
    int lenght , largest;
    
    printf("Enter the lenght of the array from 1 to 100 : ");
    scanf("%d",&lenght);
    printf("\nEnter the elements if the array : ");
    scanArr(arr,lenght);
    largest = findLargest(arr,lenght);
    printf("The largest element is %d ",largest);

    return 0 ;
}
void scanArr(int arr[],int lenght)
{
    for(int i = 0 ; i < lenght ; i++)
    {
        scanf("%d",&arr[i]);
    }
}
int findLargest(int arr[], int lenght)
{
    int largest = arr[0];
    for(int i = 0 ;i < lenght  ; i++)
    {
        if(arr[i] > largest )
        {
            largest = arr[i];
        }
    }
    return largest;
}