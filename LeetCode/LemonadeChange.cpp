/*
At a lemonade stand, each lemonade costs $5. 

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.

Example 1:

Input: [5,5,5,10,20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		//与零钱相关的问题，是典型的贪心算法，在每一步都做出当前应该做的最优 的规划
		//最优规划即每次都尽可能使用较大的纸币付款
		int change5(0), change10(0);// , change20(0);
		for (int b : bills)
		{
			switch (b)
			{
			case 5:
				change5++;
				break;
			case 10:
				if (change5 > 0)
				{
					change5--;
					change10++;
				}
				else
				{
					return false;
				}
				break;
			case 20:
				if (change5 > 0 && change10 > 0)
				{//优先使用十元纸币
					change5--;
					change10--;
				}
				else if (change5 >= 3 && change10 <=0)
				{   
					change5 -= 3;
				}
				else
				{
					return false;
				}
			default:
				break;
			}
		}
		return  true;
	}
};

//int main()
//{
//	Solution solu;
//	vector<int> input_bills = { 5,5,10,10,5,20,5,10,5,5 };
//	cout << " "<<solu.lemonadeChange(input_bills);
//	system("pause");
//	return 0;
//}