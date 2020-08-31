#pragma once

typedef struct {
	int year, month;
}YearMonth;

typedef struct { int year, yDays; }YearDays;

class Date
{
public:
	// ���캯��
	Date();
	Date(int, int, int);
	// ���������
	Date operator+ (Date);

	// ��Ա����
	void GetYear(int);  // �����ݳ�Ա��ֵ
	void GetMonth(int);
	void GetDay(int);

	int GetYear();  // �õ����ݳ�Ա��ֵ
	int GetMonth();
	int GetDay();

	void ShowDate();
	int IsLeapYear();
	int YearDays();
	void DateFromYearDays(int, int);
	void DateAddDays(int);

private:
	int year, month, day;
};

// ���ڼ������ڵ����������������Ա������

YearMonth YearMonthAddMonth(YearMonth, int);
YearDays YearDaysAddDays(YearDays, int);
