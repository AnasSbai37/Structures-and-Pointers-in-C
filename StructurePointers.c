#include <stdio.h>
#include <stdlib.h>

struct item {
    char *itemName;
    int quantity;
    float price;
    float amount;
};


void readitem(struct item * i);
void printitem(struct item * i);

int main (void) {
    struct item itm;
    struct item *pItm; 
    pItm = &itm;

    pItm->itemName = (char *) malloc(30 * sizeof(char));
    if (!pItm->itemName) {
        exit (-1);
    }
    readitem(pItm);
    printitem(pItm);

    free(pItm->itemName);
    return 0;
}

void readitem(struct item * i) {
    printf("Please enter an item name : \n");
    scanf("%s",i->itemName);
    printf("Please enter quantity : \n");
    scanf("%d", &i->quantity);
    printf("Please enter the price : \n");
    scanf("%f", &i->price);
    i->amount = (float) i->price * i->quantity;
}

void printitem(struct item * i){
    printf("Name of product : %s.\n",i->itemName);
    printf("Quantity of product : %d.\n",i->quantity);
    printf("Price : %f.\n",i->price);
    printf("The total amount is : %.2f$.\n",i->amount);
}