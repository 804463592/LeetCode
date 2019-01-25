/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

	I can be placed before V (5) and X (10) to make 4 and 9.
	X can be placed before L (50) and C (100) to make 40 and 90.
	C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

*/

//输入一个罗马数字,输出其整数

#include<iostream>
#include<map>
using namespace std;


class Solution {
public:
	int romanToInt(string s) {

		map<char, int> Roman_input;

		Roman_input['I'] = 1;
		Roman_input['V'] = 5;
		Roman_input['X'] = 10;
		Roman_input['L'] = 50;
		Roman_input['C'] = 100;
		Roman_input['D'] = 500;
		Roman_input['M'] = 1000;

		int res_int = 0; //返回值

		for (int i = 0; i < s.length()-1; i++)
		{

			if (Roman_input[s[i]] < Roman_input[s[i + 1]]) {

				res_int -= Roman_input[s[i]];
			}
			else
			{
				res_int += Roman_input[s[i]];
			}

		}
		return res_int + Roman_input[s[s.size()-1]];  //必然是加上最后一个,而不可能是减去

	}
};


//int main() {
//
//	//前提是用户需要正确输入罗马数字
//	string Roman_str = "LVIII";
//	Solution solu;
//	cout << solu.romanToInt(Roman_str);
//
//	system("pause");
//	return 0;
//}