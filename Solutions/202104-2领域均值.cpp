/*
	202104-2 �����ֵ
	Date: 2022.04.10
	Dev-CPP(C++����)
	�÷֣�100
	ʱ��ʹ�ã�171ms
	�ռ�ʹ�ã�5.644MB
	Others��ǰ׺�������㷨
*/

#include<iostream>
using namespace std;

int image[602][602] = { 0 };
int sum_image[602][602] = { 0 };

int main()
{
	int n, L, r, t;
	cin >> n >> L >> r >> t;
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> image[i][j];
			// �����άǰ׺��
			sum_image[i][j] = sum_image[i - 1][j] + sum_image[i][j - 1] - sum_image[i - 1][j - 1] + image[i][j];

		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// ȷ�������½�
			int x_down = max(1, i - r);
			int y_down = max(1, j - r);

			// ȷ�������Ͻ� 
			int x_up = min(n, i + r);
			int y_up = min(n, j + r);

			// �����������غ�
			int sum_pixel = sum_image[x_up][y_up] - sum_image[x_down-1][y_up] - sum_image[x_up][y_down-1] + sum_image[x_down-1][y_down-1];
			int sum_t = (y_up - ( y_down - 1)) * (x_up - ( x_down - 1));

			if (sum_t * t >= sum_pixel)
				num++;

		}
	}


	cout << num;
}