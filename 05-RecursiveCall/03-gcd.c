int gdc(int a, int b) {
	int i;
	for(i = a; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			break;
		}
	}
	return i;
}
