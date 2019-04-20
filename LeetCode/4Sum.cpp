/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int> > res_nums;
		sort(nums.begin(), nums.end());
		for (int k = nums.size() - 1; k >= 3;)
		{
			for (int h = 0;k >= h + 3;)
			{

				for (int i = h + 1, j = k - 1; i < j;)
				{

					int tmp_sum = nums[i] + nums[j];
					if (tmp_sum + nums[h] + nums[k] < target)
					{//小于0则让i增加,从而让nums[i]增加
						i++;
					}
					else if (tmp_sum + nums[h] + nums[k] > target) {
						//大于0则让j减少
						j--;
					}
					else { //等于0,则先保存i,j,k对应的值,同时移动ij,去除掉重复的值
						vector<int> tmp_vec;
						tmp_vec.push_back(nums[h]);
						tmp_vec.push_back(nums[i]);
						tmp_vec.push_back(nums[j]);
						tmp_vec.push_back(nums[k]);
						res_nums.push_back(tmp_vec);
						//去重复
						i++;
						while (i < j &&nums[i - 1] == nums[i]) {
							i++;
						}
						j--;
						while (i < j &&nums[j + 1] == nums[j]) {

							j--;
						}
					}

				}
				//去掉重复的h
				h++;
				while (k >= h + 3 && nums[h - 1] == nums[h])
				{
					h++;
				}

			}

			//去掉重复的k
			k--;
			while (k >= 3 && nums[k + 1] == nums[k])
			{
				k--;
			}

		}
		return res_nums;

	}
};

//int main() {
//
//	vector<int> ivec = { -3,-1,0,2,4,5,4,7,-2,5,7,-3,0,0,-9,2,-1,2,4,5,6,-3,9,-13,25,-9,7,8,-8,13,-16,7,-19 };
//
//	Solution solu;
//
//	vector<vector<int>> res = solu.fourSum(ivec, 50);
//
//
//	for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++)
//	{
//		cout << "[";
//		for (vector<int>::iterator it = iter->begin(); it != iter->end(); it++) {
//			cout << *it << " ";
//
//		}
//		cout << "]";
//
//
//	}
//
//	system("pause");
//	return 0;
//}
