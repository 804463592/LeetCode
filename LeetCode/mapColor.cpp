#include<iostream>
using namespace std;

class Solution
{
private:

	int  n = 7;    //�����
	int  m = 3; //��ͼ����ɫ����
	int** map;  //��ͼ���ڽӾ���
	int  sum = 0; //��¼��ĸ���
	int*  x;

public:
	Solution()
	{
		x = new int[n + 1];
		memset(x, 0, sizeof(x));

		map = new int*[n + 1];
		for (int i = 0; i <= n; i++)
		{
			map[i] = new int[n + 1];
			memset(this->map[i], 0, sizeof(int)*(n+1));
		}

		map[1][2] = map[2][1] = 1;
		map[1][3] = map[3][1] = 1;
		map[1][4] = map[4][1] = 1;
		map[2][3] = map[3][2] = 1;
		map[2][5] = map[5][2] = 1;
		map[3][4] = map[4][3] = 1;

		map[3][5] = map[5][3] = 1;
		map[4][5] = map[5][4] = 1;
		map[4][7] = map[7][4] = 1;
		map[5][6] = map[6][5] = 1;
		map[5][7] = map[7][5] = 1;
		map[6][7] = map[7][6] = 1;
	}

	bool  Boundary(int t)    //�жϵ�ǰ�ڵ㣬�Ƿ����Ѿ�ѡ��Ϳɫ�Ľڵ㣬�����Ƿ����Ϳɫ
	{
		for (int j = 1; j < t; j++)
		{
			if (map[j][t] == 1)
			{
				if (x[j] == x[t])
				{
					return false;
				}
			}
		}
		return  true;
	}

	void Backtrack(int t)
	{
		if (t > n)
		{
			sum++;
			cout << "��" << sum << "��Ϳɫ����Ϊ��" <<endl<< "[" ;
			for(int j = 1; j <=n; j++)
			{
				cout << x[j] << " ";
			}
			cout << "]" << endl;
		}
		if (t <= n)
		{
			for (int i = 1; i <= m; i++)
			{
				x[t] = i;
				if (Boundary(t))
					Backtrack(t + 1);
			}
		}
	}
};

//int main()
//{
//	Solution solu;
//
//	solu.Backtrack(1);
//
//	system("pause");
//	return 0;
//}
