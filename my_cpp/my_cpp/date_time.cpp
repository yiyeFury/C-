#include<iostream>

#include"date_time.h"

using namespace std;

// ���캯��
Date::Date() :year(0), month(0), day(0) {}
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

// ���������
Date Date::operator+ (Date date)
{
	Date sumDate;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // һ����ÿ���µ�����

	sumDate.year = year + date.year;
	sumDate.month = month + date.month;

	for (; sumDate.month > 12; sumDate.year++) sumDate.month -= 12;
	if (sumDate.IsLeapYear()) monthDays[1] = 29;
	for (sumDate.day = day + date.day; sumDate.day > monthDays[sumDate.month - 1];)
	{
		for (sumDate.day -= monthDays[sumDate.month - 1], sumDate.month++; sumDate.month > 12;)
		{
			sumDate.month -= 12;
			sumDate.year++;
			if (sumDate.IsLeapYear()) monthDays[1] = 29;
			else monthDays[1] = 28;
		}

	}
	return sumDate;
}

// ����������ݳ�Ա�ĸ�ֵ
void Date::GetYear(int y)
{
	year = y;
}
void Date::GetMonth(int m)
{
	month = m;
}
void Date::GetDay(int d)
{
	day = d;
}

// ��ȡ��������ݳ�Ա��ֵ
int Date::GetYear() { return year; }
int Date::GetMonth() { return month; }
int Date::GetDay() { return day; }

int Date::IsLeapYear()  // �ж��Ƿ�Ϊ���꣬���򷵻�1�����򷵻�0
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return 1;
	else return 0;
}

bool leap_year(int year)
{
	// �����Ƿ�Ϊ����
	bool cond1, cond2;
	cond1 = (year % 4 == 0) && (year % 100 != 0);
	cond2 = year % 400 == 0;

	if (cond1 || cond2) 
		return true;
	else 
		return false;
}


void Date::ShowDate()  // �������
{
	cout << year << " �� " << month << " �� " << day << "��" << endl;
}

int Date::YearDays()  // ���������
{
	int yearDays = 0;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // һ����ÿ���µ�����
	if (IsLeapYear()) monthDays[1] = 29;  //�������꣬2����29��
	for (int i = 0; i < month - 1; i++) {
		yearDays += monthDays[i];
	}

	yearDays += day;
	return(yearDays);
}

void Date::DateAddDays(int days)  // ��ǰ���ڼ���������������µ�����
{
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // һ����ÿ���µ�����
	if (IsLeapYear()) monthDays[1] = 29;  //�������꣬2����29��

	for (day = day + days; day > monthDays[month - 1];)
	{
		day -= monthDays[month - 1];
		month++;
		if (month > 12)
		{
			month -= 12, year++;
			if (IsLeapYear()) monthDays[1] = 29;
			else monthDays[1] = 28;
		}
	}
}

YearMonth AddMonth(YearMonth yearMonth, int m)
{
	yearMonth.month += m;
	if (yearMonth.month > 12) {
		yearMonth.month -= 12;
		yearMonth.year++;
	}
	return(yearMonth);
}

void Date::DateFromYearDays(int baseYear, int yearDays)  // �����������գ���������
{
	year = baseYear;
	day = yearDays;

	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // һ����ÿ���µ�����
	if (IsLeapYear()) monthDays[1] = 29;  //�������꣬2����29��

	for (month = 1; day > monthDays[month - 1]; )
	{
		day -= monthDays[month - 1];
		month++;
		if (month>12)
		{
			month -= 12, year++;
			if (IsLeapYear()) monthDays[1] = 29;
			else monthDays[1] = 28;
		}
	}
}

YearMonth YearMonthAddMonth(YearMonth yearMonth, int numMonth)
{
	yearMonth.month += numMonth;
	if (yearMonth.month > 12)
	{
		yearMonth.month -= 12; yearMonth.year++;
	}
	return yearMonth;
}

YearDays YearDaysAddDays(YearDays yearDays, int days)
{
	int sumDaysOfYear = 0;
	if ((yearDays.year % 4 == 0 && yearDays.yDays % 400 != 0) | yearDays.year % 400 == 0) sumDaysOfYear = 366;
	else sumDaysOfYear = 365;

	yearDays.yDays += days;
	while (yearDays.yDays > sumDaysOfYear)
	{
		yearDays.yDays -= sumDaysOfYear;
		yearDays.year++;
		if ((yearDays.year % 4 == 0 && yearDays.yDays % 400 != 0) | yearDays.year % 400 == 0) sumDaysOfYear = 366;
		else sumDaysOfYear = 365;
	}
	return yearDays;
}