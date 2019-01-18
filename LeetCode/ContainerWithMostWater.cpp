
/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {

		int max = 0;
		for (int i = 0, j = height.size() - 1; i < j; )
		{

			int minHeight = 0;
			if (height[i] < height[j])
			{
				minHeight = height[i];
				i++;
			}
			else
			{
				minHeight = height[j];
				j--;
			}
			//int minHeight = height[i] < height[j] ? height[i++] : height[j--];

			if (max < (j - i + 1) * minHeight)
			{
				max = (j - i + 1) * minHeight;
			}

		}

		return max;

	}
};

//int main()
//{
//	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//	Solution solu;
//	int max_water = solu.maxArea(height);
//	cout << "计算得到的最大容器水量为" << max_water << endl;
//
//	system("pause");
//	return 0;
//}
