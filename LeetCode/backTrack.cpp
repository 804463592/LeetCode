#include<iostream>
#include<vector>
using namespace std;

//《趣学算法》p252  大卖场购物车2：0-1背包问题
class backTrackSolution {
public:
	int  n =4 , W = 10;   //the num of trades, the maximum num of bag
	vector<double>  w = { 0,2,5,4,2}, v = { 0,6,9,20,4};

	void setnW(int n, int W)
	{
		if (n <= 0 || W <= 0)
		{
			cerr << "cerr:  invalid  n  and W! \n";
			return;
		}
		this->n = n;
		this->W = W;
	}

private:
	double cw = 0;
	double cp = 0;
	double bestp = 0;
	bool* bestx = new bool[n + 1];   //记录当前的最优决策解法
	bool* x = new bool[n + 1];       //记录当前解法

	double sumw = 0;
	double sumv = 0;

	double bound(int i)   //computing the bounding border: cp+rp
	{
		int rp = 0;// the rest price
		while (i <= n)
		{
			rp += v[i];
			i++;
		}
		return cp + rp;
	}

	void Backtrack(int t)
	{
		if (t > n)   //已经到达叶子结点
		{
			for (int j = 1; j <= n; j++)
			{
				bestx[j] = x[j];
			}
			//if(cp>bestp)
			   bestp = cp;
			return;
		}
		if (cw + w[t] <= W)     //满足条件则搜索左子树
		{
			x[t] = 1;
			cw += w[t];
			cp += v[t];
			Backtrack(t + 1);
			cw -= w[t];
			cp -= v[t];
		}
		if (bound(t + 1) > bestp) //满足满足条件，则搜索右子树
		{
			x[t] = 0;
			Backtrack(t + 1);
		}
	}

public:
	void Knapsack()
	{
		for (int i = 1; i <= n; i++)
		{
			sumv += v[i];
			sumw += w[i];
		}
		if (sumw <= W)
		{
			bestp = sumv;
			cout << "可以放入购物车中的物品的最大价值为：" << bestp << endl;
			cout << "所有物品均放入购物车即可。";
			return;
		}
		else
		{
			Backtrack(1);
			cout << "放入购物车中 物品的最大价值为：" << bestp << endl;
			cout << "放入购物车的物品编号为:";
			for (int i = 1; i <= n; i++)
			{
				if (bestx[i] == 1)
					cout << i << "\t";
			}
			cout << endl;

		}
	}

};

int main()
{
	backTrackSolution solu;

	double sumw = 0;
	double sumv = 0;
	int n = 4, W = 10;

	solu.Knapsack();

	system("pause");
	return 0;
}

