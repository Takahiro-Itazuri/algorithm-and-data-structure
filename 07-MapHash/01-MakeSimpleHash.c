unsigned int MakeHash1(char *str, unsigned int hashmax) {
	unsigned int n, length, hash;

	length = strlen(str);
	for(n = 0, hash = 0; n < length; n++) {
		hash += (int)str[n];
	}

	return hash % hashmax;
}
