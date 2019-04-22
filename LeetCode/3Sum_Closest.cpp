/*

����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������
ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�

���磬�������� nums = [-1��2��1��-4], �� target = 1.

�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest2(vector<int>& nums, int target) {

		sort(nums.begin(), nums.end());
        /*res��ʼ��Ϊǰ����Ԫ��֮������õģ���ʼ��Ϊ0���ܴ���bug��0�������target��
		��0��һ��Ϊ����Ԫ��֮��*/
		int res = nums[0] + nums[1] + nums[2]; 
		int tmp_sum = 0;

		for (int k = nums.size() - 1; k >= 2;) {

			for (int i = 0, j = k - 1; i < j;) {

				tmp_sum = nums[i] + nums[j] + nums[k];
				if (tmp_sum  < target)
				{//С��0����i����,�Ӷ���nums[i]����
					i++;
					//�����ȥ�ظ����룬����ظ�Ԫ�رȽ϶�Ļ������Ͽ�������ٶȣ���������ݺ���û�����ظ��ģ��������ٶȷ�������
					/*while (i < j &&nums[i - 1] == nums[i]) {
						i++;
					}*/
				}
				else if (tmp_sum > target) {
					//����0����j����
					j--;
				   /*while (i < j &&nums[j + 1] == nums[j])
				   {
						j--;
					}*/
				}
				else { //����target,��ֱ�ӷ���target,ͬʱ�ƶ�ij,ȥ�����ظ���ֵ
					return target;
				}
				//�ж��Ƿ���Ҫ����res
				if (abs(target - tmp_sum) < abs(target - res))
				{
					res = tmp_sum;
				}
			}
			//k�ƶ�,�ƶ�ʱҪȥ����Ӧֵ�ظ���k������ٶ�
			k--;
		    /*while (k >= 2 && nums[k + 1] == nums[k])
			{
				k--;
			}*/

		}

		return res;



	}

	//���棬��ָ��
	int threeSumClosest(vector<int>& nums, int target) {

		sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];
		int tmp_sum = 0;
		for (int k = nums.size() - 1; k >= 2;)
		{
			for (int i = 0, j = k - 1; i < j;)
			{
				tmp_sum = nums[i] + nums[j] + nums[k];
				if (tmp_sum < target) i++;
				else if (tmp_sum > target) j--;
				else return target;
				if (abs(target - tmp_sum) < abs(target - res)) res = tmp_sum;
			}
			k--;
		}
		return res;
	}
};

//int main() {
//
//	vector<int> ivec = {-1,2,1,-4};
//
//	Solution solu;
//
//	int res = solu.threeSumClosest(ivec,1);
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//}