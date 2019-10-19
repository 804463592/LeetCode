#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cout;
using std::max;
class Solution
{
	//<<Ȥѧ�㷨>>p175 ������������
public:
	int matrixMultiplication(vector<int>  p)
	{/*pΪ��һ��������������Լ��������о��������*/
		int matrixLen = p.size();

		//�½���̬��������m[][]�����ž�������s[][]
		int **m = new int*[matrixLen];
		int **s = new int*[matrixLen];
		for (int i = 0; i < matrixLen; i++)
		{
			m[i] = new int[matrixLen];
			memset(m[i], 0, sizeof(int)*matrixLen);
			s[i] = new int[matrixLen];
			memset(s[i], 0, sizeof(int)*matrixLen);
		}
		//initialize
		for (int i = 0; i < matrixLen - 1; i++)
		{
			for (int j = i; j < matrixLen - 1; j++)
			{
				if (i == j)
				{ //�߽��ʼ��
					m[i][j] = 0;
				}
			}
		}
		//����
		for (int r = 2; r < matrixLen; r++)
			for (int i = 0; i < matrixLen - r; i++)
			{
				int  j = i + r - 1;
				m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];  //kΪiʱ
				s[i][j] = i;
				//Ѱ����Сֵ��
				for (int k = i; k < j; k++)
				{
					int tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
					if (tmp < m[i][j])
					{
						m[i][j] = tmp;
						s[i][j] = k;
					}
				}
			}
		//��ӡ����λ��
		printMatrixOrder(0, matrixLen - 2, s);

		//�ͷŶ�̬����
		int res = m[0][matrixLen - 2];

		for (int i = 0; i < matrixLen; i++)
		{
			delete[]m[i];
			delete[]s[i];
		}
		delete[]s;
		delete[]m;
		return res;
	}
private:
	void printMatrixOrder(int i, int j, int *s[])  //��ά������Ϊ������ͬ��������д�ɣ�int **s�����֪��������������д��int s[][matrixLen],����int (*s)[matrixLen]
	{
		if (i == j)
		{
			std::cout << "A[" << i << "]";
			return;
		}
		cout << "(";
		printMatrixOrder(i, s[i][j], s);
		printMatrixOrder(s[i][j] + 1, j, s);
		cout << ")";
	}

	//<<Ȥѧ�㷨>>p183 ����������
public:
	//����gΪ͹����Σ����������ڽӾ���Ҳ���Ǹ�������֮���Ȩֵ
	int cutPizza(vector<vector<int>> g)
	{
		int  Num = g.size();  //͹����ζ�������

		//�½���ά��̬��������m����ά���ž�������s
		int **m = new int*[Num];
		int **s = new int*[Num];
		for (int i = 0; i < Num; i++)
		{
			m[i] = new int[Num];
			memset(m[i], 0, sizeof(int)*Num);
			s[i] = new int[Num];
			memset(s[i], 0, sizeof(int) * Num);
		}

		//��ʼ����������߽�
		//for (int i = 0; i < Num; i++)
		//{
		//	m[i][i] = 0;
		//}
		//for (int i = 0; i < Num - 1; i++)
		//{
		//	m[i][i+1] = 0;
		//}
		for (int r = 0; r < 2; r++)
		{
			for (int i = 0; i < Num - r; i++)
			{
				int j = i + r;
				m[i][j] = 0;
			}
		}

		//����
		for (int r = 2; r < Num; r++)
		{
			for (int i = 0; i < Num - r; i++)
			{
				int j = i + r;  //Vi,Vj֮�佫�����ٴ���һ��Vk

				//����Ѱ��Vi��Vj֮�����ʽ����Сֵ�����丳��m[i][j]

				//��һ������¼Vi��Vj֮��ĵ�һ��ֵ
				int min_tmp = m[i][i + 1] + m[i + 1][j] + g[i][i + 1] + g[i + 1][j] + g[i][j];
				s[i][j] = i + 1;
				//�ڶ�����Ѱ����Сֵ
				for (int k = i + 2; k < j; k++)
				{
					int tmp = m[i][k] + m[k][j] + g[i][k] + g[k][j] + g[i][j];
					if (min_tmp > tmp)
					{
						min_tmp = tmp;
						s[i][j] = k;//��¼����
					}
				}
				m[i][j] = min_tmp;
			}
		}

		//��ӡ�������
		printCutPizzaOrder(0, Num - 1, s);

		//�������
		int result = m[0][Num - 1];

		for (int i = 0; i < Num; i++)
		{
			delete[] m[i];
			delete[] s[i];
		}
		delete[]m;
		delete[]s;

		return result;
	}

private:
	void printCutPizzaOrder(int i, int j, int**s)
	{
		if (i == j || i + 1 == j)  return;
		//ֻ����ң����������
		if (s[i][j] > 1 + i)
		{
			std::cout << "{v" << i << "v" << s[i][j] << "}" << std::endl;
		}
		if (s[i][j] + 1 < j)
		{
			std::cout << "{v" << s[i][j] << "v" << j << "}" << std::endl;
		}
		printCutPizzaOrder(i, s[i][j], s);
		printCutPizzaOrder(s[i][j], j, s);
	}

	//<<Ȥѧ�㷨>>p210  0-1��������
public:
	//����Ϊ����������w��������Ʒ������wi,��ֵvi,���ر�������װ����ĵ�����ֵ
	int getMaxTrades(int W, vector<int> v, vector<int> w)
	{
		int width = W;  //����Ϊ��ͬ�����ı���
		int height = v.size(); //���д���ͬ��Ʒ

		//��������m
		int **m = new int*[height + 1];
		for (int i = 0; i < height + 1; i++)
		{
			m[i] = new int[width + 1];
			//����ֵ����ʼ��Ϊ0
			memset(m[i], 0, sizeof(int)*(width + 1));
		}

		//��ʼ���߽�
		for (int j = 0; j < width + 1; j++)
		{
			int  i = 1;
			if (w[i] < j)
				m[i][j] = v[i];
			else
				m[i][j] = 0;
		}

		//��ʼ����
		for (int i = 2; i < height + 1; i++)
			for (int j = 1; j < width; j++)
			{
				if (w[i] > j) {
					m[i][j] = m[i - 1][j];
				}
				else {
						m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i]);
			}
		}

		//������
		int res = m[height][width];
		//�ͷŶ�̬����
		for (int i = 0; i < height + 1; i++)
			delete[]m[i];
		delete[]m;
		return  res;
	}
};

//int main()
//{
//	Solution solu;
//
//	vector<int> rowCols = { 2,4,3,3 };//3,5,10,8,2,4, };
//   //std::cout << solu.matrixMultiplication(rowCols) << std::endl;
//
//	vector<vector<int>> g = { {0,2,3,1,5,6},
//	{2,0,3,4,8,6},
//	{3,3,0,10,13,7},
//	{1,4,10,0,12,5},
//	{5,8,13,12,0,3},
//	{6,6,7,5,3,0} };
//	std::cout << solu.cutPizza(g) << std::endl;
//
//
//	system("pause");
//	return 0;
//}