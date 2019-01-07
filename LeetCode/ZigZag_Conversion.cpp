/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

*/

#include <string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows)
	{
		string addstr;
		if (1 == numRows || numRows <= 0)
		{
			addstr = s;//���ֲ���
		}
		else {

			int i = 0;
			vector<int> index;

			//��һ��Ҫ��������
			while (i < s.size())
			{
				index.push_back(i);   //�����µ�һ��ÿ��Ԫ�ص�λ��
				addstr.push_back(s[i]);
				i = i + 2 * (numRows - 2) + 2;

			}

			//�м��ѭ������
			for (int k = 1; k < numRows - 1; k++)
			{
				for (int q = 0; q < index.size(); q++)
				{
					if ((index[q] + k) < s.size())
					{
						addstr.push_back(s[index[q] + k]);

					}

					if ((index[q] + k + 2 * (numRows - k - 2) + 2) < s.size())
					{
						addstr.push_back(s[index[q] + k + 2 * (numRows - k - 2) + 2]);

					}
				}
			}

			//���һ���ֵ�������
			int p = 0;
			while ((p + numRows - 1) < s.size())
			{

				addstr.push_back(s[p + numRows - 1]);
				p = p + 2 * (numRows - 2) + 2;

			}
		}

		return addstr;
	}

};

//int main()
//{
//	string sss = "LEETCODEISHIRING";
//	int num = 1;
//	Solution solu;
//	cout << solu.convert(sss, num) << endl;
//
//	getchar();
//	return 0;
//}