#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STAPLE_SMALL 1
#define STAPLE_MEDIUM 2
#define STAPLE_LARGE 3

typedef struct _tagstaple {
	int line;
	int column;
	int type;

	struct _tagstaple *staple_next;
	struct _tagstaple *staple_prev;
} staple;

staple* staple_head = NULL;
staple* staple_last = NULL;

void stack_push(int line, int column, int type) {
	staple *staple_new;

	staple_new = (staple*)malloc(sizeof(staple));
	if (staple_new == NULL) {
		printf("Error: Stack Overflow\n");
		exit(EXIT_FAILURE);
		return;
	}

	staple_new->line = line;
	staple_new->column = column;
	staple_new->type = type;

	staple_new->staple_next = NULL;
	staple_new->staple_prev = staple_last;
	staple_last = staple_new;
	if (staple_head == NULL) {
		staple_head = staple_new;
	}
}

int stack_pop(staple *ret) {
	staple *temp_staple;

	if (staple_head == NULL) {
		printf("Error: Stack Underflow\n");
		return 0;
	}

	ret->line = staple_last->line;
	ret->column = staple_last->column;
	ret->type = staple_last->type;
	ret->staple_next = ret->staple_prev = NULL;
	temp_staple = staple_last;

	if (staple_last->staple_prev == NULL) {
		staple_head = NULL;
	}
	else {
		staple_last->staple_prev->staple_next = NULL;
	}

	staple_last = staple_last->staple_prev;

	free(temp_staple);

	return 1;
}

int main(void) {
	char buffer[4096];
	int i, len, line = 1, carryover = 0;
	staple open;

	for(;;) {
		if(fgets(buffer, 4096, stdin) == NULL) {
			break;
		}

		len = strlen(buffer);
		if (len == 0) continue;

		for(i = 0; i < len; i++) {
			switch(buffer[i]) {
			case '(':
				stack_push(line, carryover + i + 1, STAPLE_SMALL);
				break;
			case '{':
				stack_push(line, carryover + i + 1, STAPLE_MEDIUM);
				break;
			case '[':
				stack_push(line, carryover + i + 1, STAPLE_LARGE);
				break;
			case ')':
				if (stack_pop(&open) == 0) {
					printf("Wrong correspondence\n");
					printf("Left parenthesis corresponding %d-th line %d-th column right parenthesis is not found.\n", line, carryover + i + 1);
					return EXIT_FAILURE;
				}
				if (open.type != STAPLE_SMALL) {
					printf("Wrong correspondence\n");
					printf("Types of %d-th line %d-th column left parenthesis and %d-line %d-th column right parenthesis are different.\n", open.line, open.column, line, carryover + i + 1);
					return EXIT_FAILURE;
				}
				break;
			case '}':
				if (stack_pop(&open) == 0) {
					printf("Wrong correspondence\n");
					printf("Left parenthesis corresponding %d-th line %d-th column right parenthesis is not found.\n", line, carryover + i + 1);
					return EXIT_FAILURE;
				}
				if (open.type != STAPLE_MEDIUM) {
					printf("Wrong correspondence\n");
					printf("Types of %d-th line %d-th column left parenthesis and %d-line %d-th column right parenthesis are different.\n", open.line, open.column, line, carryover + i + 1);
					return EXIT_FAILURE;
				}
				break;
			case ']':
				if (stack_pop(&open) == 0) {
					printf("Wrong correspondence\n");
					printf("Left parenthesis corresponding %d-th line %d-th column right parenthesis is not found.\n", line, carryover + i + 1);
					return EXIT_FAILURE;
				}
				if (open.type != STAPLE_LARGE) {
					printf("Wrong correspondence\n");
					printf("Types of %d-th line %d-th column left parenthesis and %d-line %d-th column right parenthesis are different.\n", open.line, open.column, line, carryover + i + 1);
					return EXIT_FAILURE;
				}
				break;
			}
		}
	}

	if (staple_head != NULL) {
		printf("Wrong Correspondence\n");
		printf("Left parenthesises are too many.\n");
		return EXIT_FAILURE;
	}

	printf("Correct Correspondence\n");
	return 0;
}
