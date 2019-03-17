/******************************************************************************
 * project 3 - cs241 -GVSU
 *
 * The execution file for the store inventory project (linked-lists).
 *
 * @author Ron Rounsifer
 * @version 0.02
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#define FALSE 0
#define TRUE 1
#define N 20

/******************************************************************************
 * Simple GUI for the operator to interface with.
 ******************************************************************************/
void displayMenu()
{
	puts("");
	puts("Inventory Manager - v0.01");
	puts("======================================================");
	puts("1: Add product			2: Sale");
	puts("3: Price lookup			4: Display inventory");
	puts("5: Remove product		6: Product search");
	puts("7: Status report		8: Exit (save)");
}


/*******************************************************************************
 * Prompts the user to gather the information that is needed to add a new 
 * product to the inventory.
 * After gathering the info, the add_product function is called from the 
 * operations.c file.
 *******************************************************************************/
void add_product_helper(struct product *l)
{
	char name[N];
	float quantity_value;
	char quantity_unit[N];
	float price_value;
	char price_unit[N];

	puts("\n");
	puts("Product information\n\n");
	
	puts("Name: ");
	fflush(stdin);
	scanf("%s", name);
	fflush(stdin);

	puts("Quantity: ");
	fflush(stdin);
	scanf("%f", &quantity_value);
	fflush(stdin);

	puts("Quantity unit: ");
	fflush(stdin);
	scanf("%s", quantity_unit);
	fflush(stdin);	

	puts("Price: ");
	fflush(stdin);
	scanf("%f", &price_value);
	fflush(stdin);	

	puts("Price unit: ");
	fflush(stdin);
	scanf("%s", price_unit);
	fflush(stdin);	

	add_product(l, buildNode(name, quantity_value, quantity_unit, price_value, price_unit));
}


/*******************************************************************************
 * Prompts the user for the name of the product they wish to look up the 
 * price for.
 * After getting the name, this will call the price_lookup function found in 
 * operations.c file.
 *******************************************************************************/
void product_lookup_helper(struct product *l, int for_price) 
{
	// get the name of the product
	char product_name[N];
	puts("\n");
	puts("Name: ");
	fflush(stdin);
	scanf("%s", product_name);

	// route to correct method call in operations.c 
	if (for_price)
		price_lookup(l, product_name);
	else	
		product_lookup(l, product_name);
}
/*******************************************************************************
 * Prompts the user for the name of the product as well as the quantity of said
 * product they wish to buy.
 * Calls the sale function found in the operations.c file to actually handle
 * the sale.
 * 
 * @returns (float) the total amount made from the sale
 *******************************************************************************/
float sale_helper(struct product *l)
{
	char product_name[N];
	int quantity;
	float profit = 0.0;

	puts("\n");
	puts("Sale\n\n");

	puts("Name: ");
	fflush(stdin);
	scanf("%s", product_name);

	puts("Quantity: ");
	fflush(stdin);
	scanf("%d", &quantity);
	sale(l, product_name, quantity, &profit);

	return profit;
}

/**
 * Returns the pointer to the new inventory list after removing the item
 * specified by the user.
 *
 * @returns new pointer to inventory list
 **/
struct product * remove_product_helper(struct product *l)
{
	// get the name of the product
	char product_name[N];
	puts("\n");
	puts("Name: ");
	fflush(stdin);
	scanf("%s", product_name);
	return remove_product(l, product_name);
}

/*******************************************************************************
 * Entry point of the program.
 *
 * @returns (int) state of program execution
 *******************************************************************************/
  int main(int argc, char *argv[])
{
	struct product *head = NULL;
	int choice, done = FALSE;
	float total_sales = 0.0;
	system("clear");

	// try to load data if there is any
	if (data_exists())
		head = load(head, "data");

	while (!done)
	{
		displayMenu();
		puts("Command: ");
		fflush(stdin);
		scanf("%d", &choice);
		fflush(stdin);

		switch (choice)
		{
			case 1: // add product
				add_product_helper(head);
				break;
			case 2: // sale
				total_sales += sale_helper(head); 
				printf("%f", total_sales);
				break;
			case 3: // price lookup
				product_lookup_helper(head, TRUE);
				break;
			case 4: // display inventory
				show_inventory(head);
				break;
			case 5: // remove product
				head = remove_product_helper(head);
				break;
			case 6: // product search
				product_lookup_helper(head, FALSE);
				break;
			case 7: // status report
				printf("\n");
				printf("Total revenue today: $%0.2f\n", total_sales);
				show_inventory(head);
				break;
			case 8: // done for the day
				done = TRUE;
				puts("Saving the inventory...\n");
				puts("Enjoy the rest of your day!\n");
				save(head, "data");
				break;
		}
	}
	return 0;
}
