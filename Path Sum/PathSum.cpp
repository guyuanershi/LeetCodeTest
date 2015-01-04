typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

// 迭代时传入新的sum值，新的sum值是减去当前节点的值
bool hasPathSum(TreeNode *root, int sum) {
	if (root == NULL) return false;

	if (sum == root->val && root->left == NULL && root->right == NULL) return true;

	bool hasPath = false;
	if (root->left != NULL)
	{
		hasPath = hasPathSum(root->left, sum - root->val);
		// if found in left tree, return directly
		if (hasPath)
			return true;
	}

	if (root->right != NULL)
	{
		//not found in left tree, continue to find in right tree
		hasPath = hasPathSum(root->right, sum - root->val);
	}

	// both left & right are NULL, this is a leaf
	return hasPath;
}

// 其实比较高效的写法是把两个递归或起来 (就是先搜索左边再搜索右边， 以后这种写法可以多学学)
// 不用判断左右叶子节点的状态
bool hasPathSum_good(TreeNode *root, int sum) {
	if (root == NULL) return false;

	if (sum == root->val && root->left == NULL && root->right == NULL) return true;

	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}