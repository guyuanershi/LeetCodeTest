// 超出时间
// 这个思路是找到回文，如果是保存再继续在这个回文上往下找
// 如果不是，那么继续分解往下找

// 时间还可以缩短在isLoop()，可以记录

// 看看其他方法吧。。。
bool isLoop(string s)
{
	int count = s.length();
	for (int f = 0, e = count - 1; f < e; f++, e--)
	{
		if (s[f] != s[e]) return false;
	}
	return true;
}


vector<vector<string>> ret;
bool hasData(vector<string> vect)
{
	for (int i = 0; i < ret.size(); i++)
	{
		if (ret.at(i) == vect) return true;
	}
	return false;
}


void partition_my(vector<string> vt)
{
	if (hasData(vt)) return;
	for (int j = 0; j < vt.size(); j++)
	{
		string s = vt.at(j);
		for (int i = 1; i < s.length(); i++)
		{
			vector<string> vect(vt);
			string left = s.substr(0, i);
			string right = s.substr(i, s.length() - i);

			// remove the current string
			vect.erase(vect.begin() + j);
			// insert new split string
			vect.insert(vect.begin() + j, right);
			vect.insert(vect.begin() + j, left);

			if (isLoop(left) && isLoop(right) && !hasData(vect))
			{
				// save to answer
				ret.push_back(vect);
			}

			//continue
			partition_my(vect);
		}
	}
}


vector<vector<string>> partition(string s) {

	vector<string> vect;
	vect.push_back(s);
	if (isLoop(s))
		ret.push_back(vect);
	partition_my(vect);
	return ret;
}
