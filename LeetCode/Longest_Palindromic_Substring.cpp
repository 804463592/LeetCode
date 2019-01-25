
/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

#include<iostream>
#include<list>
using namespace std;

class Solution {
public:
	int max(int i, int j)
	{
		return i > j ? i : j;
	}
	int expandCenter(string s, int left, int right)
	{
		int L = left, R = right;
		int return_len = 0;
		while (L >= 0 && R < s.length() && s[L] == s[R]) {
			return_len = R - L + 1;
			L--;
			R++;
		}
		return return_len;
	}
	string longestPalindrome(string s) 
	{
		if (s.length() < 1) return "";
		int max_len=0;
		int start = 0, end = 0;
		//第一种情况,去检测 aca这样的回文
		for (int i = 0;i < s.length();i++)
		{
			int len1= expandCenter(s, i, i);
			if (len1 > max_len)
			{
				max_len = len1;
				start = i - (max_len - 1) / 2;
			}
		}
		//第二种情况,检测acca这样的回文
		for (int i = 0; i < s.length(); i++) 
		{
			int len2 = expandCenter(s, i, i + 1);
			if (len2 > max_len) 
			{
				max_len = len2;
				start = i - (max_len-2) / 2;
			}
		}
		return s.substr(start, max_len);
	}
};

//int main() {
//	string str = "accbbc";
//	Solution solu;
//	string hhh = solu.longestPalindrome(str);
//
//	for (int i = 0; i < hhh.size(); i++)
//	{
//		cout << hhh[i] << " ";
//	}
//	system("pause");
//	return 0;
//}