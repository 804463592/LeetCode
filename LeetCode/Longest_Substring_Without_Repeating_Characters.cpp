
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/

#include<string>
#include<iostream>
#include<set>
using namespace std;

class Solution {

int max(int a, int b)
	{
		return a > b ? a : b;
	}

//bool isUnique(string s, int start, int end)
//	{
//		bool isunique = true;
//
//		if (start == end || start > end || start < 0 || end < 0) {
//
//			return false;
//		}
//
//		for (int i = start; i < end; i++) {
//
//			for (int j = i + 1; j <= end; j++)
//			{
//				if (s[j] == s[i]) {
//
//					isunique = false;
//
//					return isunique;
//				}
//
//
//			}
//		}
//		return isunique;
//	}

public:
	int lengthOfLongestSubstring(string s)
	{

		//int n = s.length();
		//if (n <= 1) {
		//	return 1;
		//}
		//int ans = 1;
		////暴力法,速度不快
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = i + 1; j <n; j++)
		//	{
		//		if (isUnique(s, i, j))
		//		{
		//			//ans = max(ans, j - i);
		//			ans = ans > (j - i + 1) ? ans : (j - i + 1);
		//		}
		//	}
		//}

		//滑动窗口法,速度明显更快
		int n = s.length();
		string move_str;
		set<char> move_set;

		int ans = 0, i = 0, j = 0;
		while (i < n && j < n) {
			// try to extend the range [i, j]
			if (!move_set.count(s[j])) {
				move_set.insert(s[j++]);
				ans = max(ans, j - i);
			}
			else {
				move_set.erase(s[i++]);
			}
		}
		return ans;
	}



};


int main() {

	string ss = "abcdfffff";
	cout << "请输入字符串:" << endl;
	cin >> ss;
	Solution solu;
	cout << "该字符串最长的不重复子串为" << solu.lengthOfLongestSubstring(ss)<<endl;




	system("pause");
	return 0;
}