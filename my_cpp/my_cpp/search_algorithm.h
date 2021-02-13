#pragma once

template<typename T, int M>
int BinarySearch(T(&arr)[M], T dst_val, bool is_ascend=true)
{
	/*
	arr: array���Ѿ��ź���
	dst_val: Ŀ��ֵ
	is_ascend�� bool��true for ascending�� false for descending
	*/
	int low = 0, high = M - 1;
	int mid;

	if (is_ascend) { // ��������
		while (low <= high) {
			mid = (low + high) / 2;
			if (dst_val == arr[mid]) return mid;
			else if (dst_val < arr[mid]) high = mid - 1;
			else low = mid + 1;
		}
	}else { // �ݼ�����
		while (low <= high) {
			mid = (low + high) / 2;
			if (dst_val == arr[mid]) return mid;
			else if (arr[mid] > dst_val) low = mid + 1;
			else high = mid - 1;
		}
	}
	return -1;
}