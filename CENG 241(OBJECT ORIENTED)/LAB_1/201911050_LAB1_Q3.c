#include <stdio.h>

struct user_info
{
	double bill;
	int nop;
	int choose;
	int item;

	struct components
	{
		int  id[20];
		char comp_name[20][20];
		double value[20];
	
	} comp;	
};

int main (void)
{
	
	int i;
	struct user_info user;
	
	user.bill = 0;
	user.choose = 1;
	
	printf("Enter the number of product you want to add: ");
	scanf("%d", &user.nop);
	
	for (i = 0; i < user.nop; i++)
	{
		printf("Enter product id and product name and price: ");
		scanf("%d %s %lf",  &user.comp.id[i], &user.comp.comp_name[i], &user.comp.value[i]);
		printf("%d %s %.2lf \n", user.comp.id[i], user.comp.comp_name[i], user.comp.value[i]);
	}
	
	printf("Displaying Information: \n");
	for (i = 0; i < user.nop; i++)
	{
		printf("name: %s id: %d price: %.2lf \n",  user.comp.comp_name[i], user.comp.id[i], user.comp.value[i]);
	}
	
	while (user.choose != 0)
	{
		printf("Choose item from list with the id: ");
		scanf("%d", &user.item);
		printf("Press 1 if you want to continue: ");
		scanf("%d", &user.choose);
		
		user.bill += user.comp.value[user.item-1];
	}
	
	for (i = 0; i < user.nop; i++)
	{
		printf("Your order:\n");
		printf("name: %s price: %.2lf \n",  user.comp.comp_name[i], user.comp.value[i]);
	}
	printf("Bill: %.2lf$", user.bill);
	
}
