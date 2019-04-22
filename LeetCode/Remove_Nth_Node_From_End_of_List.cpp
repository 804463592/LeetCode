/*
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
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
		ʹ��˫ָ�뷽�������������ķ�ʽ�����ָ��)
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
		//pfast����n��
		int i = 0;
		while (i < n + 1)
		{
			if(pfast) pfast = pfast->next;
			else return head->next; //��Ϊn��֤�ǺϷ��ģ�˵����Ҫɾ������ͷ�ڵ㣬����˵ֻ��ɾ��ͷ�ڵ�
			i++;
		}

		//˫ָ��ͬʱ�ж���ֱ��pfast�����յ�
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
	{   //����һ��ÿ��ɾ������ͷ�ڵ����һ��Ԫ��
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
	{  //��������ÿ�ζ�ɾ��ͷ�ڵ�
		/*
		����Ҫ�ر�ע��һ�㣬��Ȼ����Ĳ�����ָ�룬������Ȼ�Ǹ��ƹ����ģ�ֻ������ָ�����ͬһ���ڴ���ѣ�
		��ˣ���Ȼ���ָ��list_node����ΪNULL�ˣ����Ǻ��������ָ��list_node��Ȼ����NULL,��˺�����Ҫ����NULLָ��
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

	//list_node=solu.deleteNodeList2(list_node); //���������з���ֵ�����ܽ�list_node��ΪNULL

	if (!list_node)
	{
		cout << "list_node deleted!!";
	}

	ListNode* head = solu.removeNthFromEnd(list_node, 2);

	while (head) 
	{
		cout << head->val << " ";
		head = head->next;//ע�⣺���ַ�ʽcout���ƻ�ԭ��������
	}

	system("pause");
	return 0;
}