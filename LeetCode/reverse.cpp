
/*

Given a 32-bit signed integer, reverse digits of an integer.

*/
#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {


		int res = 0;
		//xΪ32λ�з�������
		int p;  //�ݴ�ÿλ�ϵ�����,�Ӹ�λ��ʼ
		int n = 0; //
		if (0 == x) { return 0; }
		int pos_flag(0);
		if (x >= 0) pos_flag = true;
		else {
			pos_flag = false;
			x = -1 * x;
		}

		int temp = x;  //����x

		int div = 1;
		while (temp > 0) {  //����x��λ��
			temp = temp / 10;
			n++;
		}

		
		div = 10;
		int temp1;//��ԭx�����һλ,�ж��Ƿ����
		temp1 = x % div;

		for (int i = 0; i < n; i++) {

			res += (x%div)*pow(10, n - i - 1);

			x = (x - x % div) / 10;

		}

		if (10 == n && int(res / pow(10, n - 1)) != temp1)  //n=10,ʮλ���ſ������
		{
			res = 0;
			cout << "�����" << endl;
		}

		if (!pos_flag) {
			res = res * (-1);
		}
		return  res;

//��һ������:
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
// 	temp = cal; // ������һ�ε�cal 
// 	cal = cal * 10;
// 	//�����ת�������������򷵻� 0��
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
	cout << "��������Ҫ��ת������:" << endl;
	cin >> input;
	cout <<"���Ϊ"<< solution.reverse(input) << endl;
	//int a = 99999999999;
	//cout << a;  //�����

	system("pause");

	return 0;
}