#include<iostream>

#include"date_time.h"

using namespace std;


// ���캯��
Date::Date() :year(0), month(0), day(0) {}
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int (*(Date::days_in_month()))[12]
{
	static int tmp_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // һ����ÿ���µ�����
	int(*days)[12] = &tmp_days;
	if (is_leap_year()) {
		cout << endl << "-------------------" << endl << endl;
		(*days)[1] = 29;
	}
	else
	{
		(*days)[1] = 28;
	}
	cout << endl << year << " " << (*days)[1] << endl << endl;
	return days;
}

// ���������
Date Date::operator+ (Date date)
{
	Date sumDate;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // һ����ÿ���µ�����

	sumDate.year = year + date.year;
	sumDate.month = month + date.month;

	for (; sumDate.month > 12; sumDate.year++) sumDate.month -= 12;
	if (sumDate.is_leap_year()) monthDays[1] = 29;
	for (sumDate.day = day + date.day; sumDate.day > monthDays[sumDate.month - 1];)
	{
		for (sumDate.day -= monthDays[sumDate.month - 1], sumDate.month++; sumDate.month > 12;)
		{
			sumDate.month -= 12;
			sumDate.year++;
			if (sumDate.is_leap_year()) monthDays[1] = 29;
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


bool Date::is_leap_year()
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

int Date::days_of_year()
{
	// ���������
	int(*mdays)[12] = days_in_month();
	int tmp_days = 0;
	for (int ii = 0; ii < month - 1; ii++)
		tmp_days += (*mdays)[ii];
	
	tmp_days += day;
	return tmp_days;
}


void Date::add_month(int m)
{
	int tmp_year = 0;
	month += m;
	tmp_year = month / 12;
	month %= 12;
	year += tmp_year;
}


void Date::add_day(int d)
{
	int(*mdays)[12] = days_in_month();
	for (day += d; day > (*mdays)[month - 1];) {
		day -= (*mdays)[month - 1];
		month++;
		if (month > 12) {
			month -= 12;
			year++;
			mdays = days_in_month();
		}
	}
}


void Date::show_date()  // �������
{
	cout << year << "-" << month << "-" << day;
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
	if (is_leap_year()) monthDays[1] = 29;  //�������꣬2����29��

	for (month = 1; day > monthDays[month - 1]; )
	{
		day -= monthDays[month - 1];
		month++;
		if (month>12)
		{
			month -= 12, year++;
			if (is_leap_year()) monthDays[1] = 29;
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


/*
class Time =====================================================================
*/
Time::Time(int h=0, int m=0, int sec=0): hour(h), minute(m), second(sec) {}

void Time::show_time()
{
	cout << hour << ":" << minute << ":" << second;
}

void Time::add_hour(int h)
{
	hour += h;
	hour %= 24;
}

void Time::add_minute(int m)
{
	minute += m;
	int tmp_h = minute / 60;
	minute %= 60;
	add_hour(tmp_h);
}

void Time::add_second(int s)
{
	second += s;
	second %= 60;
	int tmp_minute = second / 60;
	add_minute(tmp_minute);
}

/*
DateTime =======================================================================
*/
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second): Date(year, month, day), Time(hour, minute, second) {}

void DateTime::show_date_time()
{
	show_date();
	cout << " ";
	show_time();
}
