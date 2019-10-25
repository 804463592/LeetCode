#include<iostream>
using namespace std;

class Solution {
private:
	int  n = 8;  //����ĳ���
	int* x;  //���ڼ�¼ÿһ��ľ��ߣ�����x[1] = 2 �����һ�еڶ���λ�÷�һ���ʺ�

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
			if (x[t] == x[i] || t - i == fabs(x[t] - x[i]))  //��������ͬ��б������һ������
			{
				flag =false;
			}
		}
		return flag;
	}

	void  backTrack(int  t)  //����Ϊ��t��
	{
		if (t > n)
		{	
			cout << "����һ�����н�Ϊ:" << endl;
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