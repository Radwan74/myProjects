#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME      50
#define MAX_PHONE_NUM 20
#define DELIVERY      2.0
#define DISCOUNT      0.2

const double tshirtPrice = 12.0;
const double pantsPrice  = 20.0;
const double dressPrice  = 30.0;
const double hatPrice    = 10.0;
const double socksPrice  =  5.0;

typedef enum {T_shirt = 1, Pants , Dress , Hat , Socks }Eproduct;

typedef struct sClient
{
    char name[MAX_NAME];
    char city[MAX_NAME];
    char mobileNumber[MAX_PHONE_NUM];
} sClient;

typedef struct sProduct
{
    char name[MAX_NAME];
    double price ;

}sProduct;

void getString(char str[]);
void getClientInfo(sClient *custmer);
void printList();
void getProductInfo(sProduct *product);
double calculateTotalPrice(double elementPrice , int quantaty , char *city);
void printBill(char *clientName , char *clientCity , char *clientPhone , int totalQuantaty , double totalCost);


int main(void)
{
    sClient custmer;
    Eproduct eProduct ;
    double totalcost = 0.0;
    int totalQuantaty = 0;
    int continueShopping = 1;

    printf("Welcome to our store ^_^ \n");
    getClientInfo(&custmer);

    printList();

    while (continueShopping)
    {
        sProduct product;
        int quantaty;
        double elementPrice , totalPrice;
        char choice;

        

        getProductInfo(&product);
        printf("Enter the quantaty u want ^_^ :");
        scanf("%d",&quantaty);

        elementPrice = product.price;
        totalPrice = calculateTotalPrice(elementPrice , quantaty ,custmer.city);

        totalQuantaty += quantaty;
        totalcost += totalPrice;

        printf("U have orderd [%d] elements of %s for %.3f  \n" ,quantaty , product.name , product.price );
        printf("the total cost for these items = %.2f \n",totalPrice);

        
        while (1)
        {
            printf("\nDo you want to continue shopping? (y/n): ");
            if (scanf(" %c", &choice) != 1)
            {
                printf("Invalid input. Please enter 'y' or 'n'\n");
                
                while (getchar() != '\n');
                continue;
            }
            if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
            {
                printf("\nInvalid input. Please enter 'y' or 'n'\n");
                continue;
            }
            break;
        }

    continueShopping = (choice == 'y' || choice == 'Y');

        

       
    }

    printBill(custmer.name , custmer.city , custmer.mobileNumber , totalQuantaty , totalcost);
    
    return 0;
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

void getClientInfo(sClient *custmer)
{
    printf("Enter your name: ");
    getString(custmer->name);
    printf("Enter your city: ");
    getString(custmer->city);
    printf("Enter your mobile number: ");
    getString(custmer->mobileNumber);
} 

void getProductInfo(sProduct *product)
{
    int productIndex;

    if(product == NULL)
    {
        printf("Invalid information \n");
        return;
    }
    
    while (1)
    {
        printf("Enter the index of your product (1-5) : ");

        if (scanf("%d", &productIndex) != 1) 
        {
            printf("Invalid input. Please enter a valid integer.\n");
            fflush(stdin); 
            continue;
        }

        if(productIndex < T_shirt || productIndex > Socks )
        {
            printf("Invalid product index ^_^\n");
        }
        else
        {
            switch (productIndex)
            {
            case 1:
                strcpy(product->name,"T_shirt");
                product->price = tshirtPrice;
                break;
            case 2:
                strcpy(product->name,"Pants");
                product->price = pantsPrice;
                break;
            case 3:
                strcpy(product->name,"Dress");
                product->price = dressPrice;
                break;
            case 4:
                strcpy(product->name,"Hat");
                product->price = hatPrice;
                break;
            case 5:
                strcpy(product->name,"Socks");
                product->price = socksPrice;
                break;

            default:
                printf("Invalid product index ^_^\n");
                exit(1);
            }

            break;
        }
    }

   
}

double calculateTotalPrice(double elementPrice , int quantaty , char *city)
{
    double totalPrice;

    totalPrice = elementPrice * quantaty ;
    
    if(strcasecmp(city , "mansoura") != 0 )
    {
        totalPrice += (2.0 * DELIVERY) + 1.0; 
    }
    else
    {
        totalPrice += DELIVERY;
    } 

    if(quantaty > 5)
    {
        totalPrice *= (1.0 - DISCOUNT); 
    }

    return totalPrice ;
}

void printBill(char *clientName , char *clientCity , char *clientPhone , int totalQuantaty , double totalCost)
{
    printf("\nYour Bill ^_^ \n");
    printf("\n**********************************************************\n");
    printf("Custmer information : \n");
    printf("Nume  : %s\n" , clientName);
    printf("City  : %s\n" , clientCity);
    printf("Phone : %s\n" , clientPhone);
    printf("\n**********************************************************\n");
    printf("Product information : \n");
    printf("Total quantaty  : %d\n" , totalQuantaty);
    printf("Total cost      : %.2lf $\n" , totalCost);
    printf("\n**********************************************************\n");
    printf("Thank u for shopping with us ^_^ \n");

}

void printList()
{
    printf("\n**********************************************************\n");
    printf("Please choose product from our list : \n");
    printf("1- T-shirt \t(12.0$)\n");
    printf("2- Pants   \t(20.0$)\n");
    printf("3- Dress   \t(30.0$)\n");
    printf("4- Hat     \t(10.0$)\n");
    printf("5- Socks   \t(5.0 $)\n");
    printf("\n**********************************************************\n");
}