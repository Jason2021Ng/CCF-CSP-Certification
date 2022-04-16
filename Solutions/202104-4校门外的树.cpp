/*
	202104-4 У�������
	Date: 2022.04.10
	Dev-CPP(C++����C++14��׼)
	�÷֣�100
	ʱ��ʹ�ã�78ms 
	�ռ�ʹ�ã�14.25MB
	Others����̬�滮
	�ο���https://blog.csdn.net/m0_53641110/article/details/123450609 
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e3 + 10, ai = 1e5 + 10, MOD = 1e9 + 7;

int obstracle[N];
int method[N];

bool isdivisor[ai];
vector<int>divisor[ai];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> obstracle[i];
	}

	method[0] = 1;

	// ��ʼ��Լ��
	for (int i = 1; i < ai; i++)
	{
		for (int j = 2 * i; j < ai; j = j + i)
		{
			divisor[j].push_back(i);
		}
	}

	// ö������״̬
	for (int i = 0; i < n; i++)
	{
		memset(isdivisor, 0, sizeof(isdivisor));  

		// ����ö�����һ���������˵�
		for (int j = i - 1; j >= 0; j--)
		{
			// ���䳤��
			int d = obstracle[i] - obstracle[j];

			// �������ڵ�ѡ������
			int count = 0;

			// ö��d��ÿ��Լ��
			for (int k : divisor[d])
			{
				// �ж�k�Ƿ��Ѿ����ֹ�
				if (!isdivisor[k])
				{
					count++;
					isdivisor[k] = true;
				}
			}

			// �ϰ���㲻������
			isdivisor[d] = true;

			method[i] = (method[i] + (long long)method[j] * count) % MOD;
		}
	}

	cout << method[n - 1] << endl;
	return 0;
}
