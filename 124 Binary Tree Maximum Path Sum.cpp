#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* initTreeRoot(int val)
{
	return new TreeNode(val);
}

TreeNode* addLeftChild(TreeNode* node, int val)
{
	TreeNode* lChild = new TreeNode(val);
	node->left = lChild;
	return lChild;
}

TreeNode* addRightChild(TreeNode* node, int val)
{
	TreeNode* rChild = new TreeNode(val);
	node->right = rChild;
	return rChild;
}

void destroyTree(TreeNode* root)
{
	if (root->left) {
		destroyTree(root->left);
	}
	if (root->right) {
		destroyTree(root->right);
	}

	delete root;

}

void inorderPrint(TreeNode* root)
{
	if (root->left) {
		inorderPrint(root->left);
	}

	cout << root->val <<" ";

	if (root->right) {
		inorderPrint(root->right);
	}
}


int maxSum;

int maxPath(TreeNode* root)
{
	int tMax = root->val;

	if (root->left && root->right)
	{
		int lMax = maxPath(root->left);
		int rMax = maxPath(root->right);

		if (lMax > 0)
			tMax += lMax;
		
		if (rMax > 0)
			tMax += rMax;

		maxSum = max(maxSum,tMax);
		
		int tmp = max(rMax,lMax);
		if (tmp > 0)
			return root->val + tmp;
		else
			return root->val;
	}
	else if (root->left && !root->right)
	{
		int lMax = maxPath(root->left);
		if (lMax > 0)
			tMax += lMax;

		maxSum = max(maxSum,tMax);
		return tMax;
	}
	else if (root->right && !root->left)
	{
		int rMax = maxPath(root->right);
		if (rMax > 0)
			tMax += rMax;

		maxSum = max(maxSum,tMax);
		return tMax;
	}
	else
	{
		maxSum = max(maxSum,tMax);
		return tMax;
	}
}

int maxPathSum(TreeNode* root) 
{
	if (!root)
		return 0;

	maxSum = -99999;

	maxPath(root);

	return maxSum;
}

int main(){

	TreeNode* root = initTreeRoot(1);
	TreeNode* n1 = addLeftChild(root, 2);
	TreeNode* n2 = addRightChild(root, 3);
	TreeNode* n3 = addLeftChild(n1, 4);
	TreeNode* n4 = addRightChild(n1, 5);
	TreeNode* n5 = addLeftChild(n2, 8);
	TreeNode* n6 = addRightChild(n4, 7);

	cout << maxPathSum(root) <<endl;

	destroyTree(root);
	return 1;
}