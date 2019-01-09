/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
Thanks Marcos for contributing this image!

*/
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int trap(vector<int>& height)
	{
		int sum_rain = 0;  //雨水量
		int max_height = 0;
		int n_height = height.size();

		for (int i = 0; i < n_height; i++)
		{
			if (height[i] > max_height) {
				max_height = height[i];
			}
		}

		int sum_area = max_height * n_height;
		int light_area = 0;
		int stone_area = 0;

		//左边阳光照射
		for (int i = 0; i < max_height; i++)
		{
			int n = 0;

			while (n<n_height && (max_height - i) > height[n])
			{
				light_area++;
				n++;
			}
		}

		//右边阳光照射
		for (int i = 0; i < max_height; i++) {

			int n = n_height - 1;
			while (n >= 0 && (max_height - i) > height[n])
			{
				light_area++;
				n--;
			}

		}
		//计算原始的数组面积,相当于求围"水坝的石头面积"
		for (int i = 0; i < n_height; i++)
		{
			stone_area += height[i];
		}

		sum_rain = sum_area - light_area - stone_area;

		return sum_rain;
	}
};


//int main()
//{
//	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//	Solution solu;
//	int sum_rain = solu.trap(height);
//	cout << "计算得到雨水量为" << sum_rain << endl;
//
//	system("pause");
//	return 0;
//}

