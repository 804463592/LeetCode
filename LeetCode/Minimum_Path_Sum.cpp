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
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

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

		int** p = new int*[m + 1];   //p[i][j]表示iXj的grid的最小PathSum（该grid是从grid中以“终点”为右下顶点截取下来的），p[m][n]即为所求
	    for (int i = 0; i < m + 1; i++)
	    {
	      p[i] = new int[n + 1];
	    }

		//
		///*自底向上,代码一*/
		//for (int i = 1; i <= m; i++)
		//	for (int j = 1; j <= n; j++) {
		//		if (i == 1 && j == 1)  p[1][1] = grid[m - 1][n - 1];              //p[1][1]单独处理
		//		else if (i == 1)   p[i][j] = grid[m - i][n - j] + p[i][j - 1];      //i=1，只能向右走
		//		else if (j == 1)   p[i][j] = grid[m - i][n - j] + p[i - 1][j];      //j=1，只能向下走
		//		else p[i][j] = grid[m - i][n - j] + min(p[i - 1][j], p[i][j - 1]);  //能向下或向右
		//	}
		//return p[m][n];

		////同样的自底向上，代码二
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (m-1 == i && n-1== j) p[i][j] = grid[m - 1][n - 1];
				else if (m-1 == i) //说明走到了最下面，只能向右走
				{
					p[i][j] = p[i][j+1] + grid[i][j];
				}
				else if (n-1 == j) //说明走到了最右边，只能向下走
				{
					p[i][j] = p[i +1][j] + grid[i][j];
				}
				else {//说明没有走到边界上，可以向右或者向左走
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
		int row = triangle.size();    //行,第row行的元素有row个
		vector<vector<int> > f(triangle);
		//用f[m][n]记录从triangle[m][n]出发到叶子节点的最短路径和。也可以直接用triangle代替f，但会改变triangle
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