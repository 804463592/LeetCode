/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {

		//KMP算法
		if (needle.empty())
			return 0;
		vector<int> next = getnext(needle);
		int i = 0;
		int j = 0;
		
		while ((j < 0) || (i < haystack.length()) && (j < needle.length())) {
			if (j == -1 || haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else
				j = next[j];

		}
		if (j == needle.length())
			return i - j;
		return -1;
	}
	//KMP算法中的next
	vector<int> getnext(string t) {
		int k = -1;
		int j = 0;
		vector<int> next;
		for (int i = 0; i < t.length(); i++)
			next.push_back(-1);
		while (j < t.length() - 1)
			if (k == -1 || t[j] == t[k])
				if (t[++j] == t[++k])
					next[j] = next[k];
				else
					next[j] = k;
			else
				k = next[k];
		return next;
	}


	int strStr3(string haystack, string needle) {
		int res = -1;

		if (needle.empty()) return 0; //当 needle 是空字符串时我们应当返回 0

		int i = 0, k = 0, j = 0;

		for (; i < haystack.size() && j < needle.size();)
		{
			j = 0;
			if (haystack[i] == needle[j])
			{
				res = i;  //可能的合适的位置
				k = i;   //k暂时替代i指针
				while (k < haystack.size() && j < needle.size() && haystack[k] == needle[j])
				{
					k++;
					j++;
				}
				if (j == needle.size()) //找到了第一个满足题意的位置,直接返回res
				{
					return res;
				}
				 //否则，res变为-1，表明未找到合适的位置
				res = -1;
			}
			++i;
		}

		return res;
	}

	int strStr2(string haystack, string needle)
	{
		int i = 0; // 主串的位置
		int j = 0; // 模式串的位置
		while (i < haystack.size() && j < needle.size()) {
			if (haystack[i] == needle[j]) { // 当两个字符相同，就比较下一个
				i++;
				j++;
			}
			else {
				i = i - j + 1; // 一旦不匹配，i后退
				j = 0; // j归0
			}
		}
		if (j == needle.size()) {
			return i - j;
		}
		else {
			return -1;
		}

	}
};


//int main()
//{
//	Solution solu;
//	cout << solu.strStr("hello","ll");
//
//	system("pause");
//	return 0;
//}