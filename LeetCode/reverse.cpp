
/*

Given a 32-bit signed integer, reverse digits of an integer.

*/
#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {


		int res = 0;
		//x为32位有符号整数
		int p;  //暂存每位上的数字,从个位开始
		int n = 0; //
		if (0 == x) { return 0; }
		int pos_flag(0);
		if (x >= 0) pos_flag = true;
		else {
			pos_flag = false;
			x = -1 * x;
		}

		int temp = x;  //保存x

		int div = 1;
		while (temp > 0) {  //计算x的位数
			temp = temp / 10;
			n++;
		}

		
		div = 10;
		int temp1;//用原x的最后一位,判断是否溢出
		temp1 = x % div;

		for (int i = 0; i < n; i++) {

			res += (x%div)*pow(10, n - i - 1);

			x = (x - x % div) / 10;

		}

		if (10 == n && int(res / pow(10, n - 1)) != temp1)  //n=10,十位数才可能溢出
		{
			res = 0;
			cout << "溢出了" << endl;
		}

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