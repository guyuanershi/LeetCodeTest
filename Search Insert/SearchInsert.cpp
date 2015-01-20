int searchInsert(int A[], int n, int target) {
	int bottom = 0;
	int top = n - 1;
	int middle = 0;
	while (bottom < top)
	{
		middle = (bottom + top) / 2;

		if (A[middle] == target) return middle;
		if (target > A[middle])
		{
			bottom = middle + 1;
		}
		else
		{
			top = middle - 1;
		}
	}

	return A[bottom] > target ? bottom : bottom + 1;
}