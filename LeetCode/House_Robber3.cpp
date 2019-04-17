/*
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。除了“根”之外，
每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

	 3
	/ \
   2   3
	\   \
	 3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

	 3
	/ \
   4   5
  / \   \
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

*/

#include<iostream>
#include<vector>
#include<math.h>

#include <unordered_map>
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
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	unordered_map<TreeNode *, int> sums;
	//map<TreeNode *, int> sums; //使用map好像差别也不太大
	int rob2(TreeNode* root) {

		//递归先序，遍历二叉树
		//if (root!= NULL) 
		//{
		//	cout << root->val << endl;
		//	rob(root->left);
		//	rob(root->right);
		//}
		int result1(0),result2(0),res = 0;
		if (root==nullptr)
		{
			return 0;
		}
		//如果某个节点，已经计算过，则不再重复计算
		if (sums.count(root)) return sums[root];
		//考虑盗窃该节点
		if(root->left)
		{
			result1 += rob(root->left->left)+rob(root->left->right);
		}
		if (root->right)
		{
			result1 += rob(root->right->left)+rob(root->right->right);
		}
		result1 += root->val;
		//不考虑盗窃该节点
		result2 = rob(root->left) + rob(root->right);

		res = max(result1, result2);
		sums[root] = res;
		return res;

		//下面注释掉的这种思路，把左右子节点放一起考虑，实在是大错特错，好好反思！！！
		//else if (root->right != NULL && root->left == NULL && root->right->left == NULL && root->right->right == NULL)
		//{
		//	result = max(root->val, root->right->val);
		//}
		////有三个节点
		//else if (root->left != NULL &&root->right!=NULL && root->left->left==NULL&&root->left->right ==NULL
		//	&&root->right->left==NULL &&root->right->right==NULL
		//	)
		//{
		//	result= max(root->val, root->left->val + root->right->val);
		//}
		//else{
		//	result = max(root->val + rob(root->left->left) +rob(root->left->right) +rob(root->right->left)
		//		+ rob(root->right->right), rob(root->left) + rob(root->right));
		//}
	}

	
public:
	int rob(TreeNode* root) {
		return tryRob(root);
	}
	int tryRob(TreeNode* node) {
		if (!node) return 0;
		if (sums.count(node)) return sums[node];
		//偷取该节点
		int res1 = 0;
		if (node->left) {
			res1 += (tryRob(node->left->left) + tryRob(node->left->right));
		}
		if (node->right) {
			res1 += (tryRob(node->right->left) + tryRob(node->right->right));
		}
		res1 += node->val;
		//不偷取该节点
		int res2 = tryRob(node->left) + tryRob(node->right);
		sums[node] = max(res1, res2);
		return sums[node];
	}
};

int main()
{
	Solution solu;
	/*构造如下的二叉树，结果是7：
 3
/ \
2   3
 \   \
  3   1
 */
	TreeNode node1(3), node2(2), node3(3), node4(3), node5(1);
	node1.left = &node2;
	node1.right = &node3;
	node2.right = &node4;
	node3.right = &node5;

	/* 构造如下二叉树，结果应该是9
	 3
	/ \
   4   5
  / \   \
 1   3   1
	*/
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);

	//3
	TreeNode *root2 = new TreeNode(2);
	root2->left = new TreeNode(3);
	root2->left->left = new TreeNode(1);

	//cout << "&node1结果是：" <<solu.rob(&node1) << endl;
	cout << "root2结果是：" << solu.rob2(nullptr) << endl;
	system("pause");
	return 0;
}