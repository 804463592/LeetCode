/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例:

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:

	int minSubArrayLen(int s, vector<int>& nums) {

		int n_size = nums.size();
		int ans = n_size;
		//尝试寻找后面的序列
		int tmp_sum = 0;
		int i = 0, j = 0;
		for (; j < n_size; j++)
		{
			tmp_sum += nums[j];
			if (tmp_sum >= s)
			{
				ans = j - i + 1 < ans ? j - i + 1 : ans;
				tmp_sum -= nums[j];//减少重复计算
				tmp_sum -= nums[i];
				i++;
				j--;
			}
		}
		//说明没有合适的子序列
		if (i == 0 && tmp_sum < s)
			ans = 0;
		return ans;

	
	}
	int minSubArrayLen2(int s, vector<int>& nums)
	{
		if (nums.size() == 0) {
			return 0;
		}
		int  res = 0, sum = 0;
		for (int i = 0, j = 0; j < nums.size(); j++) {
			sum += nums[j];
			if (sum >= s) {
				res = res < j - i + 1 && res != 0 ? res : j - i + 1;
				sum -= nums[i];
				sum -= nums[j];
				i++;
				j--;
			}
		}
		return res;
	}

	int minSubArrayLen3(int s, vector<int>& nums)
	{

		int n_size = nums.size();
		int ans = 0;

		if (n_size == 0)return 0;
		if (n_size == 1)return nums[0] > s ? 1 : 0;
		//先找出第一个子序列的位置0，k，有可能整个序列之和都比s小
		int k = 0, first_sum = 0;
		for (; k < n_size; k++)
		{
			first_sum += nums[k];
			if (first_sum >= s)
			{
				ans = k + 1;
				break;
			}
		}
		//没有找到合适的子序列
		if (k == n_size - 1 && first_sum < s)
		{
			return 0;
		}
		//尝试寻找后面的序列
		for (int i = 1; i < n_size; i++)
		{
			int tmp_sum = nums[i];
			//子序列只需要一个长度
			if (nums[i] >= s) return 1;
			//子序列需要两个，甚至多个长度
			int j = i + 1;
			if (j >= n_size) break;

			while (tmp_sum + nums[j] < s)
			{
				tmp_sum += nums[j];
				if (j < n_size - 1)
				{
					j++;
				}
				else return ans; //已经到达数组终点，还没有能够退出while，则直接提前返回ans
			}

			ans = j - i + 1 < ans ? j - i + 1 : ans;

		}
		return ans;
	}

};

int main()
{
	Solution solu;
	vector<int> ivec = { 2,3,1,2,3,3,2 };

	cout << solu.minSubArrayLen(7, ivec) << endl;

	system("pause");
	return 0;
}