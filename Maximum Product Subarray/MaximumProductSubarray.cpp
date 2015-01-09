int maxProduct(int A[], int n) {
	if (n == 0) return 0;
	if (n == 1) return A[0];

	int cache = A[n - 1];
	int max = A[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		int a1 = A[i] * A[i + 1];
		cache = A[i] * cache;
		if (cache == 0)
			cache = A[i];

		int _m = a1;
		if (cache > a1)
			_m = cache;
		if (A[i] > _m)
			_m = A[i];
		if (A[i + 1] > _m)
			_m = A[i + 1];
		if (_m > max)
			max = _m;
	}

	cache = A[0];
	for (int i = 0; i < n - 1; i++)
	{
		int a1 = A[i] * A[i + 1];
		cache = A[i + 1] * cache;
		if (cache == 0)
			cache = A[i + 1];

		int _m = a1;
		if (cache > a1)
			_m = cache;
		if (A[i] > _m)
			_m = A[i];
		if (A[i + 1] > _m)
			_m = A[i + 1];
		if (_m > max)
			max = _m;
	}
	return max;
}

int maxProduct_1(int A[], int n) {
	if (n == 0) {
		return 0;
	}

	int maxherepre = A[0];
	int minherepre = A[0];
	int maxsofar = A[0];
	int maxhere, minhere;

	for (int i = 1; i < n; i++) {
		maxhere = max(max(maxherepre * A[i], minherepre * A[i]), A[i]);
		minhere = min(min(maxherepre * A[i], minherepre * A[i]), A[i]);
		maxsofar = max(maxhere, maxsofar);
		maxherepre = maxhere;
		minherepre = minhere;
	}
	return maxsofar;
}

int maxProduct_2(int A[], int n) {
	if (n < 1) return 0;
	int r = A[0];
	int max_p = A[0];
	// max_p is the maximum product that could be achieved
	// from the subarrays ending at the current position.
	int min_p = A[0];
	// The minimum product that could be achieved from 
	// the subarrays ending at the current position.
	for (int i = 1; i<n; i++){
		// The maximum or minimum product of the subarrays 
		// ending at the current position could be achieved from the next three values.
		int a = max_p*A[i];
		// the max product of subarray ending at the previous position multiply the current value
		int b = min_p*A[i];
		// the minimum product of subarray ending at the previous position multiply the current value
		int c = A[i];
		// the current value
		max_p = max(max(a, b), c);
		min_p = min(min(a, b), c);
		if (max_p > r) r = max_p;
	}
	return r;
}