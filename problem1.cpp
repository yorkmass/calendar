#include <iostream>
using namespace std;
int main()
{
	int year, month, day, num;
	bool runnian;	//�Ƿ�Ϊ�����־λ
	cout << "������һ����ݣ�";
	cin >> year;
	cout << "�������·ݣ�";
	cin >> month;
	cout << "���������ڣ�";
	cin >> day;
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
			runnian = true;
		else
			runnian = false;
	}
	else
	{
		if (year % 4 == 0)
		{
			runnian = true;
		}
		else
			runnian = false;
	}

	switch (month)
	{
	case 1:  num = day; break;
	case 2:	 num = 31 + day; break;
	case 3:	 num = 59 + day; break;
	case 4:  num = 90 + day; break;
	case 5:  num = 120 + day; break;
	case 6:  num = 151 + day; break;
	case 7:  num = 182 + day; break;
	case 8:  num = 212 + day; break;
	case 9:  num = 243 + day; break;
	case 10: num = 274 + day; break;
	case 11: num = 304 + day; break;
	case 12: num = 335 + day; break;
	default: break;
	}

	if (month >= 3)
	{
		if (runnian == true)
			num++;
	}
	cout << "������һ��ĵ�" << num << "��";
	return 0;
}