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
		int sum_rain = 0;  //雨水量

		//先找到直方图中的所有的转折点
		vector<int> idx;
		int idx_start = 0;
		int idx_end = 1;

		while ((idx_start + 1) < height.size() && height[idx_start] <= height[idx_start + 1])  //开始时,有可能是00012301这样的,需要移动idx_start
		{
			idx_start++;
		}
		idx.push_back(idx_start);

		while (idx_start < height.size() && idx_end < height.size()) {

			while ((idx_start + 1) < height.size() && (height[idx_start] <= height[idx_start + 1]))  //移动idx_start
			{
				idx_start++;
			}

			if (//一旦满足第一个条件,则不会计算height[idx_end + 1],也就不会越界;因此,这两个条件顺序不能换,否则会越界
				((idx_start + 1) < height.size() && height[idx_start] > height[idx_start + 1]
					&& height[idx_end - 1] < height[idx_end]) && (idx_end + 1) == height.size()
				||
				((idx_start + 1) < height.size() && height[idx_start] > height[idx_start + 1]
					&& height[idx_end - 1] < height[idx_end] && height[idx_end] >= height[idx_end + 1]))
			{

				while ((idx_end + 1) < height.size() && (height[idx_end] <= height[idx_end + 1]))  //继续移动idx_end,因为有可能出现10222223这样的
				{
					idx_end++;
				}

				if (idx_start != idx_end)
				{

					//idx.push_back(idx_start);
					idx.push_back(idx_end);   //保存所有的转折点,结尾处也算

				}

				idx_start = idx_end;
			}

			idx_end++;

		};

		cout << "找到的所有转折点的索引\n(通俗理解为:导函数为0的点以及边界点)为:" << endl;
		for (int i = 0; i < idx.size(); i++)
		{
			cout <<idx[i] << " ";
		}
		cout << endl;


		//根据idx中,找到的所有转折点,计算能接的雨水量
		if (idx.size() <= 1)
		{  //则说明原来的数组,是一个空的,或者全是相同元素的;

			sum_rain = 0;//显然雨水量应该为0;
		}
		else {

			//TODO:计算雨水量



		}
		return sum_rain;
	}
};


int main()
{
	vector<int> height = {0,0,5,7,9,5,6,9,7,3,1,5,5,5,4,6,9,5,1,1,6};
	Solution solu;
	int sum_rain = solu.trap(height);
	cout << "计算得到雨水量为" << sum_rain << endl;

	system("pause");
	return 0;
}

