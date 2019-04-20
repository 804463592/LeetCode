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

		if (n_size == 0)return 0;
		if (n_size == 1)return nums[0] > s ? 1 : 0;
		
		for (int i = 0; i < n_size; i++)
		{
			int tmp_sum = nums[i];
			//子序列只需要一个长度
			if (nums[i] >= s) return 1;
			//子序列需要两个，甚至多个长度
			int j = i + 1;
			if (j >= n_size)break;

			while (tmp_sum + nums[j] < s)
			{
				tmp_sum += nums[j];
				if(j<n_size)
				j++;
				else break;
			}
	
			ans = j - i + 1< ans ? j - i + 1:ans;


		}



		return ans;
	}
};

int main()
{
	Solution solu;
	vector<int> ivec = { 2,3,1,2,4,3,2 };


	cout << solu.minSubArrayLen(7, ivec) << endl;

	system("pause");
	return 0;
}