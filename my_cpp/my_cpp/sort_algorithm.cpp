#include<iostream>
#include"common.h"

using namespace std;

void bubble_sort(int *arr, int num, bool is_ascending)
{
	int ii, jj;
	if (is_ascending) {
		for (ii = 0; ii < num; ii++)
			for (jj = num - 1; jj >ii; jj--)
				if (arr[jj] < arr[jj - 1])  // С����λ��
					swap(arr[jj], arr[jj - 1]);
	}
	else {
		for (ii = 0; ii < num; ii++)
			for (jj = num - 1; jj >ii; jj--)
				if (arr[jj] > arr[jj - 1])  // ������λ��
					swap(arr[jj], arr[jj - 1]);
	}
		

}


void insertion_sort(int *arr, int num, bool is_ascending)
{
	// ��������
	int key, ii, jj;
	if (is_ascending) {  // ����
		for (jj = 1; jj < num; jj++) {
			key = arr[jj];
			// insert arr[jj] into the sorted sequence arr[0] ~ arr[j-1]
			ii = jj - 1; 
			while (ii >= 0 && arr[ii] > key) {
				arr[ii + 1] = arr[ii];  // λ�ú���һλ
				ii -= 1;
			}
			arr[ii + 1] = key;
		}
	}else {
		for (jj = 1; jj < num; jj++) {
			key = arr[jj];
			// insert arr[jj] into the sorted sequence arr[0] ~ arr[j-1]
			ii = jj - 1;
			while (ii >= 0 && arr[ii] < key) {
				arr[ii + 1] = arr[ii];
				ii -= 1;
			}
			arr[ii + 1] = key;
		}
	}
	

}


// �������� *********************************************************************
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

void main()
{
	const int num = 4;
	int arr[num] = {4, 1, 2, 3};
	quick_sort(arr, 0, 3);
	print_array(arr, num);
	print_array(arr, num);
	cout << endl;
	system("pause");
}
