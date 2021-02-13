#pragma once
#include<math.h>

/*
================================================================================
ð������
*/
template<typename T, unsigned num>
void bubble_sort(T (&arr)[num], bool is_ascending)
{
	int ii, jj;
	if (is_ascending) {
		for (ii = 0; ii < num; ii++)  // ��������
			for (jj = num - 1; jj >ii; jj--)  // ����Ƚϴ�С
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


/*
================================================================================
��������
*/
template<typename T, unsigned num>
void insertion_sort(T(&arr)[num], bool is_ascending)
{

	T key;
	int ii, jj;
	if (is_ascending) {  // ����
		for (jj = 1; jj < num; jj++) {
			key = arr[jj];
			// insert arr[jj] into the sorted sequence arr[0] ~ arr[j-1]
			ii = jj;  // ǰһλ��
			while (ii > 0 && arr[ii - 1] > key) {
				arr[ii] = arr[ii - 1];  // λ�ú���һλ
				ii -= 1;
			}
			arr[ii] = key;
		}
	}
	else {  // ����
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


/* 
================================================================================
��������
*/
template<typename T, unsigned num>
int partition(T (&arr)[num], int p, int r, bool is_ascending)
{
	int x, ii;
	x = arr[r];  // ��Ԫ
	ii = p;
	if (is_ascending) {  // ��������
		for (int jj = p; jj < r; jj++) {  // jj��ǵ�ǰѭ��λ��
			if (arr[jj] <= x) {  // Ѱ��С����Ԫ��ֵ
				swap(arr[ii], arr[jj]);  // ii��Ǵ����С����Ԫ��Ԫ�ص�λ��
				ii += 1;
			}
		}
	}
	else {
		for (int jj = p; jj < r; jj++) {
			if (arr[jj] >= x) {
				swap(arr[ii], arr[jj]);
				ii += 1;
			}
		}
	}
	
	swap(arr[ii], arr[r]);  // ����Ԫ����λ�ã������/�ұ߾�ΪС�ڵ���/���ڵ�������ֵ
	return ii;
}

template<typename T, unsigned num>
void quick_sort(T (&arr)[num], int p, int r, bool is_ascending)
{
	int q;
	if (p < r) {
		q = partition(arr, p, r, is_ascending);
		quick_sort(arr, p, q - 1, is_ascending);
		quick_sort(arr, q + 1, r, is_ascending);
	}
}


/*
================================================================================
�鲢����
*/
template<typename T, unsigned num>
void merge(T(&arr)[num], int p, int q, int r, bool is_ascending)
{
	int ii = 0, jj = 0, kk = 0;

	int n1 = q - p + 1; // �±귶Χ [p, q]
	int n2 = r - q;  // �±귶Χ (q, r]
	T *left = new T[n1];
	T *right = new T[n2];

	for (ii = 0; ii < n1; ii++)
		left[ii] = arr[p + ii];

	for (ii = 0; ii < n2; ii++)
		right[ii] = arr[q + ii + 1];

	ii = 0, jj = 0;
	if (is_ascending) {  // ��������
		for (kk = p; kk <= r; kk++) {
			if ((ii < n1) && (((jj < n2) && (left[ii] <= right[jj])) || (jj >= n2))) {
				arr[kk] = left[ii];
				ii++;
			}
			else if ((jj < n2) && (((ii < n1) && (right[jj] <= left[ii])) || (ii >= n1))) {
				arr[kk] = right[jj];
				jj++;
			}
		}
	}
	else {
		for (kk = p; kk <= r; kk++) {
			if ((ii < n1) && (((jj < n2) && (left[ii] >= right[jj])) || (jj >= n2))) {
				arr[kk] = left[ii];
				ii++;
			}
			else if ((jj < n2) && (((ii < n1) && (right[jj] >= left[ii])) || (ii >= n1))) {
				arr[kk] = right[jj];
				jj++;
			}
		}
	}
}

template<typename T, unsigned num>
void merge_sort(T(&arr)[num], int p, int r, bool is_ascending)
{
	if (p < r) {
		int q = floor((p + r) / 2);
		merge_sort(arr, p, q, is_ascending);
		merge_sort(arr, q + 1, r, is_ascending);
		merge(arr, p, q, r, is_ascending);
	}
}

/*
================================================================================
������
*/
int parent(int ii)
{
	return floor((ii - 1) / 2);
}

int left(int ii)
{
	return 2 * ii + 1;
}

int right(int ii)
{
	return 2 * (ii + 1);
}

template<typename T, unsigned num>
void max_heapify(T(&arr)[num], int ii, int heap_size)
{
	// ii, ��ǰ�ڵ��λ���±�
	// heap_size, ������ʵ�ʴ�ŵ�Ԫ������
	int ll, rr, largest;
	ll = left(ii), rr = right(ii);

	largest = ii;
	// ���ӽڵ���ڣ��Ҵ��ڸ��ڵ�
	if ((ll < heap_size) && (arr[ll] > arr[ii]))
		largest = ll;

	// ���ӽڵ���ڣ��Ҵ��ڸ��ڵ�����ӽڵ�
	if ((rr < heap_size) && (arr[rr] > arr[largest]))
		largest = rr;

	// ��ǰ���ڵ�С�����ӽڵ�����ӽڵ㣬���븸�ڵ��û�λ�õ��ӽڵ�������������������
	if (largest != ii) {
		swap(arr[ii], arr[largest]);
		max_heapify(arr, largest, heap_size);
	}
}

template<typename T, unsigned num>
void build_max_heap(T(&arr)[num], int heap_size)
{
	//int heap_size = num;
	int num_parents = floor(heap_size / 2);  // ����������Ԫ�ص�������������и��ڵ�ĸ���

	for (int ii = num_parents-1; ii >= 0; --ii)
		max_heapify(arr, ii, heap_size);
}

template<typename T, unsigned num>
void heap_sort(T(&arr)[num])
{
	int heap_size = num;  // ��ʼʱ������Ԫ�ظ��������������

	build_max_heap(arr, num);
	// heap_size-1 �������һ��Ԫ�ص�λ���±�
	for (int ii = heap_size - 1; ii > 0; ii--) {
		swap(arr[0], arr[heap_size - 1]);  // ���ڵ�arr[0] Ϊ���е����Ԫ��
		heap_size--;  // ������ЧԪ�� -1
		max_heapify(arr, 0, heap_size);
	}
}
