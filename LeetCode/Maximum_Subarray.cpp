/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//这是一种找规律的做法,实际上也是属于动态规划
		int tmpSum = nums[0];
		int maxSum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (tmpSum > 0) tmpSum += nums[i]; //只要tmpSum还为正，对于后面的子序列就是有帮助的
			else tmpSum = nums[i];//如果之前的tmpSum为负，则意味着tmpSum需要从nums[i]重新开始
			maxSum = max(maxSum, tmpSum);
		}
		return maxSum;
	}
};

int main()
{
	vector<int> dungeon;
	dungeon = { -2,-1,-3 };
	Solution solu;

	cout << solu.maxSubArray(dungeon) << endl;

	system("pause");
	return 0;
}