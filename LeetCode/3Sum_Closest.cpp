/*

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest2(vector<int>& nums, int target) {

		sort(nums.begin(), nums.end());
        /*res初始化为前三个元素之和是最好的，初始化为0可能带来bug，0可能最靠近target，
		但0不一定为三个元素之和*/
		int res = nums[0] + nums[1] + nums[2]; 
		int tmp_sum = 0;

		for (int k = nums.size() - 1; k >= 2;) {

			for (int i = 0, j = k - 1; i < j;) {

				tmp_sum = nums[i] + nums[j] + nums[k];
				if (tmp_sum  < target)
				{//小于0则让i增加,从而让nums[i]增加
					i++;
					//下面的去重复代码，如果重复元素比较多的话，加上可以提高速度，本题的数据好像没多少重复的，加上了速度反而变慢
					/*while (i < j &&nums[i - 1] == nums[i]) {
						i++;
					}*/
				}
				else if (tmp_sum > target) {
					//大于0则让j减少
					j--;
				   /*while (i < j &&nums[j + 1] == nums[j])
				   {
						j--;
					}*/
				}
				else { //等于target,则直接返回target,同时移动ij,去除掉重复的值
					return target;
				}
				//判断是否需要更新res
				if (abs(target - tmp_sum) < abs(target - res))
				{
					res = tmp_sum;
				}
			}
			//k移动,移动时要去掉对应值重复的k，提高速度
			k--;
		    /*while (k >= 2 && nums[k + 1] == nums[k])
			{
				k--;
			}*/

		}

		return res;



	}

	//简洁版，三指针
	int threeSumClosest(vector<int>& nums, int target) {

		sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];
		int tmp_sum = 0;
		for (int k = nums.size() - 1; k >= 2;)
		{
			for (int i = 0, j = k - 1; i < j;)
			{
				tmp_sum = nums[i] + nums[j] + nums[k];
				if (tmp_sum < target) i++;
				else if (tmp_sum > target) j--;
				else return target;
				if (abs(target - tmp_sum) < abs(target - res)) res = tmp_sum;
			}
			k--;
		}
		return res;
	}
};

//int main() {
//
//	vector<int> ivec = {-1,2,1,-4};
//
//	Solution solu;
//
//	int res = solu.threeSumClosest(ivec,1);
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//}