

#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		//�жϽڵ�l1,l2��,ֵ�Ƿ����10
		if (l1->val > 9 || l2->val > 9 || l1->val < 0 || l2->val < 0) {

			return NULL;
		}
		//�������Ľڵ�
		ListNode* res = new ListNode(0);

		//p,q,resΪ��̬�ƶ��Ľڵ�
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* result = res;

		int carry_flag = 0;  //��λ��־

		while (p != NULL && q != NULL)
		{
			//������Ӧ���ж�p,q�ڵ��е�ֵ�Ƿ���0-9֮���
			//���Ǵ�û��Ҫ�����,�Ͳ�������

			if ((p->val + q->val + carry_flag) > 9)
			{

				carry_flag = 1;
				res->val += (p->val + q->val - 10);  //������+=,��Ϊǰ�湹��ʱ,�����˽�λ��,������ԭ���Ļ������ټ�

			}
			else
			{
				carry_flag = 0;
				res->val += p->val + q->val;
			}


			if (carry_flag) {

				ListNode* res_next = new ListNode(carry_flag);
				res->next = res_next;

			}
			else {
				if (p->next != NULL || q->next != NULL) //��ζ��p,q����next
				{
					res->next = new ListNode(0);
				}
				else
				{  //��ζ�Ž���,����res����nextΪNULL

					res->next = NULL;

				}

			}

			//��ӵ���λ�����ܳ��Ȳ����
			if (p->next == NULL && q->next != NULL)
			{
				p->next = new ListNode(0);

			}
			else if (p->next != NULL && q->next == NULL)
			{
				q->next = new ListNode(0);

			}

			//carry_flag = 0;  //��䲻��Ҫ��,����1+99����������

			res = res->next;
			q = q->next;
			p = p->next;

		}


		return result;
	}
};

int main()
{
	ListNode n1(1), n2(5), n3(7);
	n1.next = &n2;
	n2.next = &n3;

	Solution solu;
	ListNode* res = solu.addTwoNumbers(&n1, &n1);

	while (res != NULL) {

		cout << res->val << " ";

		res = res->next;   //ȫ�Ƿ������� ,����ʾ��λ,Ȼ���λ

	}


	getchar();
	return 0;
}

