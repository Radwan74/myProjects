#include <stdio.h>
#include <string.h>

#define MAX_STUDENT_NUM 100
#define MAX_NAME 30

typedef struct student
{
    char name[MAX_NAME];
    int rollNum;
    float mathDegree;
    float physicsDegree;
    float chemistryDegree;

}sStudent;

typedef enum Options
{
    addRecord = 1,
    modifyRecord,
    deleteRecord,
    displayRecords,
    searchRecord,
    exit
}eOptions;

void getString(char str[]);
void displayOptions();
void addStudent(sStudent ourStudent[MAX_STUDENT_NUM] , int *studentNum);
void modifyStudent(sStudent ourStudent[MAX_STUDENT_NUM] , int studentNum);
void deleteStudent(sStudent ourStudent[MAX_STUDENT_NUM] , int *studentNum);
void displayStudents(sStudent ourStudent[MAX_STUDENT_NUM] , int studentNum);
void search(sStudent ourStudent[MAX_STUDENT_NUM] , int studentNum);

int main(void)
{
    sStudent ourStudents[MAX_STUDENT_NUM];
    int studentNum = 0;
    int choice ;

    do
    {
        displayOptions();
        printf("Enter your choice (1-6): ");
        if(scanf("%d", &choice) != 0)
        {

            switch (choice)
            {
            case addRecord :
                addStudent(ourStudents,&studentNum);
                break;
            case modifyRecord :
                modifyStudent(ourStudents,studentNum);
                break;
            case deleteRecord :
                deleteStudent(ourStudents,&studentNum);
                break;
            case displayRecords :
                displayStudents(ourStudents ,studentNum);
                break;
            case searchRecord :
                search(ourStudents,studentNum);
                break;
            case exit :
                printf("Exiting program ^_^ \n");
                break;
            
            default:
                printf("Invalid choice, please try again \n");
                break;
            }
        }
          else 
        {
            printf("\nInvalid input, please try again \n");
          
            while (getchar() != '\n');
        }
            
    } while (choice != 6);
    

    return 0 ;
}

void getString(char str[])
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        str[i++] = ch;
    }
    str[i] = '\0';
}
void displayOptions()
{
    printf("\nStudent Database Management System\n");
    printf("1. Add a new student record\n");
    printf("2. Modify an existing student record\n");
    printf("3. Delete a student record\n");
    printf("4. Display all student records\n");
    printf("5. Search for a student record\n");
    printf("6. Exit\n");
} 

void addStudent(sStudent ourStudent[MAX_STUDENT_NUM] , int *studentNum)
{
    sStudent newStudent;
    if(*studentNum == MAX_STUDENT_NUM)
    {
        printf("\nError: Maximum number of students reached.\n");
        return;
    } 

    printf("\nEnter student name : ");
    while ((getchar()) != '\n');
    getString(newStudent.name);

    printf("\nEnter student roll number :");
    scanf("%d",&newStudent.rollNum);

    printf("\nEnter student degree in math :");
    scanf("%f" , &newStudent.mathDegree);

    printf("\nEnter student degree in physics :");
    scanf("%f" , &newStudent.physicsDegree);

    printf("\nEnter student degree in chemistery :");
    scanf("%f" , &newStudent.chemistryDegree);

    ourStudent[*studentNum] = newStudent;
    (*studentNum)++;

    printf("\nStudent record added successfully.\n");

}

