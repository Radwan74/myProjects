#include<stdio.h>
void scanString(char arr[]);
void inputString(char arr[]);

int main(void)
{
    char str1[50] , str2[50];
    printf("Enter the first string : ");
    scanString(str1);
    printf("Enter the second string : ");
    inputString(str2);
    printf("***********************************************************\n");
    printf("The first string is : %s \n",str1);
    printf("The second string is : %s \n",str2);


    return 0 ;
}
void scanString(char arr[])
{
    int ch , i = 0;
    while((ch = getchar()) != '\n')
    {
        arr[i++] = ch;
    }
    arr[i]= '\0';
}
void inputString(char arr[])
{
    int i ; 
    scanf("%c",&arr[0]);
    for(i = 0 ; arr[i] != '\n' ;)
    {
        i++;
        scanf("%c",&arr[i]);
    }
    arr[i] = '\0';
}
