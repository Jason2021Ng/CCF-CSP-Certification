/*
	202104-1 �Ҷ�ֱ��ͼ 
	Date: 2022.04.10
	Dev-CPP(C++����)
	�÷֣�100
	ʱ��ʹ�ã�125ms
	�ռ�ʹ�ã�3.050MB
*/

#include<iostream>
using namespace std;

int h[266] = {0};

int main()
{
	int n,m,L;
	int temp;
	cin>>n>>m>>L;
	for (int i=0; i<n*m; i++)
	{
		cin >> temp;
		h[temp]++;
	}
	for(int i=0; i<L; i++)
		cout<<h[i]<<" ";
}
