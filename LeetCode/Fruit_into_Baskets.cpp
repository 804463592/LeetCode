/*

在一排树中，第 i 棵树产生 tree[i] 型的水果。
你可以从你选择的任何树开始，然后重复执行以下步骤：

把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。

你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
用这个程序你能收集的水果总量是多少？



示例 1：

输入：[1,2,1]
输出：3
解释：我们可以收集 [1,2,1]。
示例 2：

输入：[0,1,2,2]
输出：3
解释：我们可以收集 [1,2,2].
如果我们从第一棵树开始，我们将只能收集到 [0, 1]。
示例 3：

输入：[1,2,3,2,2]
输出：4
解释：我们可以收集 [2,3,2,2].
如果我们从第一棵树开始，我们将只能收集到 [1, 2]。
示例 4：

输入：[3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：我们可以收集 [1,2,1,1,2].
如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 个水果。


提示：

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
	//感觉这第一种方式，最好理解
	int totalFruit(vector<int>& tree) {
		//相当于求只包含两种元素的最长子序列的长度
		int imax = 0;
		//可能的最大值
		int probableMax = tree.size();

		int i = 0, j = 0;
		for (i = 0; i < tree.size(); i++) {
			int basket1 = tree[i];//篮子1
			int basket2 = -1;//篮子2
			int total = 1;
			if (imax >= probableMax) {//如果最大值大于或等于可能的最大值，则意味不需要继续进行运算了，直接中断循环
				break;
			}
			--probableMax;
			for (j = i + 1; j < tree.size(); j++) {
				int fruit = tree[j];
				if (fruit == basket1) {
					++total;
					continue;
				}
				if (basket2 == -1) {//判断篮子2有没有装水果
					basket2 = fruit;
					++total;
				}
				else {
					if (fruit == basket2) {
						++total;
					}
					else {
						break;//当前的果树不是篮子1和篮子2中装的水果类型，直接中断当前循环
					}
				}
			}
			imax = max(total, imax);
		}
		return imax;


	}
	
	//这种方法也不错
	int totalFruit2(vector<int>& tree)
	{

	int len = tree.size();
	if (len <= 2) return len;
	int count = -1, i, j;
	bool flag = true;  //用以表示第二个篮子装了水果没有，true表示没装
	int a = tree[0], b = -1;

	//这第一个for循环，找出第一个满足条件的子序列
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
	//a，b表示两种水果，j表示新的起点
	a = tree[i - 1]; b = tree[i]; j = i - 1;
	for (; i <= len; i++)
	{
		while (tree[j] == tree[j - 1]) j--; //将如果相邻的果树，水果相同，则起点必须要前移
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
			else if (basket2 == -1)  //篮子2中没有水果
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
		if (i == n_trees)//i表示子序列结束的点的再下一个点，因此最大可以等于n_trees
		{
			return n_trees;  //tree本身就只有两种水果
			//return total;
		}
		//basket1,basket2表示两种水果，j表示新的起点，
		basket1= tree[i - 1]; basket2 = tree[i]; j = i - 1;
		for (; i <= n_trees; i++)
		{
			while (tree[j] == tree[j - 1]) j--; //将如果相邻的果树，水果相同，则起点必须要前移
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
		m[tree[lo]] = 0;//map记录每一个词的最后一次出现的次数。
		int head = tree[lo];
		for (int hi = 1; hi < tree.size(); ++hi)
		{
			//cout<<lo<<" "<<hi<<endl;
			if (m.size() < 2 || (m.size() == 2 && m.find(tree[hi]) != m.end()))
			{
				m[tree[hi]] = hi;//更新当前类型最后出现的位置。
				maxv = hi - lo + 1;//得到当前的max值
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
		//相当于求只包含两种元素的最长子序列的长度
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









