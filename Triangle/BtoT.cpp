int minimumTotal(vector<vector<int> > &triangle) {
	vector<int> minlen(triangle.back()); //initial the first vector
	int row = triangle.size();

	// start from the second row from the bottom
	for (size_t r = row - 2; r < row; r--)
	{
		for (size_t i = 0; i < r; i++)
		{
			minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[r][i];
		}
	}
	return minlen[0];
}