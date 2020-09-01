#pragma once

typedef struct {
	int year, month;
}YearMonth;

typedef struct { int year, yDays; }YearDays;

class Date
{
private:
	int year, month, day;

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

	int (*days_in_month(int))[12];

	void ShowDate();
	bool is_leap_year();
	int YearDays();
	void DateFromYearDays(int, int);
	void DateAddDays(int);
};

// ���ڼ������ڵ����������������Ա������

YearMonth YearMonthAddMonth(YearMonth, int);
YearDays YearDaysAddDays(YearDays, int);
