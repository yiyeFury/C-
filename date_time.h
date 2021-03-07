#pragma once

typedef struct {
	int year, month;
}YearMonth;

typedef struct { int year, yDays; }YearDays;

class Date
{
private:
	

public:
	// ���캯��
	Date();
	Date(int, int, int);
	// ���������
	Date operator+ (Date);

	int year, month, day;

	// ��Ա����
	void GetYear(int);  // �����ݳ�Ա��ֵ
	void GetMonth(int);
	void GetDay(int);

	int GetYear();  // �õ����ݳ�Ա��ֵ
	int GetMonth();
	int GetDay();

	int (*days_in_month())[12];

	void show_date();
	bool is_leap_year();
	int days_of_year();
	void add_month(int);
	void add_day(int);

	int YearDays();
	void DateFromYearDays(int, int);
	void DateAddDays(int);
};

// ���ڼ������ڵ����������������Ա������

YearMonth YearMonthAddMonth(YearMonth, int);
YearDays YearDaysAddDays(YearDays, int);

class Time
{
private:
	
public:
	Time(int, int, int);

	int hour, minute, second;

	void show_time();
	void add_hour(int);
	void add_minute(int);
	void add_second(int);
};

class DateTime : public Date, public Time
{
private:
public:
	DateTime(int, int, int, int, int, int);

	void show_date_time();
	void add_hour(int);
	void add_minute(int);
	void add_second(int);
};