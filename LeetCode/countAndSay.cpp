
/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string readNextStr(string s) {
		int n = 1;
		int i = 0;
		string res_str = "";
		while (i < s.size())
		{
			if (s[i] == s[i + 1])
			{
				while (((i + 1) < s.size()) && s[i] == s[i + 1])
				{
					n++;
					i++;
				}
				res_str.append(to_string(n));
				n = 1;
				res_str.push_back((s[i]));
				i++;

			}
			else {

				res_str.append(to_string(n));
				n = 1;
				res_str.push_back((s[i]));
				i++;

			}

		}

		return res_str;

	}


	string countAndSay(int n) {
		string str = "1";
		for (int i = 0; i < n - 1; i++)
		{
			str = readNextStr(str);
		}

		return str;
	}
};

//int main() {
//
//	Solution solu;
//	//string res = solu.readNextStr(to_string(13112221));
//	int n = 0;
//	cout << "请输入一个正整数:" << endl;
//	cin >> n;
//	string res = solu.countAndSay(n);
//	cout << "报数的输出结果为:" << res << endl;
//
//	system("pause");
//	return 0;
//}

