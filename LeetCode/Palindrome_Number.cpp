/*

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/
#include<iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		//����ⳣ��˼·��ֱ��ȡ����λ���ϵ������бȽ�,��������ķ���,����ת�����ַ���,������һ�ַ���
		/*
		// ���������
        // ������������ x < 0 ʱ��x ���ǻ�������
        // ͬ���أ�������ֵ����һλ�� 0��Ϊ��ʹ������Ϊ���ģ�
        // �����һλ����ҲӦ���� 0
        // ֻ�� 0 ������һ����
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        // �����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ��������λ�����֡�
        // ���磬������Ϊ 12321 ʱ���� while ѭ����ĩβ���ǿ��Եõ� x = 12��revertedNumber = 123��
        // ���ڴ�����λ�����ֲ�Ӱ����ģ����������Լ���ȣ����������ǿ��Լ򵥵ؽ���ȥ����
        return x == revertedNumber || x == revertedNumber/10;
		*/

		bool res = false;

		if (x < 0) {

			res =false;
		}
		string x_str;
		stringstream ss;  //�ַ�����
		ss << x;
		ss >> x_str;   //���� trans = ss.str();

		string re_x_str;
		for (int i =x_str.size()-1;i>=0; i--)
		{
			re_x_str.push_back(x_str[i]);

		}

		if (re_x_str == x_str)
		{

			res =true;
		}
		else
		{
			res =false;
		}
	
		return res;
	}
};

#include <string>
#include <sstream>

//int main() {
//
//	Solution solu;
//	int input = 0;
//	cin >> input;
//
//	bool res = solu.isPalindrome(input);
//
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
