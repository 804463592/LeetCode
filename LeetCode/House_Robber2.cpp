/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ�Χ��һȦ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

ʾ�� 1:

����: [2,3,2]
���: 3
����: �㲻����͵�� 1 �ŷ��ݣ���� = 2����Ȼ��͵�� 3 �ŷ��ݣ���� = 2��, ��Ϊ���������ڵġ�
ʾ�� 2:

����: [1,2,3,1]
���: 4
����: �������͵�� 1 �ŷ��ݣ���� = 1����Ȼ��͵�� 3 �ŷ��ݣ���� = 3����
	 ͵�Ե�����߽�� = 1 + 3 = 4 ��
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
	int max(int a, int b) {

		return a > b ? a : b;
	}

	int rob1(vector<int>& nums)
	{
		int n_house = nums.size();
		if (nums.empty())
		{
			return 0;
		}
		else if (n_house == 1)
		{
			return nums[0];
		}
		else if (n_house == 2)
		{
			return max(nums[0], nums[1]);
		}
		else if (n_house == 3)
		{
			return max(max(nums[0], nums[1]), nums[2]);
		}
		else if (n_house == 4)
		{
			return max(nums[0] + nums[2], nums[1] + nums[3]);
		}

		int* p0 = new int[n_house];  //������0���ڵ�ļ�����
		int* p1 = new int[n_house];  //������0�ڵ㣬Ҳ���Ǽ�ȥ��0���ڵ�

		p0[0] = nums[0];
		p1[0] = 0;


		p0[1] = nums[0];
		p1[1] = nums[1];

		//һ��ע�⣬2,3�ڵ���Ϊ�м�Ľڵ㣬�ǿ�����ͷ�ڵ�ͬʱ��͵����,�ʼ����ʱ�ͷ��������
		//��Ϊ����p0[3]ʱ��3�ڵ㲻��͵��ʵ���Ͽ��ԣ���Ϊ��ֻ���м���
		p0[2] = nums[0] + nums[2];
		p1[2] = max(nums[1], nums[2]);

		p0[3] = nums[0] + max(nums[2], nums[3]);
		p1[3] = max(nums[2], nums[1] + nums[3]);

		for (int i = 3; i < n_house - 1; i++)  //iΪɶֻ�ܴ�2��ʼ����Ϊ֮ǰp0[2]�������
		{
			p0[i] = max(p0[i - 1], p0[i - 2] + nums[i]);
			p1[i] = max(p1[i - 1], p1[i - 2] + nums[i]);
		}

		p0[n_house - 1] = p0[n_house - 1 - 1];
		p1[n_house - 1] = max(p1[n_house - 2], p1[n_house - 1 - 2] + nums[n_house - 1]);  // ��һ֮�󣬻�Ҫ�ټ�2

		int result = max(p0[n_house - 1], p1[n_house - 1]);
		delete[]p0, p1;

		return result;
	}
	int rob2(vector<int>& nums)
	{
		int n_house = nums.size();
		if (nums.empty())
		{
			return 0;
		}
		else if (n_house == 1)
		{
			return nums[0];
		}
		//a��bΪ����������0������͵��0�����ӣ�1��֮
		int a0 = 0, a1 = 0;
		int b0 = 0, b1 = 0;
		int tmp0 = 0, tmp1 = 0;

		//��̬�滮�߽�㣬ֻ������ǰ���1������
		a0 = nums[0];
		a1 = 0;
		//��̬�滮�߽�㣬ֻ����ǰ��������
		b0 = nums[0];
		b1 = nums[1];

		for (int i = 2; i < n_house - 1; i++)
		{
			//��̬�滮�Ƶ�ʽ
			tmp0 = max(b0, a0 + nums[i]);
			tmp1 = max(b1, a1 + nums[i]);

			a0 = b0;
			a1 = b1;

			b0 = tmp0;
			b1 = tmp1;
		}
		// ���ķ��ӣ���Ҫ��������
		tmp0 = b0;   //͵��0�����ӵĻ�����͵���һ�����ӣ���ˣ������� nums[n_house - 1]);
		tmp1 = max(b1, a1 + nums[n_house - 1]);

		return max(tmp0, tmp1);

	}

};

//int main()
//{
//	Solution solu;
//	vector<int> house_money = { 4,1,2,7,5,3,1 };  //14
//	vector<int> house_money1 = { 2, 7, 9, 3, 1 };  //11
//	cout << solu.rob2(house_money1) << endl;
//
//	system("pause");
//	return 0;
//}