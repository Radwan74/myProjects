#include <stdio.h>
#include <string.h>

int main() {
    char arr1[50], arr2[50], arr3[100];

    printf("Enter the first string: ");
    fgets(arr1, 50, stdin);
    arr1[strcspn(arr1, "\n")] = '\0'; 

    printf("Enter the second string: ");
    fgets(arr2, 50, stdin);
    arr2[strcspn(arr2, "\n")] = '\0';  

    strcpy(arr3, arr1);
    strcat(arr3, arr2);
    printf("Concatenated string: %s\n", arr3);

    return 0;
}
