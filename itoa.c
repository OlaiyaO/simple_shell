#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* _itoa(int number) {
    	char *result;
	bool isNegative;
	int temp;
	int digitCount;
	int index;

	if (number == 0) {
        result = (char*)malloc(2);
        if (result != NULL) {
            result[0] = '0';
            result[1] = '\0';
        }
        return result;
    }
	isNegative = false;
    if (number < 0) {
        isNegative = true;
        number = -number;
    }

   	temp = number;
    digitCount = 0;
    while (temp > 0) {
        temp /= 10;
        digitCount++;
    }
    result = (char*)malloc(digitCount + (isNegative ? 2 : 1)); 

    if (result != NULL) {
        index = digitCount + (isNegative ? 1 : 0);
        result[index] = '\0'; 

        while (number > 0) {
            index--;
            result[index] = '0' + (number % 10); 
            number /= 10;
        }

        if (isNegative) {
            result[0] = '-';
        }
    }
return result;
}
