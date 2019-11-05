////program 6-2
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//#include <queue>
//using namespace std;
//const int INF = 1e7;  //����������ֵΪ10^7
//const int N = 100;
//double g[N][N];  //�����ͼ�ڽӾ���
//int bestx[N];   //��¼��ǰ����·��
//double bestl;     //��ǰ����·������
//int n, m;       //�������n,����m
//struct Node//������,��¼��ǰ���Ľ���Ϣ
//{
//	double cl; //��ǰ���߹���·������
//	int id; //�������
//	int x[N];//��¼��ǰ·��
//	Node() {}
//	Node(double _cl, int _id)
//	{
//		cl = _cl;
//		id = _id;
//	}
//};
//
////������е����ȼ��� ��clΪ���ȼ���clֵԽС��Խ����
//bool operator <(const Node &a, const Node &b)
//{
//	return a.cl > b.cl;
//}
//
////Travelingbfs Ϊ���ȶ���ʽ��֧�޽編����
//double Travelingbfs()
//{
//	int t; //��ǰ����ľ������t
//	Node livenode, newnode;//���嵱ǰ��չ���livenode,�����½��newnode
//	priority_queue<Node> q; //����һ�����ȶ���,���ȼ�Ϊ�Ѿ��߹���·������cl,clֵԽС��Խ����
//	newnode = Node(0, 2);//�������ڵ�
//	for (int i = 1; i <= n; i++)
//	{
//		newnode.x[i] = i;//��ʱ�������Ľ�����
//	}
//	q.push(newnode);//�����������ȶ���
//	cout << "�����ȼ�����˳��" << endl;//���ڵ���
//	while (!q.empty())
//	{
//		livenode = q.top();//ȡ����ͷԪ����Ϊ��ǰ��չ���livenode
//		q.pop(); //��ͷԪ�س���
//		//���ڵ���
//		cout << "��ǰ����idֵ:" << livenode.id << "��ǰ����clֵ:" << livenode.cl << endl;
//		cout << "��ǰ���Ľ�����:";
//		for (int i = 1; i <= n; i++)
//		{
//			cout << livenode.x[i];
//		}
//		cout << endl;
//
//		t = livenode.id;//��ǰ����ľ������
//		// �ѵ�������2�����ʱ�������ʱ����Ҫ��������
//		if (t == n)  //�����ж��Ƿ�������Ž⣬
//			//���統ǰ�ҵ�һ��·��(1243)������4�Ž��ʱ�������ж�g[4][3]��g[3][1]�Ƿ��б�������
//			//����б����жϵ�ǰ·������cl+g[4][3]+g[3][1]<bestl���������������ֵ�����Ž�
//		{
//			//˵���ҵ���һ�����õ�·������¼�����Ϣ
//			if (g[livenode.x[n - 1]][livenode.x[n]] != INF && g[livenode.x[n]][1] != INF)
//				if (livenode.cl + g[livenode.x[n - 1]][livenode.x[n]] + g[livenode.x[n]][1] < bestl)
//				{
//					bestl = livenode.cl + g[livenode.x[n - 1]][livenode.x[n]] + g[livenode.x[n]][1];
//					cout << endl;
//					cout << "��ǰ���ŵĽ�����:";
//					for (int i = 1; i <= n; i++)
//					{
//						bestx[i] = livenode.x[i];
//						cout << bestx[i];
//					}
//					cout << endl;
//					cout << endl;
//				}
//			continue;
//		}
//		//�жϵ�ǰ����Ƿ������޽���������������㲻����չ
//		if (livenode.cl >= bestl)
//			continue;
//		//��չ
//		//û�е���Ҷ�ӽ��
//		for (int j = t; j <= n; j++)//������չ�������з�֧
//		{
//			if (g[livenode.x[t - 1]][livenode.x[j]] != INF)//���x[t-1]������x[j]�����б�����
//			{
//				double cl = livenode.cl + g[livenode.x[t - 1]][livenode.x[j]];
//				if (cl < bestl)//�п��ܵõ����̵�·��
//				{
//					newnode = Node(cl, t + 1);
//					for (int i = 1; i <= n; i++)
//					{
//						newnode.x[i] = livenode.x[i];//������ǰ�Ľ�����
//					}
//					swap(newnode.x[t], newnode.x[j]);//����x[t]��x[j]����Ԫ�ص�ֵ
//					q.push(newnode);//�½�����
//				}
//			}
//		}
//	}
//	return bestl;//��������ֵ��
//}
//
//void init()//��ʼ��
//{
//	bestl = INF;
//	for (int i = 0; i <= n; i++)
//	{
//		bestx[i] = 0;
//	}
//	for (int i = 1; i <= n; i++)
//		for (int j = i; j <= n; j++)
//			g[i][j] = g[j][i] = INF;//��ʾ·�����ɴ�
//}
//void print()//��ӡ·��
//{
//	cout << endl;
//	cout << "���·��:  ";
//	for (int i = 1; i <= n; i++)
//		cout << bestx[i] << "--->";
//	cout << "1" << endl;
//	cout << "���·�����ȣ�" << bestl;
//}
//
//int main()
//{
//	int u, v, w;//u,v������У�w����u��v����֮��·�ĳ���
//	cout << "�����뾰���� n(�����):";
//	cin >> n;
//	init();
//	cout << "�����뾰��֮���������(����):";
//	cin >> m;
//	cout << "������������������u��v֮��ľ���w,��ʽ:����u ����v ����w:" << endl;
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> u >> v >> w;
//		g[u][v] = g[v][u] = w;
//	}
//	Travelingbfs();
//	print();
//	system("pause");
//	return 0;
//}

