
/*

Given a 32-bit signed integer, reverse digits of an integer.

*/
#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {

		int res = 0;  //ΪʲôlongҲ�����
        //xΪ32λ�з�������
		int n = 0; //λ��
		if (0 == x) { return 0; }

		//ȫתΪ��������
		int pos_flag(0);
		if (x >= 0) pos_flag = true;
		else {
			pos_flag = false;
			x = -1 * x;
		}

		int temp = x;  //����x

		while (temp > 0) {  //����x��λ��n
			temp = temp / 10;
			n++;
		}

		//������洢ÿһλ��ֵ,��У���Ƿ����
		int* ori_p = new int[n];

		for (int i = 0; i < n; i++)
		{
			res += (x % 10)*pow(10, n - i - 1);
			ori_p[i] = x % 10;
			x = x / 10;

		}

		//�ж��Ƿ����
		if (10 == n) {  //n=10�ſ������

			int res_temp = res;
			for (int i = 0; i < n; i++)
			{
				if (int(res_temp % 10) != ori_p[n - i - 1])
				{
					cout << "������,����������!!!" << endl;
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