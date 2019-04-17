/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
	 偷窃到的最高金额 = 1 + 3 = 4 。
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

	int rob1(vector<int>& nums)
	{
		int n_house = nums.size();
		if (nums.empty())
		{
			return 0;
		}
		else if (n_house == 1)
		{
			return nums[0];
		}
		else if (n_house == 2)
		{
			return max(nums[0], nums[1]);
		}
		else if (n_house == 3)
		{
			return max(max(nums[0], nums[1]), nums[2]);
		}
		else if (n_house == 4)
		{
			return max(nums[0] + nums[2], nums[1] + nums[3]);
		}

		int* p0 = new int[n_house];  //包含第0个节点的计算结果
		int* p1 = new int[n_house];  //不包含0节点，也就是减去第0个节点

		p0[0] = nums[0];
		p1[0] = 0;


		p0[1] = nums[0];
		p1[1] = nums[1];

		//一定注意，2,3节点作为中间的节点，是可以与头节点同时“偷”的,最开始计算时就犯了这个错
		//以为计算p0[3]时，3节点不能偷，实际上可以，因为这只是中间结果
		p0[2] = nums[0] + nums[2];
		p1[2] = max(nums[1], nums[2]);

		p0[3] = nums[0] + max(nums[2], nums[3]);
		p1[3] = max(nums[2], nums[1] + nums[3]);

		for (int i = 3; i < n_house - 1; i++)  //i为啥只能从2开始？因为之前p0[2]计算错了
		{
			p0[i] = max(p0[i - 1], p0[i - 2] + nums[i]);
			p1[i] = max(p1[i - 1], p1[i - 2] + nums[i]);
		}

		p0[n_house - 1] = p0[n_house - 1 - 1];
		p1[n_house - 1] = max(p1[n_house - 2], p1[n_house - 1 - 2] + nums[n_house - 1]);  // 减一之后，还要再减2

		int result = max(p0[n_house - 1], p1[n_house - 1]);
		delete[]p0, p1;

		return result;
	}
	int rob2(vector<int>& nums)
	{
		int n_house = nums.size();
		if (nums.empty())
		{
			return 0;
		}
		else if (n_house == 1)
		{
			return nums[0];
		}
		//a，b为两个变量，0：代表偷第0个房子，1则反之
		int a0 = 0, a1 = 0;
		int b0 = 0, b1 = 0;
		int tmp0 = 0, tmp1 = 0;

		//动态规划边界点，只考虑最前面的1个房子
		a0 = nums[0];
		a1 = 0;
		//动态规划边界点，只考虑前两个房子
		b0 = nums[0];
		b1 = nums[1];

		for (int i = 2; i < n_house - 1; i++)
		{
			//动态规划推导式
			tmp0 = max(b0, a0 + nums[i]);
			tmp1 = max(b1, a1 + nums[i]);

			a0 = b0;
			a1 = b1;

			b0 = tmp0;
			b1 = tmp1;
		}
		// 最后的房子，需要单独考虑
		tmp0 = b0;   //偷第0个房子的话，则不偷最后一个房子，因此，不加上 nums[n_house - 1]);
		tmp1 = max(b1, a1 + nums[n_house - 1]);

		return max(tmp0, tmp1);

	}

};

//int main()
//{
//	Solution solu;
//	vector<int> house_money = { 4,1,2,7,5,3,1 };  //14
//	vector<int> house_money1 = { 2, 7, 9, 3, 1 };  //11
//	cout << solu.rob2(house_money1) << endl;
//
//	system("pause");
//	return 0;
//}