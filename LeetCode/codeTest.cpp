//#include<iostream>
//using namespace std;
//
//class Model
//{
//private:
//	int val;
//
//public:
//	Model(int n=0):val(n){}
//
//	Model(const Model &obj) { val = 2 * obj.val; }
//
//	Model &operator = (const Model &obj)
//	{
//		val = 4 * obj.val;
//		return *this;
//	}
//	void print()
//	{
//		cout << val << endl;
//	}
//};
//
//int main()
//{
//	Model obj1(10), obj2 = obj1, obj3;
//    
//	obj3 = obj1;
//	obj2.print();
//	obj3.print();
//	
//	system("pause");
//	return  0;
//}

#include <iostream>
#include<vector>
#include<string>
#include<memory.h>  //为了使用memset
#include<algorithm>
using namespace std;

class Solution
{
public:

	int minT(int a, int b)
	{
		return a < b ? a : b;
	}


	int minDistance(string word1, string word2)
	{

		//字符串长度
		int len1 = word1.size();
		int len2 = word2.size();

		//新建动态规划递推表达式
		int **d = new int*[len1 + 1];
		for (int i = 0; i <= len1; i++)
		{
			d[i] = new int[len2 + 1];
			//memset(d[i],0,sizeof(int)*(len2+1));
		}

		//初始化递推表达式边界

		for (int j = 0; j <= len2; j++)
		{
			d[0][j] = j;
		}

		for (int i = 0; i <= len1; i++)
		{
			d[i][0] = i;
		}


		//        for(int i=0;i<=len1;i++)
		//            for(int j =0;j<=len2;j++)
		//        {
		//            cout<<"the d："<<d[i][j]<<endl;
		//        }

				//求解递推表达式
		for (int i = 1; i <= len1; i++)
			for (int j = 1; j <= len2; j++)
			{
				int diff;
				if (word1[i - 1] == word2[j - 1])
				{
					diff = 0;
				}
				else
				{
					diff = 1;
				}
				int temp = minT(d[i - 1][j] + 1, d[i][j - 1] + 1);
				d[i][j] = minT(temp, d[i - 1][j - 1] + diff);
			}

		return d[len1][len2];
	}
};


//int main()
//{
//
//	string str1 = "family";
//	string str2 = "frame";
//	cout << str1 << "\t" << str2 << endl;
//
//	Solution solu;
//	std::cout << "the distance:" << solu.minDistance(str1, str2) << endl;
//
//	cout << "Hello world!" << endl;
//
//	system("pause");
//	return 0;
//}
