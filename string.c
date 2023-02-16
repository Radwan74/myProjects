#include<stdio.h>
#include <string.h>
int getArr(char arr[]);
void printString(char arr[],int lenght);

int main(void)
{
    char arr1[50] , arr2[50] , arr3[100] ;
    int lenght1 , lenght2 , lenght3 ; 
    printf("Enter the first string : ");
    lenght1 =getArr(arr1);
    printf("\nEnter the second string : ");
    lenght2 =getArr(arr2);
    printf("\nThe first string is :  ");
    printString(arr1,lenght1);
    printf("\nThe second string is : ");
    printString(arr2,lenght2);
    strcpy(arr3, arr1);
    strcat(arr3, arr2);
    printf("\nThe concatenated string is : %s",arr3);
    
    

    return 0;
}
int getArr(char arr[])
{
    int ch , i = 0;
    while ((ch=getchar())!='\n')
    {
        
        arr[i++]=ch;
    }
    arr[i]='\0';
 
    return i;
}
void printString(char arr[],int lenght)
{
    for(int i = 0; i < lenght ; i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}