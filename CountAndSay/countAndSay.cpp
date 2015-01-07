// 这个问题不是很有趣，基本思路就是读取字符串，按顺序判断相同字符的个数
// 输出字符个数+字符，如此循环
// 对于c++花了很长时间在int=》string上，很麻烦，后来知道从c++11，开始有一个函数to_string()
// 比较方便

// 虽然这个代码不是最好的写法，可以再重构下，不过也就这样了
string countAndSay(int n)
{
	string str = "1";
	string res = "1";
	while (--n > 0)
	{
		res = "";
		int count = 0;
		char f = str[0];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (f == str[i])
			{
				count++;
			}
			else
			{
				res += to_string(count);
				res += f;
				f = str[i];
				count = 1;
			}
		}

		if (count != 0)
		{
			res += to_string(count);;
			res += f;
		}
		str = res;
	}
	return res;
}