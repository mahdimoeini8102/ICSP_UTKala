#include <stdio.h>
#include "mystring.h"
void strcopy(char* str1, char* str2) {
	int i = 0;
	while (*(str1 + i - 1) != '\0') {
		*(str2 + i) = *(str1 + i);
		i++;
	}
}

int strcompare(char* str1, char* str2) {
	int i = 0, result = 0;
	while (*(str1 + i - 1) != ' ' && *(str1 + i - 1) != '\n' && *(str1 + i - 1) != '\0') {
		if (*(str1 + i) == *(str2 + i))
			result = 1;
		else {
			result = 0; 
			break;
		}
		i++;
	}
	return result;
}