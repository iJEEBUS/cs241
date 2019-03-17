#include <stdio.h>
#include <string.h>

#define N 20
struct product {
	char name[N];
	float quantity_value;
	char quantity_unit[N];
	float price_value;
	char price_unit[N];
	struct product *next;
};

typedef struct person person;

// save list to a file
void save(struct product *l, char fn[]);

// load list from a file
struct product * load(struct product *l, char fn[]);

// build a node
struct product * buildNode(char name[], float quantity_value, char quantity_unit[], float price_value, char price_unit[]);


// append a node that is pointed to by p to the end of a list name l if 
// the list is not empty and the product is not already in the list.
// if empty, make p the head of l and return l
struct product * add_product(struct product *l, struct product *p);

// check the main inventory file to see if it contains data or not
int data_exists();

// display the entire inventory
void show_inventory(struct product *l);

// look up the price of a specific item
void price_lookup(struct product *l, char name[]);

// look up the info about a product
void product_lookup(struct product *l, char name[]);

// remove a product from stock
void remove_product(struct product *l, char name[]);

// sell a product and return the total money made from the deal
void sale(struct product *l, char name[], int qty, float *profit);
