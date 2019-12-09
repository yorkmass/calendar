#include <iostream>
using namespace std;
int main()
{
	char p[12][4] = { "鼠","牛","虎","兔","龙","蛇","马","羊","鸡","猴","狗","猪" };
	int year0 = 2008;   //2008年是鼠年，作为基准
	int year, n;
	cout << "请输入一个年份";
	cin >> year;
	n = year - year0;
	n = n % 12;
	if (n < 0)
		n += 12;   //求余时，n可能是负数，如果是负数则加12 
	cout << year << "年的人属相为:" << p[n];
	return 0;
}