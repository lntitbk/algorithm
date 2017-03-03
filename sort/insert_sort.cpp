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
	delete [] temp;
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

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition(int a[], int L, int R)
{
	int i, j , p;
	i = L; j = R + 1;
	p = a[L];

	while (i < j)
	{
		i++;
		while (a[i] < p)
		{
			i++;
			// cout << i << ",";
		}
		j--;
		while (a[j] > p)
		{
			j--;
			// cout << i << ",";
		}
		if (i < j) swap(a[i], a[j]);
		// cout << "doi cho" << a[i] << a[j] << "\n";
	}
	// swap(a[i], a[j]);
	swap(a[j], a[L]);
	return j;
}

void max_heapify(int a[], int i, int n)
{
	int max = i;
	int L = 2*i + 1;
	int R = 2*i + 2;

	if (L < n && a[L] > a[max])
	{
		max = L;

	}

	if ( R < n && a[R] > a[max])
	{
		max = R;
	}

	if ( max != i)
	{
		swap(a[i], a[max]);
		max_heapify(a, max, n);
	}
}

void build_heap(int a[], int n)
{
	for (int i = n/2 ; i >= 0; i--)
		max_heapify(a, i, n);
}

void sort_heap(int a[], int n)
{
	build_heap(a, n);
	for (int i = n; i >= 0; i--)
	{
		swap(a[0], a[i]);
		max_heapify(a, 0, i);
	}
}

void quicksort(int a[], int L, int R)
{
	int pivot;
	if ( L < R)
	{
		pivot = partition(a, L, R);
		if (L < pivot) quicksort(a, L, pivot -1);
		if (R > pivot) quicksort(a, pivot + 1, R);
	}
		
}

int main(int argc, char* argv[])
{
	int arr[] = {3, 5,4,1};
	int array_size = sizeof(arr)/sizeof(arr[0]);
	// quicksort(arr, 0, array_size - 1);
	// swap(arr[0], arr[1]);
	sort_heap(arr, array_size - 1);
	for (int i = 0; i < array_size; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}