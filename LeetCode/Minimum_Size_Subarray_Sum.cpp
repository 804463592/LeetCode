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
		int ans = 0;


		return 0;
	}
};

int main()
{
	Solution solu;
	vector<int> ivec = { 2,3,1,2,4,3 };


	solu.minSubArrayLen(7,ivec);

	system("pause");
	return 0;
}