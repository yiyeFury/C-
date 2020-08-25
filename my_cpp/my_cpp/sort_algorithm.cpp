#include<iostream>

using namespace std;

/*
================================================================================
��������
*/
int partition(int *arr, int p, int r)
{
	int x, ii;
	x = arr[r], ii = p - 1;
	for (int jj = p; jj < r; jj++) {
		if (arr[jj] <= x) {
			ii += 1;
			swap(arr[ii], arr[jj]);
		}
	}
	swap(arr[ii + 1], arr[r]);
	return ii + 1;
}

void quick_sort(int *arr, int p, int r)
{
	int q;
	if (p < r) {
		q = partition(arr, p, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q + 1, r);
	}
}



