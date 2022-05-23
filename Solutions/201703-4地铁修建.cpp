/*
	201703-4 �����޽�
	Date: 2022.05.14
	Dev-CPP(C++����C++14��׼)
	�÷֣�100
	ʱ��ʹ�ã�437ms
	�ռ�ʹ�ã�7.335MB
	Others����С������ - Kruskal�㷨
*/

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

// ����� 
struct edge {
	int u, v;
	int weight;
	edge(int x, int y, int w) :u(x), v(y), weight(w) {}
};

bool cmpEdge(edge a, edge b)
{
	return a.weight < b.weight;
}

int father[100001];

// ���鼯 - ���Ҹ��ڵ�
int findroot(int x)
{
	if (father[x] == x)
		return x;
	return father[x] = findroot(father[x]); // ·��ѹ��
}

// Kruskal�㷨����С������
int kruskal(int v_num, int e_num, vector<edge>& E)
{
	for (int i = 0; i < v_num; i++)
	{
		father[i] = i;
	}
	sort(E.begin(), E.end(), cmpEdge);
	for (int i = 0; i < e_num; i++)
	{
		int Xroot = findroot(E[i].u);
		int Yroot = findroot(E[i].v);
		if (Xroot != Yroot)
		{
			father[Xroot] = Yroot;
			if(findroot(0) == findroot(v_num-1))
				return E[i].weight;
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector<edge> E;

	int v, e, w;
	for (int i = 0; i < m; i++)
	{
		cin >> v >> e >> w;
		v = v - 1;
		e = e - 1;
		E.push_back(edge(v, e, w));
	}

	int res = kruskal(n, m, E);
	cout << res << endl;
}