#include<iostream>
#include<vector>
using namespace std;

//��Ȥѧ�㷨��p252  ���������ﳵ2��0-1��������
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
	bool* bestx = new bool[n + 1];   //��¼��ǰ�����ž��߽ⷨ
	bool* x = new bool[n + 1];       //��¼��ǰ�ⷨ

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
		if (t > n)   //�Ѿ�����Ҷ�ӽ��
		{
			for (int j = 1; j <= n; j++)
			{
				bestx[j] = x[j];
			}
			//if(cp>bestp)
			   bestp = cp;
			return;
		}
		if (cw + w[t] <= W)     //��������������������
		{
			x[t] = 1;
			cw += w[t];
			cp += v[t];
			Backtrack(t + 1);
			cw -= w[t];
			cp -= v[t];
		}
		if (bound(t + 1) > bestp) //��������������������������
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
			cout << "���Է��빺�ﳵ�е���Ʒ������ֵΪ��" << bestp << endl;
			cout << "������Ʒ�����빺�ﳵ���ɡ�";
			return;
		}
		else
		{
			Backtrack(1);
			cout << "���빺�ﳵ�� ��Ʒ������ֵΪ��" << bestp << endl;
			cout << "���빺�ﳵ����Ʒ���Ϊ:";
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

