// GPA计算.cpp

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
double xuefen[200], chengji[200], sumc, sumx, gpa;
void duqu(int q);
void file(int q);
void show();

int main()
{
	int p, q, t = 0;

	cout << "上海交通大学GPA计算" << endl;
	cout << "作者：陈桢（上海交通大学2012级IEEE试点班）" << endl;
	cout << "由于科目繁多，人工计算费时费力，特为上海交大学生量身定做该软件。" << endl;
	cout << "版权所有2013" << endl;
	do
	{
		cout << endl;
		sumc = sumx = 0;
		do
		{
			cout << "0.手动输入成绩，1.读取txt文件，请选择：";
			cin >> p;
		}
		while (p != 0 && p != 1);
		do
		{
			cout << "0.计算GPA，1.计算加权平均成绩，请选择：";
			cin >> q;
		}
		while (q != 0 && q != 1);
		if (p == 0)
		{
			cout << "\n每行输入“学分”空格“成绩”，不能有中文，可输入等第（不区分大小写），学分为“0”的数据无需输入，输入“0”代表结束输入。\n" << endl;
			duqu(q);
		}
		else
		{
			if (t == 0) show();
			file(q);
		}
		if (sumx != 0) gpa = sumc / sumx;
		else gpa = 0;
		cout << (q == 0 ? "\n您的GPA为：" : "\n您的平均成绩为：") << gpa << endl;
		do
		{
			cout << "0.退出，1.继续计算：";
			cin >> t;
		}
		while (t !=0 && t != 1);
	}
	while (t == 1);

	return 0;
}

void duqu(int q)
{
	int i = 0;
	char c[10];

	while (true)
	{
		bool flag = false;
		cin >> xuefen[i];
		if (xuefen[i] == 0)
			break;
		else
		{
			cin >> c;
			if (c[0] <= '9' && c[0] >= '0') chengji[i] = atof(c);
			else if (q == 0)
			{
				c[0] = toupper(c[0]);
				if (strcmp(c, "A+") == 0) chengji[i] = 95;
				else if (strcmp(c, "A") == 0) chengji[i] = 90;
				else if (strcmp(c, "A-") == 0) chengji[i] = 85;
				else if (strcmp(c, "B+") == 0) chengji[i] = 80;
				else if (strcmp(c, "B") == 0) chengji[i] = 75;
				else if (strcmp(c, "B-") == 0) chengji[i] = 70;
				else if (strcmp(c, "C+") == 0) chengji[i] = 67;
				else if (strcmp(c, "C") == 0) chengji[i] = 65;
				else if (strcmp(c, "C-") == 0) chengji[i] = 62;
				else if (strcmp(c, "D") == 0) chengji[i] = 60;
				else if (strcmp(c, "P") == 0 || strcmp(c, "F") == 0) continue;
				else flag = true;
			}
			else continue;
		}
		if (flag || xuefen[i] < 0 || chengji[i] > 100)
		{
			cout << "输入错误，上组数据请检查后重新输入。" << endl;
			continue;
		}
		sumx += xuefen[i];
		if (q == 0)
		{
			if (chengji[i] < 60) continue;
			else if (chengji[i] >= 70)
			{
				switch ((int)chengji[i] / 5)
				{
				case 14 : sumc += 2.7 * xuefen[i]; break;
				case 15 : sumc += 3.0 * xuefen[i]; break;
				case 16 : sumc += 3.3 * xuefen[i]; break;
				case 17 : sumc += 3.7 * xuefen[i]; break;
				case 18 : sumc += 4.0 * xuefen[i]; break;
				default : sumc += 4.3 * xuefen[i];
				}
			}
			else if (chengji[i] <= 69 && chengji[i] >= 67) sumc += 2.3 * xuefen[i];
			else if (chengji[i] <= 67 && chengji[i] >= 65) sumc += 2.0 * xuefen[i];
			else if (chengji[i] <= 65 && chengji[i] >= 62) sumc += 1.7 * xuefen[i];
			else if (chengji[i] <= 62 && chengji[i] >= 60) sumc += 1.0 * xuefen[i];
		}
		else sumc += chengji[i] * xuefen[i];
		i++;
	}
}

void file(int q)
{
	string s;
	ifstream fin;
	char c[10], a[10];
	double x, y;

	do
	{
		cout << "请输入文件路径（不能有中文，例如：E:\\gpa.txt）：";
		cin >> s;
		fin.open(s);
	}
	while (!fin.is_open());

	while (fin >> a)
	{
		x = atof(a);
		bool flag = false;
		fin >> c;
		if (c[0] <= '9' && c[0] >= '0') y = atof(c);
		else if (q == 0)
		{
			c[0] = toupper(c[0]);
			if (strcmp(c, "A+") == 0) y = 95;
			else if (strcmp(c, "A") == 0) y = 90;
			else if (strcmp(c, "A-") == 0) y = 85;
			else if (strcmp(c, "B+") == 0) y = 80;
			else if (strcmp(c, "B") == 0) y = 75;
			else if (strcmp(c, "B-") == 0) y = 70;
			else if (strcmp(c, "C+") == 0) y = 67;
			else if (strcmp(c, "C") == 0) y = 65;
			else if (strcmp(c, "C-") == 0) y = 62;
			else if (strcmp(c, "D") == 0) y = 60;
			else if (strcmp(c, "P") == 0 || strcmp(c, "F") == 0) continue;
			else flag = true;
		}
		else continue;
		if (flag || x < 0 || y > 100) continue;
		sumx += x;
		if (q == 0)
		{
			if (y < 60) continue;
			else if (y >= 70)
			{
				switch ((int)y / 5)
				{
				case 14 : sumc += 2.7 * x; break;
				case 15 : sumc += 3.0 * x; break;
				case 16 : sumc += 3.3 * x; break;
				case 17 : sumc += 3.7 * x; break;
				case 18 : sumc += 4.0 * x; break;
				default : sumc += 4.3 * x;
				}
			}
			else if (y <= 69 && y >= 67) sumc += 2.3 * x;
			else if (y <= 67 && y >= 65) sumc += 2.0 * x;
			else if (y <= 64 && y >= 62) sumc += 1.7 * x;
			else if (y <= 62 && y >= 60) sumc += 1.0 * x;
		}
		else sumc += y * x;
	}
	fin.close();
}

void show()
{
	cout << endl;
	cout << "制作文本文件步骤：" << endl;
	cout << "1、打开成绩查询页面，将每个学期的成绩单表格全部选中（不包括标题栏），依次复制到Excel中。" << endl;
	cout << "2、删除除了“学分”和“成绩”之外的所有列，只留下两个干净的纯数字列，左边为学分，右边为成绩。" << endl;
	cout << "3、另存为txt格式，建议保存在某个盘的根目录下，因为待会儿需要输入他的地址，文件名不能有中文。\n" << endl;
}