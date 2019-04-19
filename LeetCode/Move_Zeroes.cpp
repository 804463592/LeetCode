
/*

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		vector<int>::size_type i = 0;
		int zeroes_num = 0;
		int n_size = nums.size();
		//先将非0元素移到前面
		for (vector<int>::size_type j = 0; j < nums.size(); j++)
		{
			if (nums[j] != 0)
			{
				nums[i] = nums[j];
				i++;
			}
			else
			{
				zeroes_num++;
			}
		}
		//将尾部元素置0
		for (int k = 0; k<zeroes_num ; k++) 
		{
			nums[n_size - 1 - k] = 0;
		}

	}
};

int main()
{
	Solution solu;
	vector<int> ivec = { 0,1,2,2,3,0,4,2 };

	
	solu.moveZeroes(ivec);

	for (int i = 0; i < ivec.size(); i++)
	{
		cout << ivec[i] << endl;
	}
	system("pause");
	return 0;
}