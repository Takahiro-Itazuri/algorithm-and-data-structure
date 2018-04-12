#include<stdio.h>
#include<stdlib.h>

#define PATTERN_LENGTH 13
unsigned char original_text[] = "a eighty-eighty-eighth key";
unsigned char original_pattern[PATTERN_LENGTH + 1] = "eighty-eighth";

#define _SHOW_WORKING_

unsigned char *kmp_search(unsigned char *text, unsigned char *pattern) {
	int table[PATTERN_LENGTH + 1] = {0, 0};
	int text_idx = 1, pattern_idx = 0;
	int i = 0;

	while((pattern[text_idx]) != '\0') {
		if(pattern[text_idx] == pattern[pattern_idx]) {
			table[++text_idx] = ++pattern_idx;
		}
		else if(pattern_idx == 0) {
			table[++text_idx] = 0;
		}
		else {
			pattern_idx = table[pattern_idx];
		}
	}

	while((*text) != '\0') {
#ifdef _SHOW_WORKING_
		int j;
		printf("original text:%s \n      pattern:", original_text);
		for(j = 0; j < text - original_text; ++j) printf(" ");
		printf("%c \n", pattern[i]);
#endif
		if((*text) == pattern[i]) {
			text++;
			if(pattern[++i] == '\0') {
				return text - PATTERN_LENGTH;
			}
		}else if(i == 0) {
			text++;
		}
		else {
			i = table[i];
		}
	}

	return NULL;
}

int main(void) {
	unsigned char *result;
	result = kmp_search(original_text, original_pattern);
	if (result == NULL) {
		printf("Not Found.\n");
	}
	else {
		printf("Found.\n");
	}

	return EXIT_SUCCESS;
}
