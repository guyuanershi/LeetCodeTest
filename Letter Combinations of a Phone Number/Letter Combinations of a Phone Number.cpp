string originalstr = "abcdefghijklmnopqrstuvwxyz";

//using binary tree
typedef struct Node
{
	string value;
	Node *parent;
	Node *child;
};

void test(Node *node, string str, vector<string>& vects)
{
	if (node == NULL)
	{
		vects.push_back(str);
		return;
	}

	for (int i = 0; i < node->value.length(); i++)
	{
		string onestr = node->value.substr(i, 1);
		string tmp = str;
		test(node->child, tmp.append(onestr), vects);
	}

}

vector<string> letterCombinations(string digits) {
	vector<string> mapping = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	Node *root = NULL, *tmp;
	for (int i = 0; i < digits.length(); i++)
	{
		//char digit = digits.at(i);
		//int n;
		//sscanf(&digit, "%d", &n);
		int n = digits.at(i) - '0';
		if (n <= 1) continue;
		Node *pn = new Node();
		pn->value = mapping.at(n - 2);
		pn->parent = NULL;
		pn->child = NULL;
		if (root == NULL)
		{
			root = pn;
			tmp = pn;
		}
		else
		{
			pn->parent = tmp;
			tmp->child = pn;
			tmp = pn;
		}
	}

	vector<string> vects;
	test(root, "", vects);

	delete root;
	return vects;
}

// there are someother way to do it without recursion