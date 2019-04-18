/*

第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。

每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。

返回载到每一个人所需的最小船数。(保证每个人都能被船载)。



示例 1：

输入：people = [1,2], limit = 3
输出：1
解释：1 艘船载 (1, 2)
示例 2：

输入：people = [3,2,2,1], limit = 3
输出：3
解释：3 艘船分别载 (1, 2), (2) 和 (3)
示例 3：

输入：people = [3,5,3,4], limit = 5
输出：4
解释：4 艘船分别载 (3), (3), (4), (5)
提示：

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
		//先对vector排序
		sort(people.begin(), people.end());

		//for (int i = 0; i < people.size(); i++)
		//{
		//	cout << people[i] << endl;
		//}

		//在满足limit的情况下，尽可能的让每艘船多坐人
		int n_boats=0;
		int n_people = people.size();
		int weight_boats = 0; //船上人的重量
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
