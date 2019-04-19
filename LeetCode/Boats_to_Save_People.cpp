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

	//这是每条船不限人数的做法，之前没看到题目说的每条船最多坐两人
	int numRescueBoatsNotLimit(vector<int>& people, int limit)
	{
		
		//for (int i = 0; i < people.size(); i++)
		//{
		//	cout << people[i] << endl;
		//}
		//在满足limit的情况下，尽可能的让每艘船多坐人
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
		//对vector从小到大排序
		sort(people.begin(), people.end());
		int weight_boats = 0; //船上人的重量
		int pa = 0,pb =n_people-1;//双指针
		while (pa<pb)
		{
			//像这种双指针的题目，一定尽可能考虑while循环，用if else会很麻烦
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

	//每辆船限人数两人，需要的船的数量,这是题目需要的结果
	int numRescueBoats(vector<int>& people, int limit) 
	{
		sort(people.begin(), people.end());
		int left = 0, right = people.size() - 1;
		int boats_num = 0;
		while (left <= right)
		{
			if (people[left] + people[right]<=limit) //坐两个人
			{
				left++;
				right--;
			}
			else  //只坐重的人
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

	cout << "每辆船不限人数，需要的船的数量为：" << solu.numRescueBoatsNotLimit(input_people, limit) << endl;

	cout << "每辆船限人数两人，需要的船的数量为：" << solu.numRescueBoats(input_people, limit);
	system("pause");
	return 0;
}
