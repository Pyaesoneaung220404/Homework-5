#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THROWS 36000
#define NUM_POINTS 11 

int main() {
	int dice1, dice2, total;
	int pointsCount[NUM_POINTS + 1] = { 0 }; 

	srand(time(NULL)); 

	
	for (int i = 0; i < NUM_THROWS; ++i) {
		dice1 = rand() % 6 + 1; 
		dice2 = rand() % 6 + 1; 
		total = dice1 + dice2;
		pointsCount[total - 2]++; 
	}

	
	printf("%-10s%-10s%-10s\n", "Total", "Count", "Expected");
	printf("=====================\n");

	for (int i = 0; i <= NUM_POINTS; ++i) {
		int expected = (i + 2 == 7) ? NUM_THROWS / 6 : 0; 
		printf("%-10d%-10d%-10d\n", i + 2, pointsCount[i], expected);
	}

	return 0;
}
