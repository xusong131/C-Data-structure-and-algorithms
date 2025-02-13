#if 0
#include<iostream>

int binary_search(int val, int len, int arr[])
{
	int first = 0;
	int last = len - 1;
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (arr[mid] == val)
		{
			std::cout << "已找到，其下标为" << mid << std::endl;
			return mid;
		}
		else if (arr[mid] > val)
		{
			last = mid - 1;
			continue;
		}
		else
		{
			first = mid + 1;
			continue;
		}
	}
	std::cout << "数组中无此元素!" << std::endl;
	return -1;
}

int main()
{
	const int len = 11;
	int arr[len] = { 12,25,34,39,45,57,63,78,82,96,100 };
	std::cout << binary_search(96, len, arr);
	std::cout << binary_search(26, len, arr);
	std::cout << binary_search(100, len, arr);
	//_sleep(10);
	return 0;
}
#endif