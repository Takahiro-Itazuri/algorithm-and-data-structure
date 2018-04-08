#include<stdio.h>
#include<stdlib.h>

#define N 5

typedef struct {
	char* title;
	char* author;
	int bookId;
	int available;
} book;

book* bookarray[N];

void initdata(void) {
	int n;

	for(n = 0; n < N; n++) {
		bookarray[n] = (book*)malloc(sizeof(book));
	}

	bookarray[0]->title = "book0";
	bookarray[1]->title = "book1";
	bookarray[2]->title = "book2";
	bookarray[3]->title = "book3";
	bookarray[4]->title = "book4";
	bookarray[0]->author = "author0";
	bookarray[1]->author = "author1";
	bookarray[2]->author = "author2";
	bookarray[3]->author = "author3";
	bookarray[4]->author = "author4";
	bookarray[0]->bookId = 1000;
	bookarray[1]->bookId = 502;
	bookarray[2]->bookId = 731;
	bookarray[3]->bookId = 628;
	bookarray[4]->bookId = 1;
	bookarray[0]->available = 1;
	bookarray[1]->available = 0;
	bookarray[2]->available = 0;
	bookarray[3]->available = 1;
	bookarray[4]->available = 1;
}

void cleanupdata(void) {
	int n;
	for(n = 0; n < N; n++) {
		free(bookarray[n]);
	}
}

void sortbook(int bottom, int top) {
	int lower, upper, div;
	book* temp;

	if(bottom >= top) {
		return;
	}

	div = bookarray[bottom]->bookId;

	for(lower = bottom, upper = top; lower < upper;) {
		while(lower < upper && bookarray[lower]->bookId < div) {
			lower++;
		}
		while(lower < upper && bookarray[upper]->bookId > div) {
			upper--;
		}
		if (lower < upper) {
			temp = bookarray[lower];
			bookarray[lower] = bookarray[upper];
			bookarray[upper] = temp;
			lower++;
			upper--;
		}
	}
	
	sortbook(bottom, upper);
	sortbook(upper + 1, top);
}

int searchbook(book* books[], int size, int key) {
	int left, right, mid;

	left = 0;
	right = size;
	while(left < right) {
		mid = (left + right) / 2;

		if(books[mid]->bookId < key) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	if (books[left]->bookId == key) {
		return left;
	}

	return -1;
}

int main(void) {
	int key, position;

	initdata();
	sortbook(0, N-1);

	while(1) {
		printf("Input book id (finished by 0): ");
		scanf("%d", &key);
	
		if(key == 0) break;

		position = searchbook(bookarray, N - 1, key);

		if (position == -1) {
			printf("Searched book is not found.\n");
		}
		else {
			printf("The next book is found---\n[title]%s\n[author]%s\n[bookId]%d\n", bookarray[position]->title, bookarray[position]->author, bookarray[position]->bookId);

			if (bookarray[position]->available == 0) {
				printf("This book is not available.\n");
			}
			else {
				printf("This boo is available.\n");
			}
		}
	}
	
	cleanupdata();
	return 0;
}
