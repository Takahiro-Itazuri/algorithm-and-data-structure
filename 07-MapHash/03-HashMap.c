#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char *english;
	char *japanese;
} WORDSET;

typedef struct {
	WORDSET **data;
	unsigned int size;
} HASHTABLE;

unsigned int MakeHash2(char *str, unsigned int hashmax) {
	unsigned int n, length, hash, weight;

	length = strlen(str);
	for(n = weight = hash = 0; n < length; n++, weight++) {
		if(weight > 7) weight = 0;

		hash += (int)str[n] << (4 * weight);
	}

	return hash % hashmax;
}

unsigned int ReHash(HASHTABLE *hashtable, unsigned int firsthash) {
	unsigned int hashval, k;

	for(k = 1; k <= hashtable->size / 2; k++) {
		hashval = (firsthash + k * k) % hashtable->size;
		if(hashtable->data[hashval] == NULL) return hashval;
	}

	return -1;
}

void AddDataToMap(HASHTABLE *hashtable, WORDSET *newdata) {
	unsigned int hashval;

	hashval = MakeHash2(newdata->english, hashtable->size);
	
	if(hashtable->data[hashval] != NULL) {
		hashval = ReHash(hashtable, hashval);

		if (hashval == -1) {
			printf("Tried to insert %s into hash map, but failed.\n", newdata->english);
			return;
		}
	}

	hashtable->data[hashval] = newdata;
}

char* GetDataFromMap(HASHTABLE *hashtable, char *key) {
	unsigned int hashval, k;
	WORDSET *word;

	hashval = MakeHash2(key, hashtable->size);

	for(k = 0; k <= hashtable->size / 2; k++) {
		word = hashtable->data[(hashval + k * k) % hashtable->size];
		if (word != NULL) {
			if(strcmp(key, word->english) == 0) return word->japanese;
		}
	}

	return NULL;
}

WORDSET* DeleteDataFromMap(HASHTABLE *hashtable, char *key) {
	unsigned int hashval, k;
	WORDSET *word;

	hashval = MakeHash2(key, hashtable->size);

	for(k = 0; k <= hashtable->size / 2; k++) {
		word = hashtable->data[(hashval + k * k) % hashtable->size];
		if (word != NULL) {
			if(strcmp(key, word->english) == 0) {
				hashtable->data[(hashval + k * k) % hashtable->size] = NULL;
				return word;
			}
		}
	}

	return NULL;
}

void InitHashTable(HASHTABLE *hashtable, unsigned int size) {
	int n;
	hashtable->data = (WORDSET**)malloc(sizeof(WORDSET*) * size);
	for(n = 0; n < size; n++) {
		hashtable->data[n] = NULL;
	}
	hashtable->size = size;
}

void CleanUpHashTable(HASHTABLE *hashtable) {
	free(hashtable->data);
	hashtable->size = 0;
}

void PrintAllData(HASHTABLE *hashtable) {
	unsigned int n;
	for(n = 0; n < hashtable->size; n++) {
		if(hashtable->data[n] != NULL) {
			printf("%d:\t%s\t%s\n", n, hashtable->data[n]->english, hashtable->data[n]->japanese);
		}
	}
}

int main(void) {
	unsigned int n;
	char key[64], *japanese;
	HASHTABLE hashtable;
	WORDSET *wordfound;
	WORDSET word[5] = {
		{"dolphin", "イルカ"}, {"beluga", "シロイルカ"},
		{"grampus", "シャチ"}, {"medusa", "海月"},
		{"otter", "カワウソ"}
	};

	InitHashTable(&hashtable, 503);

	for(n = 0; n < 5; n++) {
		AddDataToMap(&hashtable, &word[n]);
	}

	do {
		printf("Select operation (1:Search, 2:Delete, 3:Display, 0:Finish)>");
		scanf("%d", &n);
		switch(n) {
		case 1:
			printf("Input an english word: ");
			scanf("%s", key);
			japanese = GetDataFromMap(&hashtable, key);
			if(japanese != NULL) printf("%s means %s.\n", key, japanese);
			else printf("Not found.\n");
			break;
		case 2:
			printf("Input an english word: ");
			scanf("%s", key);
			wordfound = DeleteDataFromMap(&hashtable, key);
			if(wordfound != NULL) printf("Complete to delete.\n");
			else printf("Not found.\n");
			break;
		case 3:
			PrintAllData(&hashtable);
			break;
		}
	} while(n != 0);

	CleanUpHashTable(&hashtable);

	return 0;
}
