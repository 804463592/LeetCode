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

	//����ÿ��������������������֮ǰû������Ŀ˵��ÿ�������������
	int numRescueBoatsNotLimit(vector<int>& people, int limit)
	{
		
		//for (int i = 0; i < people.size(); i++)
		//{
		//	cout << people[i] << endl;
		//}
		//������limit������£������ܵ���ÿ�Ҵ�������
		int n_boats=0;
		int n_people = people.size();

		if (n_people == 1)
		{
			return people[0] > limit ? 0: 1;
		}
		if (n_people == 2)
		{
			return people[0] + people[1] > limit ? 2 : 1;
		}
		//��vector��С��������
		sort(people.begin(), people.end());
		int weight_boats = 0; //�����˵�����
		int pa = 0,pb =n_people-1;//˫ָ��
		while (pa<pb)
		{
			//������˫ָ�����Ŀ��һ�������ܿ���whileѭ������if else����鷳
			while (people[pb] + weight_boats <= limit) 
			{
				weight_boats += people[pb];
				pb--;
			}
			while (people[pa] + weight_boats <= limit)
			{
				weight_boats += people[pa];
				pa++;
			}
			weight_boats = 0;

			++n_boats;

			if (pa == pb) 
			{
				++n_boats;
			}
		}
		return n_boats;
	}

	//ÿ�������������ˣ���Ҫ�Ĵ�������,������Ŀ��Ҫ�Ľ��
	int numRescueBoats(vector<int>& people, int limit) 
	{
		sort(people.begin(), people.end());
		int left = 0, right = people.size() - 1;
		int boats_num = 0;
		while (left <= right)
		{
			if (people[left] + people[right]<=limit) //��������
			{
				left++;
				right--;
			}
			else  //ֻ���ص���
			{
				right--;
			}
			boats_num++;
		}
		return boats_num;
	}


};

int main()
{
	Solution solu;
	vector<int> input_people = {1,1,3,2,5,3 };
	int limit = 5;

	cout << "ÿ����������������Ҫ�Ĵ�������Ϊ��" << solu.numRescueBoatsNotLimit(input_people, limit) << endl;

	cout << "ÿ�������������ˣ���Ҫ�Ĵ�������Ϊ��" << solu.numRescueBoats(input_people, limit);
	system("pause");
	return 0;
}
