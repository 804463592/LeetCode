/*

��һ�����У��� i �������� tree[i] �͵�ˮ����
����Դ���ѡ����κ�����ʼ��Ȼ���ظ�ִ�����²��裺

��������ϵ�ˮ���Ž������������������������ͣ������
�ƶ�����ǰ���Ҳ����һ����������ұ�û��������ͣ������
��ע�⣬��ѡ��һ��������û���κ�ѡ�������ִ�в��� 1��Ȼ��ִ�в��� 2��Ȼ�󷵻ز��� 1��Ȼ��ִ�в��� 2���������ƣ�ֱ��ֹͣ��

�����������ӣ�ÿ�����ӿ���Я���κ�������ˮ��������ϣ��ÿ������ֻЯ��һ�����͵�ˮ����
��������������ռ���ˮ�������Ƕ��٣�



ʾ�� 1��

���룺[1,2,1]
�����3
���ͣ����ǿ����ռ� [1,2,1]��
ʾ�� 2��

���룺[0,1,2,2]
�����3
���ͣ����ǿ����ռ� [1,2,2].
������Ǵӵ�һ������ʼ�����ǽ�ֻ���ռ��� [0, 1]��
ʾ�� 3��

���룺[1,2,3,2,2]
�����4
���ͣ����ǿ����ռ� [2,3,2,2].
������Ǵӵ�һ������ʼ�����ǽ�ֻ���ռ��� [1, 2]��
ʾ�� 4��

���룺[3,3,3,1,2,1,1,2,3,3,4]
�����5
���ͣ����ǿ����ռ� [1,2,1,1,2].
������Ǵӵ�һ������ڰ˿�����ʼ�����ǽ�ֻ���ռ��� 4 ��ˮ����


��ʾ��

1 <= tree.length <= 40000
0 <= tree[i] < tree.length

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	//�о����һ�ַ�ʽ��������
	int totalFruit(vector<int>& tree) {
		//�൱����ֻ��������Ԫ�ص�������еĳ���
		int imax = 0;
		//���ܵ����ֵ
		int probableMax = tree.size();

		int i = 0, j = 0;
		for (i = 0; i < tree.size(); i++) {
			int basket1 = tree[i];//����1
			int basket2 = -1;//����2
			int total = 1;
			if (imax >= probableMax) {//������ֵ���ڻ���ڿ��ܵ����ֵ������ζ����Ҫ�������������ˣ�ֱ���ж�ѭ��
				break;
			}
			--probableMax;
			for (j = i + 1; j < tree.size(); j++) {
				int fruit = tree[j];
				if (fruit == basket1) {
					++total;
					continue;
				}
				if (basket2 == -1) {//�ж�����2��û��װˮ��
					basket2 = fruit;
					++total;
				}
				else {
					if (fruit == basket2) {
						++total;
					}
					else {
						break;//��ǰ�Ĺ�����������1������2��װ��ˮ�����ͣ�ֱ���жϵ�ǰѭ��
					}
				}
			}
			imax = max(total, imax);
		}
		return imax;


	}
	
	//���ַ���Ҳ����
	int totalFruit2(vector<int>& tree)
	{

	int len = tree.size();
	if (len <= 2) return len;
	int count = -1, i, j;
	bool flag = true;  //���Ա�ʾ�ڶ�������װ��ˮ��û�У�true��ʾûװ
	int a = tree[0], b = -1;

	//���һ��forѭ�����ҳ���һ������������������
	for (i = 0; i <= len; i++) 
	{
		if (i == len) return len;
		if (tree[i] != a && flag == true)
		{
			b = tree[i];
			flag = false;
		}
		if (tree[i] != a && flag == false && tree[i] != b) 
		{
			count = i;
			break;
		}
	}
	//a��b��ʾ����ˮ����j��ʾ�µ����
	a = tree[i - 1]; b = tree[i]; j = i - 1;
	for (; i <= len; i++)
	{
		while (tree[j] == tree[j - 1]) j--; //��������ڵĹ�����ˮ����ͬ����������Ҫǰ��
		if (i == len || (tree[i] != a  && tree[i] != b))
		{
			count = max(count, i - j);
			if (i == len) return count;
			a = tree[i - 1];
			b = tree[i];
			j = i - 1;
		}
	}
	return count;

	}
	int myTotalFruit(vector<int>& tree) 
	{
		int n_trees = tree.size();
		if (n_trees <= 2) {
			return n_trees;
		}
		int i, j;
		int basket1 = tree[0], basket2 = -1;
		int total = 1;
		for (i = 1; i < n_trees; i++)
		{
			int fruit = tree[i];
			if (fruit == basket1)
			{
				total++;
				//continue;
			}
			else if (basket2 == -1)  //����2��û��ˮ��
			{
				basket2 = fruit;
				total++;
			}
			else
			{
				if (basket2 == fruit)
				{
					total++;
				}
				else
				{
					break;
				}
			}
		}
		if (i == n_trees)//i��ʾ�����н����ĵ������һ���㣬��������Ե���n_trees
		{
			return n_trees;  //tree�����ֻ������ˮ��
			//return total;
		}
		//basket1,basket2��ʾ����ˮ����j��ʾ�µ���㣬
		basket1= tree[i - 1]; basket2 = tree[i]; j = i - 1;
		for (; i <= n_trees; i++)
		{
			while (tree[j] == tree[j - 1]) j--; //��������ڵĹ�����ˮ����ͬ����������Ҫǰ��
			if (i == n_trees || (tree[i] != basket1 && tree[i] != basket2))
			{
				total = max(total, i - j);
				if (i == n_trees) return total;
				basket1 = tree[i - 1];
				basket2 = tree[i];
				j = i - 1;
			}
		}
		return total;

	}


	int totalFruit3(vector<int>& tree)
	{

		if (tree.size() == 0)return 0;
		if (tree.size() == 1)return 1;
		int lo = 0;
		int maxv = 0;
		int res = 0;
		map<int, int> m;
		m[tree[lo]] = 0;//map��¼ÿһ���ʵ����һ�γ��ֵĴ�����
		int head = tree[lo];
		for (int hi = 1; hi < tree.size(); ++hi)
		{
			//cout<<lo<<" "<<hi<<endl;
			if (m.size() < 2 || (m.size() == 2 && m.find(tree[hi]) != m.end()))
			{
				m[tree[hi]] = hi;//���µ�ǰ���������ֵ�λ�á�
				maxv = hi - lo + 1;//�õ���ǰ��maxֵ
				res = max(res, maxv);
			}
			else if (m.size() == 2 && m.find(tree[hi]) == m.end())
			{
				lo = hi - 1;
				int temp = tree[lo];
				while (tree[lo] == temp)
				{
					lo--;
				}
				m.erase(tree[lo]);
				lo += 1;
				m[temp] = hi - 1;
				m[tree[hi]] = hi;
				maxv = hi - lo + 1;
				res = max(res, maxv);
			}
		}
		return res;
	}

	int totalFruit4(vector<int>& tree) {
		//�൱����ֻ��������Ԫ�ص�������еĳ���
		int a = -1, b = -1;
		int st = 0, res = 0, c = 0;

		for (int i = 0; i < tree.size(); i++)
		{
			if (tree[i] != a && tree[i] != b)
			{
				if (i - st > res)res = i - st;
				st = c;
				if (tree[c] == a)
				{
					b = tree[i];
				}
				else a = tree[i];
				c = i;
			}
			else if (tree[c] != tree[i])c = i;
		}
		if (res < tree.size() - st)res = tree.size() - st;
		return res;


	}

};

//int main()
//{
//	Solution solu;
//	vector<int> ivec = { 3,3,3,3,2,1,1,2,3,3,4 };
//	
//
//	vector<int> mivec = { 1,2,1 };
//
//	//cout << solu.totalFruit2(mivec) << endl;;  //5
//	cout << solu.myTotalFruit(ivec);  //5
//	system("pause");
//	return 0;
//}









