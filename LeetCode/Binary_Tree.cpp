/*
����һ���������������������� ������

ʾ��:

����: [1,null,2,3]
   1
	\
	 2
	/
   3

���: [1,3,2]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {

		vector<int> res;
         
		inOrderFunc(root, res);

		return res;
	}
	void inOrderFunc(TreeNode* root, vector<int> &res) {

		if (root != NULL) {
		
			inOrderFunc(root->left, res);

			res.push_back(root->val);
			
			inOrderFunc(root->right,res);
		}

		//����������д�����ã���root��nullptrʱ�ᱨ��
		//if (root->left)
		//	func(root->left, res);
		//if (root != NULL) {
		//	res.push_back(root->val);
		//}
		//if(root->right)
	    // (root->right,res);
	}
	vector<int> preorderTraversal(TreeNode* root) {

		vector<int> res;

		preOrderFunc(root, res);

		return res;
	}
	void preOrderFunc(TreeNode* root, vector<int> &res) {

		if (root != NULL) {

			res.push_back(root->val);

			preOrderFunc(root->left, res);

			preOrderFunc(root->right, res);
		}
	}
	vector<int> postorderTraversal(TreeNode* root) {

		vector<int> res;

		postOrderFunc(root, res);

		return res;
	}
	void postOrderFunc(TreeNode* root, vector<int> &res) {

		if (root != NULL) {

			postOrderFunc(root->left, res);

			postOrderFunc(root->right, res);

			res.push_back(root->val);
		}
	}



	TreeNode* creatBinaryTree(vector<int> &tree_vec)
	{

		if (tree_vec.empty())
		{
			cout << "�����β�� null" << endl;
			return NULL;
		}

		TreeNode* root_node = new TreeNode(0);

		int item = tree_vec[0];
		if (item == 0) {
			root_node = NULL;
			tree_vec.erase(tree_vec.begin());

			cout << "�����ڵ㣺 null" << endl;
		}
		else {
			root_node->val = item;
			tree_vec.erase(tree_vec.begin());

			cout << "�����ڵ�" << item << endl;
			root_node->left = creatBinaryTree(tree_vec);
			root_node->right = creatBinaryTree(tree_vec);
		}

		return root_node;
	}

	void deleteBinaryTree(TreeNode* root)
	{

	}

};

//int main()
//{
//	vector<int> tree_vec = { 1,0,2,3 }; //-1��ʾ�ڵ�Ϊ��
//
//	Solution solu;
//
//	TreeNode* root = solu.creatBinaryTree(tree_vec);
//
//	vector<int> res =solu.inorderTraversal(root);
//
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//	system("pause");
//	return 0;
//}