#include <iostream>
using namespace std;
int year, month, day, he;
int run[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int ping[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//这点到基本点的求和
//判断闰年和平年
int leap(int year)
{
	int four, hundred, fourhundred;
	four = year % 4;
	hundred = year % 100;
	fourhundred = year % 400;
	if (four == 0 && hundred == 0 && fourhundred == 0)
		return 1;
	else if (four == 0 && hundred != 0 && fourhundred != 0)
		return 1;
	else return 0;
}
int qiuhe(int year, int month, int day, int run[], int ping[])
{
	//19000101 星期一
	int i, sum = 0;
	for (i = 1900; i < year; i++)
	{
		int m;//用来标签是闰年还是平年  m==1,就是闰年
		m = leap(i);
		if (m == 1)
		{
			sum = sum + 366;
		}
		else
		{
			sum = sum + 365;
		}
	}
	//加月份的天数
	for (i = 0; i < month - 1; i++)
	{
		if (leap(year) == 1)
			sum = sum + run[i];
		else
			sum = sum + ping[i];
	}
	return sum;
}


void muban()
{
	char weekday[7][10] = { "星期一\t","星期二\t","星期三\t","星期四\t","星期五\t","星期六\t","星期天" };
	int i;
	for (i = 0; i < 7; i++)
		cout << weekday[i];
	cout << endl;
}

void shibiePrint(int sum, int year, int month)
{
	int yushu, temp, i;
	yushu = sum % 7;//得到多余的天数，然后在后一个月份用空格表示出来
	for (i = 0; i < yushu; i++)
		cout << "\t";//输出空格
	temp = 7 - yushu;
	if (leap(year) == 1)
	{
		for (i = 1; i <= run[month - 1]; i++)//打印31天
		{
			cout << i<< "\t";
			if (i == temp || (i - temp) % 7 == 0)
				cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (i = 1; i <= ping[month - 1]; i++)//打印30天
		{
			cout << i << "\t";
			if (i == temp || (i - temp) % 7 == 0)
				cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	cout << "请输入一个年份";
	cin >> year;
	cout << "请输入月份";
	cin >> month;
	cout << "请输入日期";
	cin >> day;
	he = qiuhe(year, month, day, run, ping);//调用函数求和
	cout << "\t\t\t"<< year<<"年"<<month<<"月\n\n";
	muban();//调用模板函数，输出模板
	shibiePrint(he, year, month);//进行相应的识别，并输出
	return 0;
}