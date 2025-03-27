#include <iostream>
#include <algorithm>

// 时间复杂度：O(N)，其中 N 为二叉树的节点数

using namespace std;

struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};


class Solution {

	int ans;
	int depth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int depthL = depth(root->left); // 左儿子为根的子树深度
		int depthR = depth(root->right); // 右儿子为根的子树深度
		ans = max(ans, depthL + depthR + 1);
		return max(depthL, depthR) + 1; // 返回返回该节点为根的子树的深度

	}


public:
	int diameterOfBinaryTree(TreeNode* root) {
		ans = 1;
		depth(root);
		return (ans - 1);
	
	}

};