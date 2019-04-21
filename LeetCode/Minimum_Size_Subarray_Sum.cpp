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
		//����Ѱ�Һ��������
		int tmp_sum = 0;
		int i = 0, j = 0;
		for (; j < n_size; j++)
		{
			tmp_sum += nums[j];
			if (tmp_sum >= s)
			{
				ans = j - i + 1 < ans ? j - i + 1 : ans;
				tmp_sum -= nums[j];//�����ظ�����
				tmp_sum -= nums[i];
				i++;
				j--;
			}
		}
		//˵��û�к��ʵ�������
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
		//���ҳ���һ�������е�λ��0��k���п�����������֮�Ͷ���sС
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
		//û���ҵ����ʵ�������
		if (k == n_size - 1 && first_sum < s)
		{
			return 0;
		}
		//����Ѱ�Һ��������
		for (int i = 1; i < n_size; i++)
		{
			int tmp_sum = nums[i];
			//������ֻ��Ҫһ������
			if (nums[i] >= s) return 1;
			//��������Ҫ�����������������
			int j = i + 1;
			if (j >= n_size) break;

			while (tmp_sum + nums[j] < s)
			{
				tmp_sum += nums[j];
				if (j < n_size - 1)
				{
					j++;
				}
				else return ans; //�Ѿ����������յ㣬��û���ܹ��˳�while����ֱ����ǰ����ans
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