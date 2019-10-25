#include<iostream>
using namespace std;

class Solution {
private:
	int  n = 8;  //矩阵的长宽
	int* x;  //用于记录每一层的决策；比如x[1] = 2 代表第一行第二个位置放一个皇后

public:
	Solution()
	{
		x = new int[n + 1];
	}
	~Solution() {
		delete[]x;
	}

	bool Place(int t)
	{
		bool flag = true;
		for (int i = 1; i < t; i++)
		{
			if (x[t] == x[i] || t - i == fabs(x[t] - x[i]))  //横坐标相同，斜方向在一条线上
			{
				flag =false;
			}
		}
		return flag;
	}

	void  backTrack(int  t)  //输入为第t行
	{
		if (t > n)
		{	
			cout << "其中一个可行解为:" << endl;
			for (int i = 1; i <= n; i++)
			{
				cout << x[i] <<" ";
			}
			cout << endl << "---------------" << endl;
		}
		else
		{
			for (int j = 1; j <= n; j++)
			{
				x[t] = j;
				if (Place(t))
					backTrack(t + 1);
			}
		}
	}
};
//
//int main()
//{
//	Solution solu;
//	solu.backTrack(1);
//	system("pause");
//	return 0;
//}