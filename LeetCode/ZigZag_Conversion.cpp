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
using namespace std;

class Solution {
public:
	string convert(string s, int numRows)
	{
		string addstr;
		int i = 0;
		while (i < s.size()) {

		
			addstr.push_back(s[i]);
			//addstr.push_back(s[i + 2 * (numRows - 2) + 2]);
			i = i + 2 * (numRows - 2) + 2;

		}







		return addstr;
	}

};

int main()
{
	string sss = "LEETCODEISHIRING";
	int num = 3;
	Solution solu;
	cout << solu.convert(sss, num) << endl;


	getchar();
	return 0;
}