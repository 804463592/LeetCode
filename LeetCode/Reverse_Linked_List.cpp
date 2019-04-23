
/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

*/

/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/


#include<iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//迭代做法,迭代法比递归法好理解
		ListNode *pPre = NULL;
		ListNode *pNode = head;
		ListNode *pNext = NULL;

		while (pNode)
		{
			//保存下一个节点
			pNext = pNode->next;
			//反转pNode节点
			pNode->next = pPre;
			//pPre,pNode向后移动
			pPre = pNode;
			pNode = pNext;

		}
		//pPre最后保存的是反转后的链表的头节点
		return pPre;
	}
	ListNode* reverseListRecursion(ListNode*head)
	{
		//递归的版本
		if (head == NULL || head->next == NULL) return head;
		ListNode* p = reverseListRecursion(head->next);
		head->next->next = head;
		head->next = NULL;
		return p;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//反转从位置 m 到 n 的链表,迭代法
		if (m == n) return head;

		ListNode* reverseHead = NULL;
		ListNode* pM = NULL; //pM,pN为边界之外的第一个点，
		ListNode* pMnext = NULL; //pM接着的点
		ListNode* pN = new ListNode(0); 

		ListNode* pPre = NULL;
		ListNode* pNode = head;
		ListNode* pNext = NULL;
		int i = 1;

		if (m > 1)
		{
			reverseHead = head;
			while (pNode &&i < n + 1)
			{
				if (i < m) //只移动，不反向
				{
					pNext = pNode->next;

					//移动
					pPre = pNode;
					pNode = pNext;
				}
				else if (i == m) //pM赋值，并开始反转
				{
					pM = pPre;
					pMnext = pNode; //保存该节点，后面在N节点处为其next赋值
					pNext = pNode->next;
					//指向空指针
					pNode->next = pN;  //这里实际上没什么用，因为PN此时是一个空指针，相当于pNode->next = NULL;因此需要保存pMnext,后面pMnext再指向pN

					//移动
					pPre = pNode;
					pNode = pNext;

				}
				else if (i > m && i < n)
				{
					pNext = pNode->next;
					//反转
					pNode->next = pPre;
					//移动
					pPre = pNode;
					pNode = pNext;

				}
				else if (i == n)
				{
					pNext = pNode->next;
					pN = pNext;

					//PM,  pN
					pM->next = pNode;
					pMnext->next = pN;
					pNode->next = pPre;

				}
				else
				{
					pNode = pNode->next;
				}
				i++;
			}
		}
		else if (m == 1)
		{
			while (pNode && i < n + 1)
			{
				if (i < n)
				{
					pNext = pNode->next;
					//反转
					pNode->next = pPre;
					//移动
					pPre = pNode;
					pNode = pNext;
				}
				else if (i == n)
				{
					pNext = pNode->next;
					//头节点接到pNext
					head->next = pNext;
					//反转
					pNode->next = pPre;

					//可能的新的头节点
					reverseHead = pNode;
					//可以不继续移动了
				}
				else
				{
					pNode = pNode->next;
				}
				i++;
			}
		}

		return reverseHead;
	}

	ListNode* createNodeList(vector<int>input_vec) {

		if (input_vec.empty())
		{
			return nullptr;
		}

		ListNode* head_node = new ListNode(input_vec[0]);
		ListNode* node = head_node;
		for (int i = 1; i < input_vec.size(); i++)
		{
			//ListNode* node = new ListNode(input_vec[i]);
			node->next = new ListNode(input_vec[i]);
			node = node->next;
		}
		return head_node;
	}

	ListNode* deleteNodeList(ListNode*list_node)
	{  //方法二，每次都删除头节点
		/*
		这里要特别注意一点，虽然这里的参数是指针，但是仍然是复制过来的（只是两者指向的是同一块内存而已）
		因此，虽然最后指针list_node最后变为NULL了，但是函数外面的指针list_node仍然不是NULL,因此函数需要返回NULL指针
		*/
		while (list_node)
		{
			ListNode* p = list_node;
			list_node = list_node->next;
			delete p;
		}
		//list_node = nullptr;
		return list_node;
	}

	void showNodeList(ListNode*head)
	{
		ListNode* p = head;
		while (p)
		{
			std::cout << p->val << " ";
			p = p->next;
		}

	}

};

int main() {

	vector<int> ivec = { 3,5,6 };
	Solution solu;
	ListNode* list_node = solu.createNodeList(ivec);

	ListNode* head = solu.reverseBetween(list_node, 1, 3);

	solu.showNodeList(head);



	system("pause");
	return 0;
}