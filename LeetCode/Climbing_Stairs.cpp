
#include<iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) {
			return 0;
		}
		if (1 == n) {
			return 1;
		}
		else if (2 == n) {
			return 2;
		}
		int result = 0;
		//ʹ�õݹ飬���ǵݹ����Ĵ�leetcode�ϻ���ʾ��ʱ
		//result = allClimbWays(n); 
	
		//ʹ�ö�̬�滮
		//int *p = new int[n + 1];   
		//p[0] = 1;
		//p[1] = 1;
		//p[2] = 2;
		//for (int i = 3; i < n + 1; i++) {

		//	p[i] = p[i - 1] + p[i - 2];
		//}
		//result = p[n];
		//delete[]p;
		//return result;

	    //����Ķ�̬�滮��ʵ���϶ౣ���˺ܶ��м������ռ临�Ӷȸߣ�����ֻ��Ҫ���������˸�д
		int a = 1;
		int b = 2;
		int temp = 0;
		for (int i = 3; i <= n; i++)
		{
			temp = a + b;
			a = b;
			b = temp;
		}
		return temp;
	}

	int allClimbWays(int n) {

		if (n <= 0) {
			return 0;
		}
		if (1 == n) {
			return 1;
		}
		else if (2 == n) {
			return 2;
		}
		else {
			return allClimbWays(n-2) +allClimbWays(n-1);
		}
	}

};

int main()
{
	Solution solu;
	cout << solu.climbStairs(40) << endl;

	system("pause");
	return 0;
}