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

void merge(int* a, int low, int high, int mid)
{
	int MAX_SIZE = high - low + 1;
	int* temp = new int[MAX_SIZE];
	int i = low, j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high)
	{
		if (a[i] > a[j])
		{
			temp[k] = a[j];
			j++;
		} 
		else
		{
			temp[k] = a[i];
			i++;
		}
		k++;
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		i++;
		k++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		j++;
		k++;
	}

	for (int h = 0; h < MAX_SIZE; h++)
	{
		a[low + h] = temp[h];
	}

}

void merge_sort(int* a, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a,low,high,mid);	
	}
}

int main(int argc, char* argv[])
{
	int arr[] = {1, 2, 4, 3};
	int array_size = sizeof(arr)/sizeof(arr[0]);
	merge_sort(arr, 0, array_size - 1);
	for (int i = 0; i < array_size; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}