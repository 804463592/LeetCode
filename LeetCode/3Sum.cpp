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
		sort(nums.begin(), nums.end());

		for (int k = nums.size() - 1; k >= 2;) {

			for (int i = 0, j = k - 1; i < j;) {

				int tmp_sum = nums[i] + nums[j];
				if (tmp_sum + nums[k] < 0)
				{//С��0����i����,�Ӷ���nums[i]����
					i++;
				}
				else if (tmp_sum + nums[k] > 0) {
					//����0����j����
					j--;
				}
				else { //����0,���ȱ���i,j,k��Ӧ��ֵ,ͬʱ�ƶ�ij,ȥ�����ظ���ֵ
					vector<int> tmp_vec;
					tmp_vec.push_back(nums[i]);
					tmp_vec.push_back(nums[j]);
					tmp_vec.push_back(nums[k]);
					res_nums.push_back(tmp_vec);
					//ȥ�ظ�
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
			//ȥ���ظ���k
			k--;
			while (k >= 2 && nums[k + 1] == nums[k])
			{
				k--;
			}
		}


		return res_nums;

	}
};



//int main() {
//
//	vector<int> ivec = { -1,0,1,2,-1,-4,-1,1 };
//
//	Solution solu;
//
//	vector<vector<int>> res = solu.threeSum(ivec);
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