/*
	201812-4 ��������
	Date: 2022.05.23
	Dev-CPP(C++����C)
	�÷֣�100
	ʱ��ʹ�ã�218ms
	�ռ�ʹ�ã�5.753MB
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
	int ans = 0;
	int count = 0;
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
			ans = max(ans, E[i].weight);
			count++;
			if (count == v_num - 1)
				return ans;
		}
	}

}


int main()
{
	int n, m, root;
	cin >> n;
	cin >> m;
	cin >> root;

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