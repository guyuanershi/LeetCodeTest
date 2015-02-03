bool dfs(string s, unordered_set<string> &dict, int start, vector<string> &path, vector<vector<bool>> &map, vector<string> &ret)
{
	if (start == s.size())
	{
		string temp = "";
		for (int i = 0; i < path.size(); i++)
		{
			if (temp == "") temp = path.at(i);
			else temp += " " + path.at(i);
		}
		ret.push_back(temp);
		return true;
	}

	bool b = false;
	for (int i = 0; i < s.size() - start; i++)
	{
		//cout << start << endl;
		if (map[i][start])
		{
			string substr = s.substr(start, i + 1);
			path.push_back(substr);
			b = dfs(s, dict, start + i + 1, path, map, ret);
			path.pop_back();
		}

	}

	// 减少重复
	// 如果已经走过的都不能满足，那么说明不能用
	// 可以全部设为false
	if (!b)
		for (auto m : map[s.size() - start - 1])
		{
			m = false;
		}
	return b;
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
	vector<string> ret;
	vector<string> path;

	vector<vector<bool>> map(s.size(), vector<bool>(s.size(), false));

	for (int len = 1; len <= s.size(); len++)
	{
		for (int j = 0; j <= s.size() - len; j++)
		{
			string str = s.substr(j, len);
			map[len - 1][j] = dict.find(str) != dict.end();
		}
	}
	
	dfs(s, dict, 0, path, map, ret);
	return ret;
}