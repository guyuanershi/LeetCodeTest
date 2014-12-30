#include "stdafx.h"
#include "T.h"
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
	if (triangle.size() == 0) return 0;

	vector<vector<int>> cache;

	for (size_t r = 0; r < triangle.size(); r++)
	{
		vector<int> v;
		cache.push_back(v);
		if (r == 0)
		{
			cache[r].push_back(triangle[r].at(r));
			continue;
		}

		for (size_t j = 0; j < triangle[r].size(); j++)
		{
			if (j == 0)
			{
				int m = cache[r - 1][0] + triangle[r][0];
				cache[r].push_back(m);
			}
			else if (j > r - 1)
			{
				int m = cache[r - 1][r - 1] + triangle[r][j];
				cache[r].push_back(m);
			}
			else
			{
				int m1 = cache[r - 1][j - 1];
				int m2 = cache[r - 1][j];
				cache[r].push_back(fmin(m1, m2) + triangle[r][j]);
			}
		}
	}

	int s = cache.size() - 1;
	int minnum = cache[s][0];
	for (size_t i = 1; i < cache[s].size(); i++)
	{
		minnum = fmin(minnum, cache[s][i]);
	}
	return minnum;
}
