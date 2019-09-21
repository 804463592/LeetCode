#include<iostream>
#include<vector>

using std::vector;
using std::cout;
class Solution
{
	//<<趣学算法>>p175
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
		for(int r =2;r<matrixLen ;r++)
		for (int i = 0; i < matrixLen-r; i++)
		{
			    int  j = i + r - 1;
				m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];  //k为i时
				s[i][j] = i;
				for (int k = i; k < j; k++)
				{
					int tmp = m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
					if (tmp < m[i][j])
					{
						m[i][j] = tmp;
						s[i][j] = k;
					}
				}
		}
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
	void printMatrixOrder(int i, int j, int** s)
	{
		if (i == j)
		{
			std::cout << "A[" << i << "]";
			return;
		}
		cout << "(";
		printMatrixOrder(i, s[i][j], s);
		printMatrixOrder(s[i][j]+1,j, s);
		cout << ")";
	}
};

int main()
{
	vector<int> rowCols = { 2,4,3,3};//3,5,10,8,2,4, };
	Solution solu;
	std::cout << solu.matrixMultiplication(rowCols)<<std::endl;
	system("pause");
	return 0;
}