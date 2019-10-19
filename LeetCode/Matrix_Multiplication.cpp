#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cout;
using std::max;
class Solution
{
	//<<趣学算法>>p175 矩阵连乘问题
public:
	int matrixMultiplication(vector<int>  p)
	{/*p为第一个矩阵的行数，以及后面所有矩阵的列数*/
		int matrixLen = p.size();

		//新建动态递推数组m[][]，最优决策数组s[][]
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
				{ //边界初始化
					m[i][j] = 0;
				}
			}
		}
		//递推
		for (int r = 2; r < matrixLen; r++)
			for (int i = 0; i < matrixLen - r; i++)
			{
				int  j = i + r - 1;
				m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];  //k为i时
				s[i][j] = i;
				//寻找最小值；
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
		//打印括号位置
		printMatrixOrder(0, matrixLen - 2, s);

		//释放动态数组
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
	void printMatrixOrder(int i, int j, int *s[])  //二维数组作为参数，同样还可以写成：int **s，如果知道列数，还可以写成int s[][matrixLen],或者int (*s)[matrixLen]
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

	//<<趣学算法>>p183 切披萨问题
public:
	//输入g为凸多边形（披萨）的邻接矩阵，也就是各个顶点之间的权值
	int cutPizza(vector<vector<int>> g)
	{
		int  Num = g.size();  //凸多边形顶点数量

		//新建二维动态递推数组m，二维最优决策数组s
		int **m = new int*[Num];
		int **s = new int*[Num];
		for (int i = 0; i < Num; i++)
		{
			m[i] = new int[Num];
			memset(m[i], 0, sizeof(int)*Num);
			s[i] = new int[Num];
			memset(s[i], 0, sizeof(int) * Num);
		}

		//初始化递推数组边界
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

		//递推
		for (int r = 2; r < Num; r++)
		{
			for (int i = 0; i < Num - r; i++)
			{
				int j = i + r;  //Vi,Vj之间将会至少存在一个Vk

				//下面寻找Vi，Vj之间递推式的最小值，将其赋给m[i][j]

				//第一步，记录Vi，Vj之间的第一个值
				int min_tmp = m[i][i + 1] + m[i + 1][j] + g[i][i + 1] + g[i + 1][j] + g[i][j];
				s[i][j] = i + 1;
				//第二步，寻找最小值
				for (int k = i + 2; k < j; k++)
				{
					int tmp = m[i][k] + m[k][j] + g[i][k] + g[k][j] + g[i][j];
					if (min_tmp > tmp)
					{
						min_tmp = tmp;
						s[i][j] = k;//记录决策
					}
				}
				m[i][j] = min_tmp;
			}
		}

		//打印具体决策
		printCutPizzaOrder(0, Num - 1, s);

		//清除缓存
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
		//只输出弦，不用输出边
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

	//<<趣学算法>>p210  0-1背包问题
public:
	//输入为背包的容量w，各个商品的重量wi,价值vi,返回背包所能装货物的的最大价值
	int getMaxTrades(int W, vector<int> v, vector<int> w)
	{
		int width = W;  //各列为不同容量的背包
		int height = v.size(); //各行代表不同商品

		//递推数组m
		int **m = new int*[height + 1];
		for (int i = 0; i < height + 1; i++)
		{
			m[i] = new int[width + 1];
			//所有值均初始化为0
			memset(m[i], 0, sizeof(int)*(width + 1));
		}

		//初始化边界
		for (int j = 0; j < width + 1; j++)
		{
			int  i = 1;
			if (w[i] < j)
				m[i][j] = v[i];
			else
				m[i][j] = 0;
		}

		//开始递推
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

		//保存结果
		int res = m[height][width];
		//释放动态数组
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