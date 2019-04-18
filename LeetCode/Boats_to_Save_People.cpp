/*

�� i ���˵�����Ϊ people[i]��ÿ�Ҵ����Գ��ص��������Ϊ limit��

ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit��

�����ص�ÿһ�����������С������(��֤ÿ���˶��ܱ�����)��



ʾ�� 1��

���룺people = [1,2], limit = 3
�����1
���ͣ�1 �Ҵ��� (1, 2)
ʾ�� 2��

���룺people = [3,2,2,1], limit = 3
�����3
���ͣ�3 �Ҵ��ֱ��� (1, 2), (2) �� (3)
ʾ�� 3��

���룺people = [3,5,3,4], limit = 5
�����4
���ͣ�4 �Ҵ��ֱ��� (3), (3), (4), (5)
��ʾ��

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		//�ȶ�vector����
		sort(people.begin(), people.end());

		//for (int i = 0; i < people.size(); i++)
		//{
		//	cout << people[i] << endl;
		//}

		//������limit������£������ܵ���ÿ�Ҵ�������
		int n_boats=0;
		int n_people = people.size();
		int weight_boats = 0; //�����˵�����
		int p = 0;
		while (p<n_people)
		{
			if (people[p] + weight_boats < limit)
			{
				weight_boats += people[p];
				p++;
			}
			else
			{
				++n_boats;
				weight_boats = 0;
				p++;
			}
			

		}




		return n_boats;
	}
};

int main()
{
	Solution solu;
	vector<int> input_people = { 3,2,2,1 };
	int limit = 3;

	cout << solu.numRescueBoats(input_people, limit);
	system("pause");
	return 0;
}
