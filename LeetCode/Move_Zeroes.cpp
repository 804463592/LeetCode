
/*

����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:

����: [0,1,0,3,12]
���: [1,3,12,0,0]
˵��:

������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������

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
		//�Ƚ���0Ԫ���Ƶ�ǰ��
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
		//��β��Ԫ����0
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