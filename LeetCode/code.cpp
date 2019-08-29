#include<iostream>
#include <math.h>
#include<vector>
using namespace std;
int getAge(int W, int Y, float x, int N)
{
	int temp_Y = Y;
	for (int i = 0; i < N; i++)
	{
		temp_Y++;
		temp_Y = ((W*(1 - x)*temp_Y + W * x * 21) / W);
	}
	return ceil(temp_Y);
}

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {

		//binary search
		int left = 0, right = A.size() - 1; //avoid integer overflow,because 0 < i < A.length - 1
		int mid = 1;

		while (left < right)
		{
			mid = int(left + (right - left) / 2);
			if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1])
				return mid;
			 if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1])
			{
				left = mid ;
			}
			else if (A[mid] < A[mid - 1] && A[mid] > A[mid + 1]) {
				right = mid ;
			}
		}
		return  mid;
	}
};


//int main()
//{
//	int hh = getAge(100, 30, 0.3, 1);
//	//cout << hh;
//	
//	vector<int> peak_arr = { 24,69,100,99,79,78,67,36,26,19};
//	Solution solu;
//	cout << solu.peakIndexInMountainArray(peak_arr)<<endl;
//	system("pause");
//	return 0;
//}