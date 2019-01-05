/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix)
	{
		//这道题的思路,先上下镜像对称(垂直翻转),再转置

		//垂直翻转
		for (size_t i = 0; i < matrix.size()/2; i++)
		{
			for (size_t j = 0; j < matrix[i].size(); j++) {

				int temp = 0;
				temp = matrix[i][j];
				matrix[i][j] = matrix[matrix.size() - i - 1][j];
				matrix[matrix.size() - i - 1][j] = temp;
			}

		}
		//转置
		for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t j = i; j < matrix[i].size(); j++) {  //注意j不要从0开始,否则会转置两次,相当于没有转置

				int temp = 0;
				temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;

			}

		}



		////水平翻转
		//for (vector<vector<int>>::iterator iter1 = matrix.begin(); iter1 != matrix.end(); iter1++)
		//{
		//	for (int i = 0; i < int(iter1->size()) / 2; i++)
		//	{
		//		int temp = 0;
		//		temp = (*iter1)[0 + i];
		//		(*iter1)[0 + i] = (*iter1)[iter1->size() - i-1];  //减一,不然索引溢出
		//		(*iter1)[iter1->size() - i-1] = temp;

		//	}
		//}

	}
};


int main() {

	vector<int> ivec1 = { 1,2,3 };
	vector<int> ivec2 = { 4,5,6 };
	vector<int> ivec3 = { 7,8,9 };

	vector<vector<int>> ivec;
	ivec.push_back(ivec1);
	ivec.push_back(ivec2);
	ivec.push_back(ivec3);

	Solution solu;
	solu.rotate(ivec);  //旋转图像


	for (vector<vector<int>>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{
		for (vector<int>::iterator iter = it->begin(); iter != it->end(); iter++)
		{

			cout << *iter << "  ";
		}
		cout << endl << endl;

	}


	system("pause");

	return 0;
}