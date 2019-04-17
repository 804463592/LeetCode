/*
���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ������������ֻ��һ����ڣ����ǳ�֮Ϊ�����������ˡ�����֮�⣬
ÿ����������ֻ��һ��������������֮������һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö���������
�������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������

�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�

ʾ�� 1:

����: [3,2,3,null,3,null,1]

	 3
	/ \
   2   3
	\   \
	 3   1

���: 7
����: С͵һ���ܹ���ȡ����߽�� = 3 + 3 + 1 = 7.
ʾ�� 2:

����: [3,4,5,1,3,null,1]

	 3
	/ \
   4   5
  / \   \
 1   3   1

���: 9
����: С͵һ���ܹ���ȡ����߽�� = 4 + 5 = 9.

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
	//map<TreeNode *, int> sums; //ʹ��map������Ҳ��̫��
	int rob2(TreeNode* root) {

		//�ݹ����򣬱���������
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
		//���ĳ���ڵ㣬�Ѿ�������������ظ�����
		if (sums.count(root)) return sums[root];
		//���ǵ��Ըýڵ�
		if(root->left)
		{
			result1 += rob(root->left->left)+rob(root->left->right);
		}
		if (root->right)
		{
			result1 += rob(root->right->left)+rob(root->right->right);
		}
		result1 += root->val;
		//�����ǵ��Ըýڵ�
		result2 = rob(root->left) + rob(root->right);

		res = max(result1, result2);
		sums[root] = res;
		return res;

		//����ע�͵�������˼·���������ӽڵ��һ���ǣ�ʵ���Ǵ���ش��ú÷�˼������
		//else if (root->right != NULL && root->left == NULL && root->right->left == NULL && root->right->right == NULL)
		//{
		//	result = max(root->val, root->right->val);
		//}
		////�������ڵ�
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
		//͵ȡ�ýڵ�
		int res1 = 0;
		if (node->left) {
			res1 += (tryRob(node->left->left) + tryRob(node->left->right));
		}
		if (node->right) {
			res1 += (tryRob(node->right->left) + tryRob(node->right->right));
		}
		res1 += node->val;
		//��͵ȡ�ýڵ�
		int res2 = tryRob(node->left) + tryRob(node->right);
		sums[node] = max(res1, res2);
		return sums[node];
	}
};

int main()
{
	Solution solu;
	/*�������µĶ������������7��
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

	/* �������¶����������Ӧ����9
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

	//cout << "&node1����ǣ�" <<solu.rob(&node1) << endl;
	cout << "root2����ǣ�" << solu.rob2(nullptr) << endl;
	system("pause");
	return 0;
}