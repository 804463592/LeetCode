/*

һЩ��ħץס�˹�����P�������������˵��³ǵ����½ǡ����³����� M x N ��������ɵĶ�ά��������Ӣ�µ���ʿ��K����������������Ͻǵķ���������봩�����³ǲ�ͨ���Կ���ħ�����ȹ�����

��ʿ�ĳ�ʼ��������Ϊһ����������������Ľ���������ĳһʱ�̽��� 0 �����£���������������

��Щ�����ɶ�ħ�����������ʿ�ڽ�����Щ����ʱ��ʧȥ�������������������ֵΪ�����������ʾ��ʿ����ʧ��������������������Ҫô�ǿյģ��������ֵΪ 0����Ҫô����������ʿ����������ħ�������������ֵΪ�����������ʾ��ʿ�����ӽ�����������

Ϊ�˾��쵽�﹫������ʿ����ÿ��ֻ���һ������ƶ�һ����



��дһ������������ȷ����ʿ�ܹ����ȵ������������ͳ�ʼ����������

���磬���ǵ����²��ֵĵ��³ǣ������ʿ��ѭ���·�� �� -> �� -> �� -> �£�����ʿ�ĳ�ʼ������������Ϊ 7��

-2 (K)	-3	   3
-5	    -10	   1
10	    30	  -5 (P)


˵��:

��ʿ�Ľ�������û�����ޡ�

�κη��䶼���ܶ���ʿ�Ľ������������в��Ҳ����������ʿ�Ľ���������������ʿ��������ϽǷ����Լ���������������½Ƿ��䡣

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
		//�ܵ�˼·���ǣ�������治��Ҫ������������ô��ֻ��Ҫ��֤���ߵ���ǰ�Ϳ����ˣ�
		//���������Ҫ������ۣ���ô����Ҫ��֤���ߵ���ǰ����+����Ķ�����������
		//��ˣ����Կ��������ﶯ̬�滮��Ҫ������У�Ҳ���ǣ��ȼ���dp[i+1][j+1],�ټ���dp[i][j]

		//�����Ͽ��Եó�����̬�滮ʽ,dp[i][j]��ʾ��ij����λ���ߵ������½�λ�ã���Ҫ����СѪ��,��ij�����
		int** dp = new int*[height];
		for (int i = 0; i < height; i++)
		{
			dp[i] = new int[width];
			memset(dp[i], 0, sizeof(int)*width);
		}
		//�������dp
		for (int i = height - 1; i >= 0; i--)
		{
			for (int j = width - 1; j >= 0; j--)
			{
				if (i == height - 1 && j == width - 1)
				{
					dp[i][j] = max(1 - dungeon[i][j], 1);
				}
				else if (i == height - 1 && j != width - 1) //ijλ��Ϊ���һ��
				{
					dp[i][j] = max(dp[i][j + 1] - dungeon[i][j], 1);  
				}
				else if (j == width - 1 && i != height - 1) //ijλ�����һ��
				{
					dp[i][j] = max(dp[i + 1][j] - dungeon[i][j], 1);
				}
				else
				{
					//��ôд���Կ����Ƕ�ǰ�����������һ���Ƚϣ�ѡ�����С��
					dp[i][j] = min(max(dp[i + 1][j] - dungeon[i][j], 1), max(dp[i][j + 1] - dungeon[i][j], 1)); 
					//д����������Ҳ�ǿ��Եģ�������һ����
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

		//��̬�滮ʽ,dp[i][j]��ʾij����λ�ã�����00�㴦��·����Ȩ�͵���Сֵ
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
				else if (i == 0 && j != 0) //��һ�ŷ���
				{
					dp[i][j] = dp[i][j - 1] + dungeon[i][j];
				}
				else if (j == 0 && i != 0) //��һ�з���
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
