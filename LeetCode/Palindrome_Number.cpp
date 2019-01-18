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
		//这个题常规思路是直接取各个位置上的数进行比较,这里转换成字符串,是另外一种方法

		bool res = false;

		if (x < 0) {

			res =false;
		}

		string x_str;
		stringstream ss;  //字符串流
		ss << x;
		ss >> x_str;   //或者 trans = ss.str();

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

int main() {

	Solution solu;
	int input = 0;
	cin >> input;

	bool res = solu.isPalindrome(input);

	cout << res << endl;
	system("pause");
	return 0;
}
