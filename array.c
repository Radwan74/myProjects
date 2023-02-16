#include<stdio.h>

void printArrElements(int arr[], int lenght);
int getSum(int arr[],int lenght);

int main(void)
{

    int arr[] = {1,2,3,4,5};
    int sum , lenght ;
    float average;
    lenght=sizeof(arr)/sizeof(arr[0]);
    printArrElements(arr,lenght);
    sum = getSum(arr,lenght) ;
    average=(float)sum/lenght;
    printf("the sum = %d  and the average = %.2f",sum , average);



    return 0 ;

}
void printArrElements(int arr[], int lenght)
{
    for(int i = 0 ; i < lenght ;i++)
    {
        printf("arr[%d] = %d\n" , i+1 , arr[i]);
    }
}
int getSum(int arr[] , int lenght)
{
    int sum = 0;
    for(int i = 0 ; i < lenght; i++)
    {
        sum += arr[i];
    }
    return sum;
}
