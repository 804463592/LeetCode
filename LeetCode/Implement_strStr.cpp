/*
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {

		//KMP�㷨
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
	//KMP�㷨�е�next
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

		if (needle.empty()) return 0; //�� needle �ǿ��ַ���ʱ����Ӧ������ 0

		int i = 0, k = 0, j = 0;

		for (; i < haystack.size() && j < needle.size();)
		{
			j = 0;
			if (haystack[i] == needle[j])
			{
				res = i;  //���ܵĺ��ʵ�λ��
				k = i;   //k��ʱ���iָ��
				while (k < haystack.size() && j < needle.size() && haystack[k] == needle[j])
				{
					k++;
					j++;
				}
				if (j == needle.size()) //�ҵ��˵�һ�����������λ��,ֱ�ӷ���res
				{
					return res;
				}
				 //����res��Ϊ-1������δ�ҵ����ʵ�λ��
				res = -1;
			}
			++i;
		}

		return res;
	}

	int strStr2(string haystack, string needle)
	{
		int i = 0; // ������λ��
		int j = 0; // ģʽ����λ��
		while (i < haystack.size() && j < needle.size()) {
			if (haystack[i] == needle[j]) { // �������ַ���ͬ���ͱȽ���һ��
				i++;
				j++;
			}
			else {
				i = i - j + 1; // һ����ƥ�䣬i����
				j = 0; // j��0
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