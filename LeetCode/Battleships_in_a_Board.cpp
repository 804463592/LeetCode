/*

����һ����ά�ļװ壬 ����������ж�����ս���� ս���� 'X'��ʾ����λ�� '.'��ʾ�� ����Ҫ�������¹���

����һ����Ч�ļװ壬����ս�����߿�λ��ɡ�
ս��ֻ��ˮƽ���ߴ�ֱ���á����仰˵,ս��ֻ���� 1xN (1 ��, N ��)��ɣ����� Nx1 (N ��, 1 ��)��ɣ�����N�����������С��
����ս��֮��������һ��ˮƽ��ֱ�Ŀ�λ�ָ� - ��û�����ڵ�ս����
ʾ�� :

X..X
...X
...X
������ļװ�����2��ս����

��Ч���� :

...X
XXXX
...X
�㲻���յ���������Ч�װ� - ��Ϊս��֮�����ٻ���һ����λ�����Ƿֿ���

����:

�������һ��ɨ���㷨��ֻʹ��O(1)����ռ䣬���Ҳ��޸ļװ��ֵ��������������

*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		//˼�룺ͳ��ս��ͷ����Ϊÿһ��ս�������Ͻ���Ϊ�յ�Xֻ����һ����ͬ��Ҳ����ͳ��ս��β����������
		int count_ship = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j]=='X' &&((i == 0) || board[i - 1][j] == '.') && ((j == 0) || board[i][j - 1] == '.'))
				{
					++count_ship;
				}
			}
		}

		//TODO��~~~~

		return count_ship;
	}
};

//int main()
//{
//	vector<vector<char>> input = {
//	{'X','.','.','X'},
//	{'.','.','.','X'},
//	{'.','.','.','X'}
//	};
//
//	Solution solu;
//	cout << solu.countBattleships(input);
//
//	system("pause");
//	return 0;
//
//}