#pragma once
#include<iostream>
using namespace std;

/* -----------------------------------------------------------------------------
��ӡ����
*/
template<typename T, unsigned num>
void print_array(T(&p)[num])
{
	for (int ii = 0; ii < num; ii++)
		cout << ' ' << p[ii];
	cout << endl << endl;
}
