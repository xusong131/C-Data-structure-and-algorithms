#include<iostream>
#include<time.h>

//ð������O(N^2) �ȶ�
void bubble_sort(int arr[], int len)
{
	for (int j=0;j<len-1;++j)
	{
		bool flag = false;
		for (int i = 0; i < len - 1 - j; ++i)
		{
			
			if (arr[i] > arr[i + 1])
			{
				int temp = 0;
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = true;
			}
			
		}
		if (!flag)
			return;
	}
}

//ѡ������O(N^2) ���ȶ�
void select_sort(int arr[],int len)
{
	for (int i = 0; i < len - 1; ++i) //����
	{
		int min = arr[i];
		int min_key = i;
		for (int j = i + 1; j < len; ++j) //ÿһ�ֱȽϵĴ���
		{
			if (arr[j] < min)
			{
				min = arr[j];
				min_key = j;
			}
		}

		//�Ѿ�Ϊ��Сֵ����ʼ����
		if (min_key != i)
		{
			int temp = 0;
			temp = arr[i];
			arr[i] = min;
			arr[min_key] = temp;
		}
	}
}

//�������� ���O(N),���O(N^2) �ȶ�
void insert_sort(int arr[],int len)
{
	for (int i = 1; i < len; ++i)
	{	
		int val = arr[i];
		int j = i - 1;
		for ( ; j >= 0; --j)
		{
			if (arr[j] <= val)
			{
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}
}

int main()
{
	const int len = 10;
	srand(time(NULL));
	int arr[len] = { 0 };

	std::cout << "���ɵ����У�" << std::endl;
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % 100 + 1;
		std::cout << arr[i] << " ";
	}

	//bubble_sort(arr,len);
	//select_sort(arr,len);
	insert_sort(arr,len);

	std::cout << std::endl << "���������:" << std::endl;
	for (int k = 0; k < len; ++k)
	{
		std::cout << arr[k] << " ";
	}

	return 0;
}