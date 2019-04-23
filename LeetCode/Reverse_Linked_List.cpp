
/*
��תһ��������

ʾ��:

����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
����:
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

*/

/*
��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��

˵��:
1 �� m �� n �� �����ȡ�

ʾ��:

����: 1->2->3->4->5->NULL, m = 2, n = 4
���: 1->4->3->2->5->NULL
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
		//��������,�������ȵݹ鷨�����
		ListNode *pPre = NULL;
		ListNode *pNode = head;
		ListNode *pNext = NULL;

		while (pNode)
		{
			//������һ���ڵ�
			pNext = pNode->next;
			//��תpNode�ڵ�
			pNode->next = pPre;
			//pPre,pNode����ƶ�
			pPre = pNode;
			pNode = pNext;

		}
		//pPre��󱣴���Ƿ�ת��������ͷ�ڵ�
		return pPre;
	}
	ListNode* reverseListRecursion(ListNode*head)
	{
		//�ݹ�İ汾
		if (head == NULL || head->next == NULL) return head;
		ListNode* p = reverseListRecursion(head->next);
		head->next->next = head;
		head->next = NULL;
		return p;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//��ת��λ�� m �� n ������,������
		if (m == n) return head;

		ListNode* reverseHead = NULL;
		ListNode* pM = NULL; //pM,pNΪ�߽�֮��ĵ�һ���㣬
		ListNode* pMnext = NULL; //pM���ŵĵ�
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
				if (i < m) //ֻ�ƶ���������
				{
					pNext = pNode->next;

					//�ƶ�
					pPre = pNode;
					pNode = pNext;
				}
				else if (i == m) //pM��ֵ������ʼ��ת
				{
					pM = pPre;
					pMnext = pNode; //����ýڵ㣬������N�ڵ㴦Ϊ��next��ֵ
					pNext = pNode->next;
					//ָ���ָ��
					pNode->next = pN;  //����ʵ����ûʲô�ã���ΪPN��ʱ��һ����ָ�룬�൱��pNode->next = NULL;�����Ҫ����pMnext,����pMnext��ָ��pN

					//�ƶ�
					pPre = pNode;
					pNode = pNext;

				}
				else if (i > m && i < n)
				{
					pNext = pNode->next;
					//��ת
					pNode->next = pPre;
					//�ƶ�
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
					//��ת
					pNode->next = pPre;
					//�ƶ�
					pPre = pNode;
					pNode = pNext;
				}
				else if (i == n)
				{
					pNext = pNode->next;
					//ͷ�ڵ�ӵ�pNext
					head->next = pNext;
					//��ת
					pNode->next = pPre;

					//���ܵ��µ�ͷ�ڵ�
					reverseHead = pNode;
					//���Բ������ƶ���
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
	{  //��������ÿ�ζ�ɾ��ͷ�ڵ�
		/*
		����Ҫ�ر�ע��һ�㣬��Ȼ����Ĳ�����ָ�룬������Ȼ�Ǹ��ƹ����ģ�ֻ������ָ�����ͬһ���ڴ���ѣ�
		��ˣ���Ȼ���ָ��list_node����ΪNULL�ˣ����Ǻ��������ָ��list_node��Ȼ����NULL,��˺�����Ҫ����NULLָ��
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