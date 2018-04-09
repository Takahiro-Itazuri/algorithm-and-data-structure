unsigned int MakeHash2(char *str, unsigned int hashmax) {
	unsigned int n, length, hash, weight;

	length = strlen(str);
	for(n = weight = hash = 0; n < length; n++, weight++) {
		if (weight > 7) weight = 0;
		hash += (int)str[n] << (4 * weight);
	}

	return hash % hashmax;
}