//program6-2 �Լ�ʵ�ְ汾
#include<iostream>
#include<queue>
using namespace std;

const int INF = 1e7;
const int N = 100;

double g[N][N];    //�����ͼ���ڽӾ���
int bestx[N];         //��¼���Ž�

double bestl;      //��¼����·������
int n, m;           //����ĸ���n������m

struct Node
{
	double cl;    //���ڸý�㣬��ǰ�Ѿ��߹���·������
	int id;  //ʵ�����ǽ���Ĳ����
	int x[N];    //��¼��ǰ����������·��
	Node() {
		this->cl = 0;
		this->id = id;
	}
	Node(double cl, int id)
	{
		this->cl = cl;
		this->id = id;
	}
};

bool operator<(const Node&a, const Node&b)
{
	return a.cl > b.cl;
}

double Travelingbfs()
{//��֧���編�����ù����������



	Node livenode, newnode;
	//��һ����������ԭ���Ĵ����У�ʹ��if(t==n)�������һ��������⴦��

	//������������ڵ�,�ӵڶ�����㿪ʼ;Ҳ����id =2������livenode�е�x[1] ��ȷ���ģ�id=3�����ʾx[1],x[2]�Ѿ�ȷ��
	//��ô����n =4�����⣬id���ս��ӵ�5��Ҳ����˵�����һ��livenode��idΪ5��������Ӧ��ʹ��if(t>n)��
	

	//������ʹ��if(t==n)Ҳ���ǲ����ԣ���ô��ʼ��ʱ����Ҫ��ʼ��id =1����ʱid =1������x[1]��ȷ���ģ�id =3������x[1],x[2],x[3]��ȷ����
	//���˾��÷�ʽ�����������������ģ���һ����㣬������һ���Ѿ�ȷ���ˣ���������ԭ����һ����id =2�Ŵ���x[1]�Ѿ�ȷ�����ܻ��ҡ����ַ�ʽ��������

	//��ʽ�������������淽ʽ��ʼ��
	//Node newnode(0,2);
	//Node* p_newnode = new Node(0,2);
	//Node newnode = Node(0, 2);

	//��ʽ������
	//������ڵ�
	newnode.cl = 0;
	newnode.id = 1;
	for (int i = 1; i <= n; i++)
	{
		newnode.x[i] =i;
	}
	priority_queue<Node> q;
	q.push(newnode);

	int t;  //��ʾ��ǰ�Ĳ���
	while (!q.empty())
	{
		//���ȶ��ж�ͷ����
		livenode = q.top();
		q.pop();

		//���ڵ���
		cout << "��ǰ����idֵ:" << livenode.id <<"\t"<< "��ǰ����clֵ:" << livenode.cl << endl;
		cout << "��ǰ���Ľ�����:";
		for (int i = 1; i <= n; i++)
		{
			cout << livenode.x[i];
		}
		cout << endl<<endl;
		t = livenode.id;

       //��ʽ��������Ϊ��if(t>n)
		if (t ==n)
		{
			/*
			�ж��Ƿ�Ϊ��ǰ���Ž⣺Ҫ��֤���һ������������ͨ·��
			ͬʱ��·��Ҫ���
			*/
			if (g[1][livenode.x[n]] != INF && livenode.cl + g[1][livenode.x[n]] < bestl)
			{
				//��������������һ��·�ߣ�ͬʱ����bestl
				for (int i = 1; i <= n; i++)
				{
					bestx[i] = livenode.x[i];
				}
				bestl = livenode.cl + g[1][livenode.x[n]];
			}
			continue;
		}
		if (livenode.cl > bestl)
			continue;
		//��ʽ��������Ϊ��for (int j = t; j <= n; j++)
		for (int j = t+1; j <= n; j++)
		{
			//��ʽ��������Ϊ��	if (g[livenode.x[j]][livenode.x[t-1]] != INF)
			//���x[j]�����x[t-1]����ɵ�����ж��Ƿ���ܻ���µ�bestl
			if (g[livenode.x[j]][livenode.x[t]] != INF)
			{
				//��ʽ��������Ϊ��	double cl = livenode.cl + g[livenode.x[j]][livenode.x[t-1]];
				double cl = livenode.cl + g[livenode.x[j]][livenode.x[t]];

				if (cl < bestl)
				{
					//˵���ý�������չ�ӽ���������У���Ϊ��ǰ��cl����С��bestl��
					newnode = Node(cl, t+1);
					for (int i = 1; i <= n; i++)
					{
						newnode.x[i] = livenode.x[i];
					}
					//��ʽ��������Ϊ��swap(newnode.x[t], newnode.x[j]);
					swap(newnode.x[t+1], newnode.x[j]);
					//�µĽ�������
					q.push(newnode);
				}
			}
		}
	}
	return bestl;
}

void init()
{
	bestl = INF;
	for (int i = 0; i <= n; i++)
	{
		bestx[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = INF;
		}
	//ֱ�ӳ�ʼ������ͨ������̨
	n = 4;
	m = 6;
	g[1][2] = g[2][1] = 15;
	g[1][3] = g[3][1] = 30;
	g[1][4] = g[4][1] = 5;
	g[2][3] = g[3][2] = 6;
	g[2][4] = g[4][2] = 12;
	g[3][4] = g[4][3] = 3;
}

void print()
{
	cout << endl;
	cout << "���·��Ϊ��";
	for (int i = 1; i <= n; i++)
	{
		cout << bestx[i] << "--->";
	}
	cout << "1" << endl;
	cout << "���·������Ϊ��" << bestl;
}

int main()
{
	init();
	Travelingbfs();
	print();
	system("pause");
	return 0;
}









