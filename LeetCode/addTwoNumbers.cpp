

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

		//判断节点l1,l2中,值是否大于10
		if (l1->val > 9 || l2->val > 9 || l1->val < 0 || l2->val < 0) {

			return NULL;
		}
		//保存结果的节点
		ListNode* res = new ListNode(0);

		//p,q,res为动态移动的节点
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* result = res;

		int carry_flag = 0;  //进位标志

		while (p != NULL && q != NULL)
		{
			//本来还应该判断p,q节点中的值是否在0-9之间的
			//但是答案没有要求这个,就不考虑了

			if ((p->val + q->val + carry_flag) > 9)
			{

				carry_flag = 1;
				res->val += (p->val + q->val - 10);  //必须是+=,因为前面构造时,考虑了进位的,必须在原来的基础上再加

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
				if (p->next != NULL || q->next != NULL) //意味着p,q还有next
				{
					res->next = new ListNode(0);
				}
				else
				{  //意味着结束,所以res后面next为NULL

					res->next = NULL;

				}

			}

			//相加的两位数可能长度不相等
			if (p->next == NULL && q->next != NULL)
			{
				p->next = new ListNode(0);

			}
			else if (p->next != NULL && q->next == NULL)
			{
				q->next = new ListNode(0);

			}

			//carry_flag = 0;  //这句不能要啊,否则1+99计算结果不对

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

		res = res->next;   //全是反着来的 ,先显示低位,然后高位

	}


	getchar();
	return 0;
}

