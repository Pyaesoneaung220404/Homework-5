#include <stdio.h>


int recursiveMaximum(int array[], int size);

int main() {
	int myArray[] = { 3, 7, 1, 9, 4, 2, 6, 8, 5 };
	int arraySize = sizeof(myArray) / sizeof(myArray[0]);

	
	int max = recursiveMaximum(myArray, arraySize);

	printf("The maximum value in the array is: %d\n", max);

	return 0;
}


int recursiveMaximum(int array[], int size) {
	
	if (size == 1) {
		return array[0];
	}

	
	int maxInRest = recursiveMaximum(array + 1, size - 1);

	
	return (array[0] > maxInRest) ? array[0] : maxInRest;
}
