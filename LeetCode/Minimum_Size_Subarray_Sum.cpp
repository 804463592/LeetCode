/*
����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С�����������顣��������ڷ������������������飬���� 0��

ʾ��:

����: s = 7, nums = [2,3,1,2,4,3]
���: 2
����: ������ [4,3] �Ǹ������µĳ�����С�����������顣
����:

������Ѿ������O(n) ʱ�临�ӶȵĽⷨ, �볢�� O(n log n) ʱ�临�ӶȵĽⷨ��

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
			//������ֻ��Ҫһ������
			if (nums[i] >= s) return 1;
			//��������Ҫ�����������������
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