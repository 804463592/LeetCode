/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		/*
		使用双指针方法（即马拉车的方式、相对指针)
		*/
		if (!head->next && n==1)
		{
			return nullptr;
		}

		//if (n<=0)
		//{
		//	return head;
		//}

		ListNode* pfast = head, *pslow = head;
		//pfast先走n步
		int i = 0;
		while (i < n + 1)
		{
			if(pfast) pfast = pfast->next;
			else return head->next; //因为n保证是合法的，说明需要删除的是头节点，或者说只能删除头节点
			i++;
		}

		//双指针同时行动，直到pfast到达终点
		while (pfast)
		{
			pfast = pfast->next;
			pslow = pslow->next;
		}
		pslow->next = pslow->next->next;
	
		return head;
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

	void deleteNodeList1(ListNode*head)
	{   //方法一，每次删除的是头节点后面一个元素
		ListNode* p = head->next;
		while (head)
		{
			head->next = p->next;
			delete p;
			p = head->next;
		}
	}
	//ListNode*
	ListNode* deleteNodeList2(ListNode*list_node)
	{  //方法二，每次都删除头节点
		/*
		这里要特别注意一点，虽然这里的参数是指针，但是仍然是复制过来的（只是两者指向的是同一块内存而已）
		因此，虽然最后指针list_node最后变为NULL了，但是函数外面的指针list_node仍然不是NULL,因此函数需要返回NULL指针
		*/
		while (list_node)
		{
			ListNode* p = list_node;
			list_node =list_node->next;
			delete p;
		}
		list_node = nullptr;
		return list_node;
	}

};

int main() {
	
	vector<int> ivec = {1,3,5};
	Solution solu;
	ListNode* list_node = solu.createNodeList(ivec);

	//list_node=solu.deleteNodeList2(list_node); //函数必须有返回值，才能将list_node置为NULL

	if (!list_node)
	{
		cout << "list_node deleted!!";
	}

	ListNode* head = solu.removeNthFromEnd(list_node, 2);

	while (head) 
	{
		cout << head->val << " ";
		head = head->next;//注意：这种方式cout会破坏原来的链表
	}

	system("pause");
	return 0;
}