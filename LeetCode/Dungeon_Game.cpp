/*

一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。



编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。

例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。

-2 (K)	-3	   3
-5	    -10	   1
10	    30	  -5 (P)


说明:

骑士的健康点数没有上限。

任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。

*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {

		int res = 0;
		int height = dungeon.size();
		int width = dungeon[0].size();
		//总的思路就是，如果后面不需要额外生命，那么你只需要保证能走到当前就可以了，
		//如果后面需要额外代价，那么你需要保证能走到当前并且+后面的额外生命代价
		//因此，可以看出，这里动态规划需要逆序进行，也就是，先计算dp[i+1][j+1],再计算dp[i][j]

		//由以上可以得出，动态规划式,dp[i][j]表示从ij坐标位置走到最右下角位置，需要的最小血量,即ij是起点
		int** dp = new int*[height];
		for (int i = 0; i < height; i++)
		{
			dp[i] = new int[width];
			memset(dp[i], 0, sizeof(int)*width);
		}
		//逆序求解dp
		for (int i = height - 1; i >= 0; i--)
		{
			for (int j = width - 1; j >= 0; j--)
			{
				if (i == height - 1 && j == width - 1)
				{
					dp[i][j] = max(1 - dungeon[i][j], 1);
				}
				else if (i == height - 1 && j != width - 1) //ij位置为最后一排
				{
					dp[i][j] = max(dp[i][j + 1] - dungeon[i][j], 1);  
				}
				else if (j == width - 1 && i != height - 1) //ij位置最后一列
				{
					dp[i][j] = max(dp[i + 1][j] - dungeon[i][j], 1);
				}
				else
				{
					//这么写可以看成是对前面两种情况的一个比较，选择代价小的
					dp[i][j] = min(max(dp[i + 1][j] - dungeon[i][j], 1), max(dp[i][j + 1] - dungeon[i][j], 1)); 
					//写成下面这样也是可以的，意义是一样的
					//dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j])-dungeon[i][j]) 
				}
			}
		}
		res = dp[0][0];
		//TODO:delete dp
		for (int i = 0; i < height; i++)
		{
			delete[]dp[i];
		}
		delete[]dp;


		return res;
	}


	int calculate(vector<vector<int>>& dungeon) {

		int res = 0;
		int dungeon_height = dungeon.size();
		int dungeon_width = dungeon[0].size();

		//动态规划式,dp[i][j]表示ij坐标位置，距离00点处的路径加权和的最小值
		int** dp = new int*[dungeon_height];
		for (int i = 0; i < dungeon_height; i++)
		{
			dp[i] = new int[dungeon_width];
		}
		for (int i = 0; i < dungeon_height; i++)
		{
			for (int j = 0; j < dungeon_width; j++)
			{
				if (i == 0 && j == 0) { dp[i][j] = dungeon[i][j]; }
				else if (i == 0 && j != 0) //第一排房间
				{
					dp[i][j] = dp[i][j - 1] + dungeon[i][j];
				}
				else if (j == 0 && i != 0) //第一列房间
				{
					dp[i][j] = dp[i - 1][j] + dungeon[i][j];
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + dungeon[i][j];
				}
			}
		}
		res = dp[dungeon_height - 1][dungeon_width - 1];
		//TODO:delete dp
		for (int i = 0; i < dungeon_height; i++)
		{
			delete[]dp[i];
		}
		delete[]dp;


		return res;
	}
};

int main()
{
	vector<vector<int>> dungeon;
	dungeon = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
	Solution solu;

	cout << solu.calculateMinimumHP(dungeon) << endl;

	system("pause");
	return 0;
}
