/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1��3��1��1��1 minimizes the sum.

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	int min(int x, int y)
	{
		return x < y ? x : y;
	}

	int minPathSum(vector<vector<int>>& grid)
	{

		if (grid.empty()) return 0;
		int m = grid.size();
		int n = grid[0].size();
		int res = 0;

		int** p = new int*[m + 1];   //p[i][j]��ʾiXj��grid����СPathSum����grid�Ǵ�grid���ԡ��յ㡱Ϊ���¶����ȡ�����ģ���p[m][n]��Ϊ����
	    for (int i = 0; i < m + 1; i++)
	    {
	      p[i] = new int[n + 1];
	    }

		//
		///*�Ե�����,����һ*/
		//for (int i = 1; i <= m; i++)
		//	for (int j = 1; j <= n; j++) {
		//		if (i == 1 && j == 1)  p[1][1] = grid[m - 1][n - 1];              //p[1][1]��������
		//		else if (i == 1)   p[i][j] = grid[m - i][n - j] + p[i][j - 1];      //i=1��ֻ��������
		//		else if (j == 1)   p[i][j] = grid[m - i][n - j] + p[i - 1][j];      //j=1��ֻ��������
		//		else p[i][j] = grid[m - i][n - j] + min(p[i - 1][j], p[i][j - 1]);  //�����»�����
		//	}
		//return p[m][n];

		////ͬ�����Ե����ϣ������
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (m-1 == i && n-1== j) p[i][j] = grid[m - 1][n - 1];
				else if (m-1 == i) //˵���ߵ��������棬ֻ��������
				{
					p[i][j] = p[i][j+1] + grid[i][j];
				}
				else if (n-1 == j) //˵���ߵ������ұߣ�ֻ��������
				{
					p[i][j] = p[i +1][j] + grid[i][j];
				}
				else {//˵��û���ߵ��߽��ϣ��������һ���������
					p[i][j] = min(p[i][j + 1], p[i + 1][j]) + grid[i][j];
				}
				
			}
		}

		 res = p[0][0];

		for (int i = 0; i < m + 1; i++)
		{
			delete []p[i];
		}
		delete[]p;

		return res;
	}

	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return 0;
		if (m == 1 && n == 1) return 1;
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}

	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();    //��,��row�е�Ԫ����row��
		vector<vector<int> > f(triangle);
		//��f[m][n]��¼��triangle[m][n]������Ҷ�ӽڵ�����·���͡�Ҳ����ֱ����triangle����f������ı�triangle
		for (int x = row - 2; x >= 0; x--)
			for (int y = 0; y <= x; y++)
				f[x][y] = min(f[x + 1][y], f[x + 1][y + 1]) + triangle[x][y];
		return f[0][0];
	}

};


//int main()
//{
//	vector<vector<int>> vec =
//	{
//		{2, 3, 1},
//		{1, 5, 1},
//		{4, 2, 1}
//	};
//
//
//
//
//	vector<vector<int>> tvec =
//	{
//		{1, 2, 5},
//		{3, 2, 1},
//		//{4, 2, 1},
//		//{4, 2, 1}
//		
//	};
//
//	Solution solu;
//	//cout << solu.minimumTotal(tvec);
//
//	cout << solu.minPathSum(tvec);
//	system("pause");
//	return 0;
//}