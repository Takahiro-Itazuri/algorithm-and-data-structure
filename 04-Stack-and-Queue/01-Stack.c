#define STACK_MAX 10

double stack[STACK_MAX];
int stack_top = 0;

void stack_push(double val) {
	if (stack_top == STACK_MAX) {
		printf("Error: Stack Overflow\n");
		exit(EXIT_FAILURE);
	}
	else {
		stack[stack_top] = val;
		stack_top++;
	}
}

double stack_pop(void) {
	if (stack_top == 0) {
		printf("Error: Stack Underflow\n");
		eixt(EXIT_FAILURE);
		return 0;
	}
	else {
		stack_top--;
		return stack[stack_top];
	}
}
