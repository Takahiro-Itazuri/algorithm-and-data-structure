#include<stdio.h>
#include<stdlib.h>

unsigned char original_text[] = "Team Swift";
unsigned char original_pattern[] = "if";

#define _SHOW_WORKING_

unsigned char* simple_search(unsigned char *text, unsigned char *pattern) {
	int i;
	while((*text) != '\0') {
#ifdef _SHOW_WORKING_
		printf("original text:%s \n      pattern:", original_text);
		for(i = 0; i < text - original_text; i++) {
			printf(" ");
		}
		printf("%s \n", pattern);
#endif
		for(i = 0; pattern[i] != '\0'; i++) {
			if(pattern[i] != text[i]) break;
		}

		if(pattern[i] == '\0') {
			return text;
		}

		text++;
	}

	return NULL;
}

int main(void) {
	unsigned char *result;
	result = simple_search(original_text, original_pattern);
	if(result == NULL) {
		printf("Not Found.\n");
	}
	else {
		printf("Found.\n");
	}

	return EXIT_SUCCESS;
}
