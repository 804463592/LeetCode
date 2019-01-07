#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string str ="1";
		for (int i = 0; i < n; i++)
		{
			str.append(to_string(1));
		}

		

		return str;
	}
};

int main() {

	Solution solu;
	string res =solu.countAndSay(2);
	cout << res<<endl;

	getchar();
	return 0;
}

