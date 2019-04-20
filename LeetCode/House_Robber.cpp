/*

����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

ʾ�� 1:

����: [1,2,3,1]
���: 4
����: ͵�� 1 �ŷ��� (��� = 1) ��Ȼ��͵�� 3 �ŷ��� (��� = 3)��
	 ͵�Ե�����߽�� = 1 + 3 = 4 ��
ʾ�� 2:

����: [2,7,9,3,1]
���: 12
����: ͵�� 1 �ŷ��� (��� = 2), ͵�� 3 �ŷ��� (��� = 9)������͵�� 5 �ŷ��� (��� = 1)��
	 ͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��

*/


#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
	int max(int a, int b) {

		return a > b ? a : b;
	}


	int rob(vector<int>& nums)
	{

		if (nums.size() == 0) {
			return 0;
		}
		else if (nums.size() == 1)
		{
			return nums[0];
		}
		else if (nums.size() == 2)
		{
			return max(nums[0],nums[1]);
		}
		//else if (nums.size() == 3)
		//{
		//	return max(nums[0]+nums[2],nums[1]);
		//}
		else {
			vector<int> num = nums;
			int tmp1 = num[num.size()-1];
			num.pop_back();
			int val_a = rob(num);

			int tmp2 = num[num.size() - 1];
			num.pop_back();
			int val_b = rob(num) + tmp1;

			int res = 0;
			if (val_b > val_a) {
				num.push_back(tmp2);
			}
			return max(val_a, val_b);
		}

	}

	int rob1(vector<int>&nums) {
		
		if (nums.empty()) {
			return 0;
		}
		int result = 0;
		int n_house = nums.size();
		if (n_house == 1)
		{
			result = nums[0];
			return result;
		}
		else if (n_house == 2)
		{
			result = max(nums[0], nums[1]);
			return result;
		}
		int* p = new int[n_house];
		p[0] = nums[0];
		p[1] = max(nums[0], nums[1]);
		//p[2] = max(nums[0] + nums[2], nums[1]);

		for (int i = 2; i < nums.size(); i++)
		{
			p[i] = max(p[i - 1], p[i - 2]+nums[i]);
		}
		result = p[nums.size() - 1];
		delete []p;
		return result;
	}
	int rob2(vector<int>&nums) 
	{
		if (nums.empty()) {
			return 0;
		}
	
		int n_house = nums.size();
		if (n_house == 1)
		{
			return nums[0];
		}
		else if (n_house == 2)
		{
			return max(nums[0], nums[1]);;
		}
		
		int a = nums[0];
		int b = max(nums[0], nums[1]);
		int tmp = 0;
		for (int i = 2; i < nums.size(); i++)
		{
			tmp = max(b, a + nums[i]);
			a = b;
			b = tmp;
		}

		return tmp;

	}

};

//int main()
//{
//	Solution solu;
//	vector<int> house_money = {1,2,3,19,3,1 };
//	cout << solu.rob1(house_money)<< endl;
//
//	system("pause");
//	return 0;
//}