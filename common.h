#pragma once
#include<iostream>
#include<iomanip>


using namespace std;

/* -----------------------------------------------------------------------------
打印数组
*/

template<typename T, int M>
void PrintArray(const T(&arr)[M])
{
    // 打印 1d 数组
    cout << __func__ << endl;
    for (int ii = 0; ii < M; ii++)
        cout << setw(10) << arr[ii];
    cout << endl << endl;
}


template<typename T, int M, int N>
void PrintArray(const T(&arr)[M][N])
{
    // 打印 2d 数组
    cout << __func__ << endl;
    for (int ii = 0; ii < M; ii++) {
        for (int jj = 0; jj < N; jj++)
            cout << setw(10) << arr[ii][jj];
        cout << endl;
    }
    cout << endl;
}


