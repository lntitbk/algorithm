#include <iostream>

using namespace std;

void insertion_sort(int* a, int array_size)
{
	for(int i = 0; i < array_size; i++)
	{
		int j = i;
		int last = a[i];
		while(j > 0 && a[j -1] > last)
		{
			a[j] = a[j-1];
			a[j-1] = last;
			j--;
		}
	}
}

void selection_sort(int* a, int array_size)
{
	for(int i= 0; i < array_size - 1; i++)
	{
		int min = i;
		for(int j = i; j < array_size; j++)
		{
			if (a[min] > a[j])
			{
				int temp = a[min];
				a[min] = a[j];
				a[j] = temp;
			}
		} 
	}
}

void merge_sort(int* a, int array_size)
{

}

int main(int argc, char* argv[])
{
	int arr[] = {1, 2, 4, 3};
	int length = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr, length);
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}