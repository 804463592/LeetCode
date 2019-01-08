#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string readNextStr(string s) {
		int n = 1;
		int i = 0;
		string res_str ="";
		while(i < s.size())   //while
		{
			if (s[i] == s[i + 1])
			{

				while (((i+1)<s.size()) && s[i] == s[i + 1])
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
		string str ="1";
		for (int i = 0; i < n-1; i++)
		{
			str = readNextStr(str);
		
		}

		return str;
	}
};

int main() {

	Solution solu;
	//string res = solu.readNextStr(to_string(13112221));
	string res = solu.countAndSay(5);
	cout << res<<endl;

	//string str;
	//str.push_back(res[2]);
	//cout << str;
	//cout << res[0];

	getchar();
	return 0;
}

