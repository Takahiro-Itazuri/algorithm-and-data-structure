#include<stdio.h>
#include<stdlib.h>

#define PATTERN_LENGTH 4
unsigned char original_text[] = "On a dark desert highway, cool wind in my hair,";
unsigned char original_pattern[PATTERN_LENGTH + 1] = "wind";

#define _SHOW_WORKING_

unsigned char *bm_search(unsigned char *text, unsigned char *pattern) {
	int table[256];
	int text_idx, pattern_idx, text_len, i;

	for(i = 0; i < 256; i++) {
		table[i] = PATTERN_LENGTH;
	}

	for(i = 0; i < PATTERN_LENGTH - 1; i++) {
		table[pattern[i]] = PATTERN_LENGTH - i - 1;
	}

	for(text_len = 0; text[text_len] != '\0'; ++text_len){}

	text_idx = PATTERN_LENGTH - 1;

	while(text_idx < text_len) {
#ifdef _SHOW_WORKING_
		printf("original text:%s \n      pattern:", original_text);
		for(i = 0; i < text_idx - PATTERN_LENGTH + 1; i++) {
			printf(" ");
		}
		printf("%s \n", pattern);
#endif
		pattern_idx = PATTERN_LENGTH - 1;
		while(text[text_idx] == pattern[pattern_idx]) {
			if(pattern_idx == 0) return text + text_idx;
			text_idx--;
			pattern_idx--;
		}

		if (table[text[text_idx]] > PATTERN_LENGTH - pattern_idx) {
			text_idx += table[text[text_idx]];
		}
		else {
			text_idx += PATTERN_LENGTH - pattern_idx;
		}
	}

	return NULL;
}

int main(void) {
	unsigned char *result;
	result = bm_search(original_text, original_pattern);
	if(result == NULL) {
		printf("Not Found.\n");
	}
	else {
		printf("Found.\n");
	}

	return EXIT_SUCCESS;
}
