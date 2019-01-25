/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
Thanks Marcos for contributing this image!

*/

//下面的实现复杂了,换了个思路

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
			cout << idx[i] << " ";
		}
		cout << endl;


		////根据idx中,找到的所有转折点,计算能接的雨水量
		//if (idx.size() <= 1)
		//{  //则说明原来的数组,是一个空的,或者全是相同元素的;

		//	sum_rain = 0;//显然雨水量应该为0;
		//}
		//else {

		//	//TODO:计算雨水量
		//	int i = 0;
		//	while (i < idx.size())
		//	{

		//		int n_start = 0;  //每次计算sum_rain的起始点和终止点
		//		int n_end = 0;


		//		if ((i + 1) < idx.size() && height[idx[i]] <= height[idx[i + 1]])  //满足该条件,则可以直接计算雨水量
		//		{

		//			n_start = idx[i];
		//			n_end = idx[i + 1];
		//			/////////////计算sum_rain//////////////////


		//			/////////////////////////////////////////
		//			i++;
		//		}
		//		else if ((i + 1) < idx.size() && height[idx[i]] > height[idx[i + 1]])
		//		{

		//			n_start = idx[i];

		//			//需要去找最接近n_start对应的height的索引
		//			int max = height[idx[i] + 1];  //不会溢出
		//			while (i < idx.size())
		//			{

		//				if (height[idx[i]] > height[n_start])
		//				{
		//					n_end = idx[i];
		//					break;

		//				}

		//				if (height[idx[i]] > max)
		//				{
		//					max = height[idx[i]];
		//					n_end = idx[i];
		//				}

		//				i++;
		//			}
		//			 

		//			//继续往后移动
		//			i++;
		//		}

		//		//通过n_start和n_end,计算sum_rain


		//		cout << "n_start= " << n_start << endl;
		//		cout << "n_end= " << n_end << endl;


		//		//更新i,n_start,n_end;

		//		//i++;
		//	}
		//}




		return sum_rain;
	}
};


//int main()
//{
//	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1,0,1 };
//	Solution solu;
//	int sum_rain = solu.trap(height);
//	cout << "计算得到雨水量为" << sum_rain << endl;
//
//	system("pause");
//	return 0;
//}

