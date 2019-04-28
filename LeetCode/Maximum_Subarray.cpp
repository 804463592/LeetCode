/*
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//����һ���ҹ��ɵ�����,ʵ����Ҳ�����ڶ�̬�滮
		int tmpSum = nums[0];
		int maxSum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (tmpSum > 0) tmpSum += nums[i]; //ֻҪtmpSum��Ϊ�������ں���������о����а�����
			else tmpSum = nums[i];//���֮ǰ��tmpSumΪ��������ζ��tmpSum��Ҫ��nums[i]���¿�ʼ
			maxSum = max(maxSum, tmpSum);
		}
		return maxSum;
	}
};

int main()
{
	vector<int> dungeon;
	dungeon = { -2,-1,-3 };
	Solution solu;

	cout << solu.maxSubArray(dungeon) << endl;

	system("pause");
	return 0;
}