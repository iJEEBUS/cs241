/*******************************************************************************
 * Store inventory - linked lists - project 3 - cs241 @ GVSU
 *
 * The brains behind the store inventory system that is defined in the project 3
 * assignment. Allows the operator to add a product, commit a sale, lookup prices, 
 * display the entire inventory, remove a product, search for a product, view a
 * status report of the daily sales, and close for the day (save the inventory 
 * to a file).
 *
 * @author Ron Rounsifer
 * @version 0.02
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

#define N 20
#define FALSE 0
#define TRUE 1

/*******************************************************************************
 * Save all the data of current list to a file (fout) 
 *******************************************************************************/
void save(struct product *l, char fn[])
{
	FILE *fout = fopen(fn, "w");
	if (fout == NULL)
	{
		printf("save: file open failed (%s)\n", fn);
		return;
	}
	struct product *curr = l;
	while (curr != NULL)
	{
		fprintf(fout, "%s %.0f %s %.2f %s\n", 
				curr->name, 
				curr->quantity_value, 
				curr->quantity_unit, 
				curr->price_value, 
				curr->price_unit);
		curr = curr->next;
	}
	fclose(fout);
}

/*******************************************************************************
 * Load data from a file (fn) and append to a list (l). 
 * 
 * @returns the resulting list
 *******************************************************************************/
struct product * load(struct product *l, char fn[])
{
	char name[N], quantity_unit[N], price_unit[N];
	float quantity_value, price_value;
	int rt;
	struct product *head = l;

	FILE *fin = fopen(fn, "r");
	if (fin == NULL)
	{
		printf("save: file open failed (%s)\n", fn);
		return NULL;
	}

	while(1)
	{
		rt = fscanf(fin, "%s %f %s %f %s\n", 
				name, 
				&quantity_value, 
				quantity_unit, 
				&price_value, 
				price_unit);
		if (rt < 5)
			break;
		if (head == NULL)
			head = buildNode(name, quantity_value, quantity_unit, price_value, price_unit);
		else
			add_product(head, buildNode(name, quantity_value, quantity_unit, price_value, price_unit));
	}

	fclose(fin);
	return head;

}


/*******************************************************************************
 * Create a node with the products:
 * 	- name 			(char[])
 * 	- quantity_value 	(float)
 * 	- quantity_unit 	(char[])
 * 	- price_value 		(float)
 * 	- price_unit 		(char[])
 *
 * @returns the new node
 *******************************************************************************/
struct product * buildNode(char name[], float quantity_value, char quantity_unit[], float price_value, char price_unit[])
{
	struct product *p = (struct product *) malloc(sizeof(struct product));

	if (p == NULL)
	{
		printf("buildNode: memory allocation failed");
		return NULL;
	}

	strcpy(p->name, name);
	strcpy(p->quantity_unit, quantity_unit);
	strcpy(p->price_unit, price_unit);
	p->quantity_value = quantity_value;
	p->price_value = price_value;

	return p;	
}

/*******************************************************************************
 * Add the product, p, to the inventory list, l.
 * If the list is empty, set p as the head of l, return l.
 * Otherwise, increment inv count if product is already in list;
 * else append the product to the list if it is not in the list yet.
 *
 * @returns the list with the added product
 *******************************************************************************/
struct product * add_product(struct product *l, struct product *p)
{
	struct product *head = l;
	if (l == NULL)
		l = p;
	else
	{
		// Check if the product is already in inventory
		while (head->next != NULL)
		{
			// increment inventory quantity if found
			if (strcmp(l->name, p->name) == 0)
			{
				head->quantity_value += p->quantity_value;
				return l;
			}
			head = head->next;
		}

		// append the product to the list if it was not found in inventory
		head->next = p;	
	}
	return l;
}


/*******************************************************************************
 * Opens the file and checks if a character exists within. 
 * This is just to check if the inventory data exists upon boot
 * of the program.
 *
 * @returns TRUE if data in file, FALSE otherwise
 *******************************************************************************/
int data_exists()
{
	FILE *fp = fopen("data", "r");
	
	if (fp == NULL)
	{
		puts("This file does not exist yet");
		exit(1);	
	}

	int c = fgetc(fp);
	if (c == EOF)
	{
		fclose(fp);
		return FALSE;
	}
	fclose(fp);
	return TRUE;
}

/*******************************************************************************
 * Given a list, display each item in the inventory.
 *******************************************************************************/
void show_inventory(struct product *l)
{
	if (l != NULL)
	{
		printf("\n");	
		printf("-\n");
		printf("%s / %.0f %s / $%.2f %s\n", l->name, l->quantity_value, l->quantity_unit, l->price_value, l->price_unit);
		printf("-\n");
		printf("\n");
		show_inventory(l->next);
	}
}

/*******************************************************************************
 * Given a list of inventory and a product name, displays the price of the 
 * product if it is found in the inventory.
 *********************************************************************************/
void price_lookup(struct product *l, char name[])
{
	if (l != NULL)
	{
		if (strcmp(l->name, name) == 0)
		{
			// match found
			printf("\n");
			printf("-\n");
			printf("%s / $%0.2f %s\n", l->name, l->price_value, l->price_unit);
			printf("-\n");
			printf("\n");
		} else {
			// no match, check next node
			price_lookup(l->next, name);
		}
	} else {
		// no match found in inventory
		printf("Sorry, there was no match found.");
	}
}

/*******************************************************************************
 * Given a list of inventory and product name, displays the infor of the 
 * product if it is found in the inventory.
 *******************************************************************************/
void product_lookup(struct product *l, char name[])
{
	if (l != NULL)
	{
		if (strcmp(l->name, name) == 0)
		{
			// match found
			printf("\n");
			printf("-\n");
			printf("%s / %.0f %s / $%0.2f %s\n", l->name, l->quantity_value, l->quantity_unit, l->price_value, l->price_unit);
			printf("-\n");
			printf("\n");
		} else {
			// no match, check next node
			product_lookup(l->next, name);
		}
	} else {
		// no match found in inventory
		printf("Sorry, there was no match found.");
	}
}

/*******************************************************************************
 * Given a list and  a product name, search through the list
 * and remove the product from it.
 *******************************************************************************/
void remove_product(struct product *l, char name[])
{
	if (l != NULL)
	{
		if (strcmp(l->next->name, name) == 0)
		{
			// match found
			l->next = l->next->next;

		} else {
			// no match, check next node
			remove_product(l->next, name);
		}
	} else {
		// no match found in inventory
		printf("Sorry, no item called '%s' found in the inventory.", name);
	}
}

/*******************************************************************************
 * When a sale occurs the iventory is searched for the item, the items 
 * quantity is then checked if it exists. If not enough items are in stock
 * we sell the rest of what we have and remove the item from inventory.
 *
 * The profit generated from each sale is written to the profit pointer that is
 * passed as an argument.
 *******************************************************************************/
void sale(struct product *l, char name[], int qty, float *profit)
{
	if (l != NULL)
	{
		if (strcmp(l->name, name) == 0)
		{
			// match found
			if (l->quantity_value >= qty)
			{
				// have enough in stock
				*profit = (l->price_value * qty);
				l->quantity_value -= qty;
				printf("%f\n", *profit);

			} else {
				// do not have enough in stock
				*profit = (l->price_value * l->quantity_value);
				remove_product(l, name);
			}
		} else {
			// no match, check next node
			sale(l->next, name, qty, profit);
		}
	} else {
		// no match found in inventory
		printf("Sorry, there was no match  for '%s'", name);
	}
}
