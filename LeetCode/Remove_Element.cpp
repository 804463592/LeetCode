/*

����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 1:

���� nums = [3,2,2,3], val = 3,

����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ�� 2:

���� nums = [0,1,2,2,3,0,4,2], val = 2,

����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��

ע�������Ԫ�ؿ�Ϊ����˳��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
˵��:

Ϊʲô������ֵ��������������Ĵ���������?

��ע�⣬�����������ԡ����á���ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�

����������ڲ���������:

// nums ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
int len = removeElement(nums, val);

// �ں������޸�����������ڵ������ǿɼ��ġ�
// ������ĺ������صĳ���, �����ӡ�������иó��ȷ�Χ�ڵ�����Ԫ�ء�
for (int i = 0; i < len; i++) {
	print(nums[i]);
}

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int ans=0;
		vector<int>::size_type i = 0;
		for (vector<int>::size_type j =0;j<nums.size();j++)
		{
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				i++;
				ans++;
			}
	
		}

		return ans;
	}

};

int main()
{
	Solution solu;
	vector<int> ivec = { 0,1,2,2,3,0,4,2 };

	//cout << solu.totalFruit2(mivec) << endl;;  //5
	cout << solu.removeElement(ivec, 2) << endl;;  //5

	for (int i = 0; i < ivec.size(); i++)
	{
		cout << ivec[i] << endl;
	}
	system("pause");
	return 0;
}









