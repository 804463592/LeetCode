
/*

Given a 32-bit signed integer, reverse digits of an integer.

*/
#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {

		int res = 0;  //为什么long也会溢出
        //x为32位有符号整数
		int n = 0; //位数
		if (0 == x) { return 0; }

		//全转为正数处理
		int pos_flag(0);
		if (x >= 0) pos_flag = true;
		else {
			pos_flag = false;
			x = -1 * x;
		}

		int temp = x;  //保存x

		while (temp > 0) {  //计算x的位数n
			temp = temp / 10;
			n++;
		}

		//用数组存储每一位的值,来校验是否溢出
		int* ori_p = new int[n];

		for (int i = 0; i < n; i++)
		{
			res += (x % 10)*pow(10, n - i - 1);
			ori_p[i] = x % 10;
			x = x / 10;

		}

		//判断是否溢出
		if (10 == n) {  //n=10才可能溢出

			int res_temp = res;
			for (int i = 0; i < n; i++)
			{
				if (int(res_temp % 10) != ori_p[n - i - 1])
				{
					cout << "结果溢出,请重新输入!!!" << endl;
					res = 0;
					break;
				}
				res_temp = res_temp / 10;

			}

		}

		delete ori_p;

		if (!pos_flag) {
			res = res * (-1);
		}
		return  res;

//另一种做法:
// int arr[12];
// int index = 0;
// int flag = true;
// if(x>=0) flag = true;
// else {
// flag = false;
// x = -1 * x;
// }
// while(x>0){
// arr[index] = x % 10;
// x = x / 10;
// index++;
// }
// int cal = 0;
// int temp;
// for(int i=0;i<index;i++){
// 	cout<<arr[i]<<"\t";
// 	temp = cal; // 保留上一次的cal 
// 	cal = cal * 10;
// 	//如果反转后的整数溢出，则返回 0。
// 	if(cal / 10 != temp){
// 		cout<<"yi chu"<<endl;
// 		return 0;
// 	}
// 	cal = arr[i] + cal;
// }
// if(!flag) return - 1*cal;
// return cal;

	}
};

int main() {

	Solution solution;
	int input;
	cout << "请输入需要反转的数字:" << endl;
	cin >> input;
	cout <<"结果为"<< solution.reverse(input) << endl;
	//int a = 99999999999;
	//cout << a;  //溢出了

	system("pause");

	return 0;
}