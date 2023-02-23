#include<stdio.h>
#include<string.h>

/* declare category emun */
enum enumCategory{food, drink, toiletries, clothing};

/* declare product info union */
union unumProductInfo
{
    int intValue;
    float floatValue;
};

/*declare the product structure */
struct sProduct
{
    char name[50];
    float price;
    int stock;
    enum enumCategory category;
    union unumProductInfo info;
};

void printProduct(struct sProduct product);

int main(void)
{
    /* declare an array of three sProducts */
    struct sProduct product[3];

    /*intialize the first product*/
    strcpy(product[0].name, "Milk");
    product[0].price = 1.5;
    product[0].stock = 10;
    product[0].category = drink;
    product[0].info.intValue = 10;

    /*intialize the second product*/
    strcpy(product[1].name, "Bread");
    product[1].price = 2.5;
    product[1].stock = 20;
    product[1].category = food;
    product[1].info.intValue = 200;

    /*intialize the third product*/
    strcpy(product[2].name, "T_shirt");
    product[2].price = 3.5;
    product[2].stock = 30;
    product[2].category = clothing;
    product[2].info.intValue = 30;

    /* print the products */
    for(int i = 0; i < 3; i++)
    {
        printProduct(product[i]);
    }
}

void printProduct(struct sProduct product)
{
    printf("Name: %s , category : %d , price : %.2f , stock : %d , addition info : %d \n"
    , product.name , product.category , product.price , product.stock , product.info.intValue);
}
