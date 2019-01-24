/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;



class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		
		vector<vector<int> > res_nums;

	


		return res_nums;

		//std::sort(nums.begin(), nums.end());
		//vector<vector<int>> v2;
		//for (int c = nums.size() - 1; c >= 2; ) {
		//	for (int a = 0, b = c - 1; a < b; ) {
		//		int tmp_sum = nums[a] + nums[b];
		//		if (tmp_sum < -nums[c]) {
		//			++a;
		//		}
		//		else if (tmp_sum > -nums[c]) {
		//			--b;
		//		}
		//		else {
		//			vector<int> v = { nums[a], nums[b], nums[c] };
		//			v2.push_back(v);
		//			do {//去重复 a b
		//				++a;
		//			} while (a < b && nums[a - 1] == nums[a]);
		//			do {
		//				--b;
		//			} while (a < b && nums[b + 1] == nums[b]);
		//		}
		//	}
		//	do {//去重复 c
		//		--c;
		//	} while (c >= 2 && nums[c + 1] == nums[c]);
		//}
		//return v2;


	}
};



int main() {

	vector<int> ivec = { -1,0,1,2,-1,-4};

	Solution solu;

	vector<vector<int>> res = solu.threeSum(ivec);


	for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++)
	{
		cout << "[";
		for (vector<int>::iterator it = iter->begin(); it != iter->end(); it++) {
			cout << *it << " ";

		}
		cout << "]";
		

	}

	system("pause");
	return 0;
}