void modifyStudent(sStudent ourStudent[MAX_STUDENT_NUM] , int studentNum)
{
    int rollNum , i ;
    char field[20];
    
    printf("\nEnter the roll number of student to modify :");
    if(scanf("%d" , &rollNum) != 0)
    {
        for( i = 0 ; i < studentNum ; i++)
        {
            if(ourStudent[i].rollNum == rollNum)
            {
                break;
            }
        }

        if(i == studentNum)
        {
            printf("\nError: Student record not found.\n");
            return;
        }

        printf("\nEnter the field u want to modify(name , roll number , math degree , physics degree , chemistry degree ) : ");
        if(scanf("%s" ,&field ) != 0)
        {

            if(strcasecmp(field , "name") == 0)
            {
                printf("\nEnter the new name :");
                while ((getchar()) != '\n');
                getString(ourStudent[i].name);
            }
            else if(strcasecmp(field , "roll number") == 0 )
            {
                printf("\nEnter the new roll number : ");
                scanf("%d",&ourStudent[i].rollNum);
            }
            else if(strcasecmp(field , "math degree") == 0 )
            {
                printf("\nEnter the new math degree : ");
                scanf("%f" ,&ourStudent[i].mathDegree);
            }
            else if(strcasecmp(field , "physics degree") == 0 )
            {
                printf("\nEnter the new physics degree : ");
                scanf("%f" ,&ourStudent[i].physicsDegree);
            }
            else if(strcasecmp(field , "chemistry degree") == 0 )
            {
                printf("\nEnter the new chemistry degree : ");
                scanf("%f" ,&ourStudent[i].chemistryDegree);
            }
            else
            {
                printf("\nError : Invalid information ^_^ \n");
            }
        }

    }
    else
    {
        printf("\nInvalid input, please try again \n");
          
        while (getchar() != '\n');
    }

}

void deleteStudent(sStudent ourStudent[MAX_STUDENT_NUM] , int *studentNum)
{
    int rollNum , i , j ;

    printf("\nEnter student roll number to delete :");
    scanf("%d" ,&rollNum);

    for(i = 0 ; i < *studentNum ; i++)
    {
        if(ourStudent[i].rollNum == rollNum )
        {
            break;
        }
    }

    if( i == *studentNum)
    {
        printf("\nError: Student record not found.\n");
        return;
    }

    for(j = i ; j < *studentNum - 1 ; j++ )
    {
        ourStudent[j] = ourStudent[i+1] ;
    }

    (*studentNum)--;

    printf("\nStudent record deleted successfully.\n");
}

void displayStudents(sStudent ourStudent[MAX_STUDENT_NUM] , int studentNum)
{
    if(studentNum == 0 )
    {
        printf("\nNo student records found \n");
        return;
    }
    printf("***************************************************************************");
    printf("\nStudent Database : \n");

    for(int i = 0 ; i < studentNum ; i++ )
    {
        printf("Information of student number %d : \n" , i+1);
        printf("Student name  : %s \n" , ourStudent[i].name);
        printf("Student roll number : %d \n" ,ourStudent[i].rollNum);
        printf("Student meth degree : %.2f \n" , ourStudent[i].mathDegree);
        printf("Student physics degree : %.2f \n" , ourStudent[i].physicsDegree);
        printf("Student chemistry degree : %.2f \n" , ourStudent[i].chemistryDegree);
        printf("***************************************************************************\n");
    }
}

void search(sStudent ourStudent[MAX_STUDENT_NUM] , int studentNum)
{
    int rollNum , i;

    printf("Enter the roll number u want to search for : ");
    if(scanf("%d" , &rollNum) != 0)
    {

        for(i = 0 ; i < studentNum ; i++)
        {
            if(ourStudent[i].rollNum == rollNum)
            {
                printf("Information of student number %d : \n" , i);
                printf("Student name  : %s \n" , ourStudent[i].name);
                printf("Student roll number : %d \n" ,ourStudent[i].rollNum);
                printf("Student meth degree : %.2f \n" , ourStudent[i].mathDegree);
                printf("Student physics degree : %.2f \n" , ourStudent[i].physicsDegree);
                printf("Student chemistry degree : %.2f \n" , ourStudent[i].chemistryDegree);

                return;
            }
        }

    }
    else
    {
        printf("\nInvalid input, please try again \n");
          
        while (getchar() != '\n');
    }
}