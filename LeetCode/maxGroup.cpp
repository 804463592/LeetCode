#include<iostream>
using namespace std;

class Solution{

private:
	int n =0;
	int** a;  //���ڱ����ڽӾ���Ķ�ά����
	int* x;   //���ڱ����ʿ�Ƿ�ѡ��
	int cn =0;  //��ǰ����

	int bestn=0; //��ǰ���ݵ��������
	int* bestx;  //��¼��ǰ����Ѿ���

public:
	Solution(int n =5)
	{
		this->n = n;
		this->a = new int*[n + 1];
		for (int i = 0; i < n + 1; i++)
		{
			this->a[i] = new int[n + 1];
			memset(a[i], 0, sizeof(int)*(n + 1));
		}

		this->x = new int[n + 1];
		memset(x, 0, sizeof(int)*(n + 1));
		this->bestx = new int[n + 1];
		memset(bestx, 0, sizeof(int)*(n + 1));
	}


	bool place(int t)  //�ж��Ƿ���Է�����
	{
		bool flag = true;
		for (int j =1; j < n; j++)
		{
			if (x[j] && a[t][j] == 0)
			{
				flag = false;
				break;
			}
		}
		return flag;
	}

	void backTrack(int t)
	{
		if (t > n)
		{
			for (int i = 1; i <= n; i++)
			{
				bestx[i] = x[i];
			}
			bestn = cn;
			return;
		}
		if (place(t))
		{
			x[t] = 1;
			cn++;
			backTrack(t + 1);
			cn--;
		}
		if (cn + n - t > bestn)
		{
			x[t] = 0;
			backTrack(t + 1);
		}
	}
	void kansTrack() 
	{
		//�����ڽӹ�ϵ��1����������Ҳ��������Ѻù�ϵ
		a[1][2] = 1;
		a[1][3] = 1;
		a[1][4] = 1;
		a[1][5] = 1;
		a[2][3] = 1;
		a[3][4] = 1;
		a[3][5] = 1;
		a[4][5] = 1;

		a[2][1] = 1;
		a[3][1] = 1;
		a[4][1] = 1;
		a[5][1] = 1;
		a[3][2] = 1;
		a[4][3] = 1;
		a[5][3] = 1;
		a[5][4] = 1;

		n = 5;
		cn = 0;
		backTrack(1);

		cout << "�����ӵ��������Ϊ��" << bestn << endl;
		cout << "�����ӵĳ�Ա���Ϊ��";
		for (int i = 1; i <= n; i++)
		{
			if (bestx[i])
				cout << i << " ";
		}
	}
};

//int main()
//{
//	Solution solu;
//
//	solu.kansTrack();
//
//	system("pause");
//	return 0;
//}