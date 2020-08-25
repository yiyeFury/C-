#pragma once


/*
============================================================================
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
