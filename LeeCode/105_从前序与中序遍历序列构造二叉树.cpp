#include <vector>

using namespace std;

class TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}

};


// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/2361558/105-cong-qian-xu-yu-zhong-xu-bian-li-xu-4lvkz

// 分治方法（先根据前序遍历确认根节点，再根据中序遍历确认左右子树范围，再根据前序遍历确认左右子树的根）
// 注意！！！只适用于“无重复节点值”的二叉树
// 使用哈希表提升时间复杂度

class Solution {

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		
	
	
	}

};