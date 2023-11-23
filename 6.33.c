#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THROWS 36000
#define NUM_POINTS 11 


int binarySearch(int array[], int start, int end, int key);
void simulateThrows(int pointsCount[], int throws);

int main() {
	int pointsCount[NUM_POINTS + 1] = { 0 }; 

	srand(time(NULL)); 

	
	simulateThrows(pointsCount, NUM_THROWS);

	
	printf("%-10s%-10s%-10s\n", "Total", "Count", "Expected");
	printf("=====================\n");

	for (int i = 0; i <= NUM_POINTS; ++i) {
		int expected = (i + 2 == 7) ? NUM_THROWS / 6 : 0; 
		printf("%-10d%-10d%-10d\n", i + 2, pointsCount[i], expected);
	}

	return 0;
}


void simulateThrows(int pointsCount[], int throws) {
	for (int i = 0; i < throws; ++i) {
		int dice1 = rand() % 6 + 1; 
		int dice2 = rand() % 6 + 1; 
		int total = dice1 + dice2;

		
		int index = binarySearch(pointsCount, 0, NUM_POINTS, total);
		if (index != -1) {
			pointsCount[index]++;
		}
	}
}


int binarySearch(int array[], int start, int end, int key) {
	if (start <= end) {
		int mid = start + (end - start) / 2;

		if (array[mid] == key) {
			return mid; 
		}

		if (array[mid] > key) {
			return binarySearch(array, start, mid - 1, key); 
		}

		return binarySearch(array, mid + 1, end, key); 
	}

	return -1; 
}
