/*
	202203-2 ���мƻ�
	Date: 2022.04.07
	Dev-CPP(C++����)
	�÷֣�100
	ʱ��ʹ�ã�295ms
	�ռ�ʹ�ã�3.585MB
	Others��ǰ׺�������㷨
*/

#include<iostream>


using namespace std;

int temp[200001] = { 0 };

int main()
{

	int k = 0;
	int num_plan = 0;
	int num_select = 0;

	int start = 0;
	int check = 0;
	int select = 0;

	cin >> num_plan >> num_select >> k;

	for (int i = 0; i < num_plan; i++)
	{
		cin >> start  >> check;
		temp[max(1, start - k - check + 1)]++;
		temp[max(1, start - k + 1)]--;
	}

	for (int i = 1; i < 200001; i++)
	{
		temp[i] = temp[i] + temp[i - 1];
	}

	for (int j = 1; j < num_select+1; j++)
	{
		cin >> select;
		cout << temp[select] << endl;
	}


}