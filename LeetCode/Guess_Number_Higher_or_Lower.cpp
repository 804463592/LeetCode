/*
����������һ����������Ϸ�� ��Ϸ�������£�
�Ҵ� 1 �� n ѡ��һ�����֡� ����Ҫ����ѡ�����ĸ����֡�
ÿ����´��ˣ��һ��������������Ǵ��˻���С�ˡ�
�����һ��Ԥ�ȶ���õĽӿ� guess(int num)�����᷵�� 3 �����ܵĽ����-1��1 �� 0����
-1 : �ҵ����ֱȽ�С
 1 : �ҵ����ֱȽϴ�
 0 : ��ϲ����¶��ˣ�
ʾ�� :
����: n = 10, pick = 6
���: 6

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
			if (guess(mid) == 1) //target��mid����
			{
				low = mid + 1;
			}
			else if (guess(mid) == -1) //target��mid��С
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