/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
Thanks Marcos for contributing this image!

*/
#include<vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	int trap(vector<int>& height)
	{
		int sum_rain = 0;  //��ˮ��

		//���ҵ�ֱ��ͼ�е����е�ת�۵�
		vector<int> idx;
		int idx_start = 0;
		int idx_end = 1;

		while ((idx_start + 1) < height.size() && height[idx_start] <= height[idx_start + 1])  //��ʼʱ,�п�����00012301������,��Ҫ�ƶ�idx_start
		{
			idx_start++;
		}
		idx.push_back(idx_start);

		while (idx_start < height.size() && idx_end < height.size()) {

			while ((idx_start + 1) < height.size() && (height[idx_start] <= height[idx_start + 1]))  //�ƶ�idx_start
			{
				idx_start++;
			}

			if (//һ�������һ������,�򲻻����height[idx_end + 1],Ҳ�Ͳ���Խ��;���,����������˳���ܻ�,�����Խ��
				((idx_start + 1) < height.size() && height[idx_start] > height[idx_start + 1]
					&& height[idx_end - 1] < height[idx_end]) && (idx_end + 1) == height.size()
				||
				((idx_start + 1) < height.size() && height[idx_start] > height[idx_start + 1]
					&& height[idx_end - 1] < height[idx_end] && height[idx_end] >= height[idx_end + 1]))
			{

				while ((idx_end + 1) < height.size() && (height[idx_end] <= height[idx_end + 1]))  //�����ƶ�idx_end,��Ϊ�п��ܳ���10222223������
				{
					idx_end++;
				}

				if (idx_start != idx_end)
				{

					//idx.push_back(idx_start);
					idx.push_back(idx_end);   //�������е�ת�۵�,��β��Ҳ��

				}

				idx_start = idx_end;
			}

			idx_end++;

		};

		cout << "�ҵ�������ת�۵������\n(ͨ�����Ϊ:������Ϊ0�ĵ��Լ��߽��)Ϊ:" << endl;
		for (int i = 0; i < idx.size(); i++)
		{
			cout <<idx[i] << " ";
		}
		cout << endl;


		//����idx��,�ҵ�������ת�۵�,�����ܽӵ���ˮ��
		if (idx.size() <= 1)
		{  //��˵��ԭ��������,��һ���յ�,����ȫ����ͬԪ�ص�;

			sum_rain = 0;//��Ȼ��ˮ��Ӧ��Ϊ0;
		}
		else {

			//TODO:������ˮ��



		}
		return sum_rain;
	}
};


int main()
{
	vector<int> height = {0,0,5,7,9,5,6,9,7,3,1,5,5,5,4,6,9,5,1,1,6};
	Solution solu;
	int sum_rain = solu.trap(height);
	cout << "����õ���ˮ��Ϊ" << sum_rain << endl;

	system("pause");
	return 0;
}

