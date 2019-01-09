#include<iostream>]
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

int main()
{
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	Solution solu;
	int max_water = solu.maxArea(height);
	cout << "����õ����������ˮ��Ϊ" << max_water << endl;

	system("pause");
	return 0;
}
