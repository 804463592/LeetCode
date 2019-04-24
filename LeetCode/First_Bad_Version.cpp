/*

���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣
����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�
�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��
�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����

ʾ��:

���� n = 5������ version = 4 �ǵ�һ������İ汾��

���� isBadVersion(3) -> false
���� isBadVersion(5) -> true
���� isBadVersion(4) -> true

���ԣ�4 �ǵ�һ������İ汾��

*/

#include<iostream>
#include<vector>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	bool flag = false;
	if (version >= 5) flag = true;
	cout << "������api" << endl;
	return flag;
};

class Solution {
public:
	int firstBadVersion(int n) {
		if (n == 1) return 1;
		int low = 1, high = n;
		int mid = 0;
		while (high > low)
		{
			mid = (-low + high) / 2 + low; //��ôд��Ϊ�˷�ֹ��n�ر��ʱ���ܵ����
			if (isBadVersion(mid))
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}

		}
		return low;
	}
};

//int main()
//{
//	Solution solu;
//	cout << solu.firstBadVersion(10) << endl;
//
//	system("pause");
//	return 0;
//}