#include <stdio.h>

typedef struct {
	int q;
	float u;
} Food;


float cost(Food food) {
	return food.q * food.u;
}

int main() {
	Food paratha, vegetables, mineral_water;
	int num_people;
	float total_cost, cost_person;

	
	printf("Quantity Of Paratha: ");
	scanf("%d", &paratha.q);
	printf("Unit Price: ");
	scanf("%f", &paratha.u);

	
	printf("Quantity Of Vegetables: ");
	scanf("%d", &vegetables.q);
	printf("Unit Price: ");
	scanf("%f", &vegetables.u);

	
	printf("Quantity Of Mineral Water: ");
	scanf("%d", &mineral_water.q);
	printf("Unit Price: ");
	scanf("%f", &mineral_water.u);

	
	printf("Number of People: ");
	scanf("%d", &num_people);

	
	total_cost= cost(paratha) + cost(vegetables) + cost(mineral_water);

	
	cost_person = total_cost / num_people;

	
	printf("Individual people will pay: %.2f tk\n", cost_person);

	return 0;
}

