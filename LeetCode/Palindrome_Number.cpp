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
		//这个题常规思路是直接取各个位置上的数进行比较,比如下面的方法,这里转换成字符串,是另外一种方法
		/*
		// 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber/10;
		*/

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
