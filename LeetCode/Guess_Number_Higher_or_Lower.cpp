/*
我们正在玩一个猜数字游戏。 游戏规则如下：
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
每次你猜错了，我会告诉你这个数字是大了还是小了。
你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！
示例 :
输入: n = 10, pick = 6
输出: 6

*/

#include<iostream>
#include<vector>
using namespace std;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) 
{
	int res = 0;
	int target = 6;
	if (target<num) res = -1;
	else if (target>num) res = 1;
	else res = 0;
	return res;
};

class Solution {
public:
	int guessNumber(int n) {

		int low = 1, high = n;
		int mid = 0;
		while (low < high)
		{
			mid = low + (high - low) / 2;
			if (guess(mid) == 1) //target比mid更大
			{
				low = mid + 1;
			}
			else if (guess(mid) == -1) //target比mid更小
			{
				high = mid - 1;
			}
			else
			{
				return mid;
			}
		}

		return low;
	}
};

//int main()
//{
//	Solution solu;
//	cout << solu.guessNumber(10) << endl;
//
//	system("pause");
//	return 0;
//}