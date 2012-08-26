/*
 * ZJU 1118 N-Credible Mazes
 * 00:00.01 852k
 * 2005.03.23 by adai
 */

#include <iostream>
using namespace std;

int maze = 0, n, num, total, isnew, ret;
int dir[100][2];
int used[100];

class tersection
{
public:
	int a[10];
	int flag;
	int num;
	tersection()
	{
		for (int i = 0; i < 10; ++i)
			a[i] = 0;
		flag = 0;
	}
	tersection &operator = (const tersection &cc){
		for (int i = 0; i < 10; ++i)
			a[i] = cc.a[i];
		flag = cc.flag;
		num = cc.num;
		return *this;
	}
    friend int operator==(const tersection& left, const tersection& right);
}tt[100], list[100];

int operator==(const tersection& left, const tersection& right)
{
	for (int i = 0; i < n; ++i)
	{
		if (left.a[i] != right.a[i])
			return 0;
	}
	return 1;
}

int bfs()
{
	int head = 0, tail = 0, nhead, ntail;

	tt[0].flag = 1;
	list[0] = tt[0];

	while (1)
	{
		if (tt[1].flag){
			ret = 1;
			break;
		}
		nhead = tail + 1;
		ntail = tail;
		for (int i = head; i <= tail; ++i)
		{
			int number = list[i].num;
			for (int j = 0; j < num; ++j)
			{				
				if (dir[j][0] != number)
					continue;
				if (used[j])
					continue;
				used[j] = 1;
				int cc = dir[j][1];
				if (tt[cc].flag)
					continue;
				tt[cc].flag = 1;
				list[++ntail] = tt[cc];
			}
		}
		if (ntail < nhead)
			break;
		for (int i = nhead; i <= ntail; ++i)
			list[i - nhead] = list[i];
		head = 0, tail = ntail - nhead;
	}
	return 0;
}

int main()
{
	tersection temp;
	while (cin >> n && n)
	{
		total = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp.a[i];
		}
		temp.num = total;
		tt[total++] = temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp.a[i];
		}
		temp.num = total;
		tt[total++] = temp;

		num = 0;
		while (cin >> temp.a[0] && temp.a[0] >= 0)
		{
			for (int i = 1; i < n; ++i)
				cin >> temp.a[i];
			isnew = 1;
			for (int i = 0; i < total; ++i)
			{
				if (tt[i] == temp)
				{
					dir[num][0] = i;
					isnew = 0;
				}
			}
			if (isnew)
			{
				temp.num = total;
				dir[num][0] = total;
				tt[total++] = temp;
			}

			isnew = 1;
			for (int i = 0; i < n; ++i)
				cin >> temp.a[i];
			for (int i = 0; i < total; ++i)
			{
				if (tt[i] == temp)
				{
					dir[num][1] = i;
					isnew = 0;
				}
			}
			if (isnew)
			{
				temp.num = total;
				dir[num][1] = total;
				tt[total++] = temp;
			}
			used[num++] = 0;
		}

		ret = 0;
		bfs();
		if (ret)
			cout << "Maze #" << ++maze << " can be travelled" << endl;
		else
			cout << "Maze #" << ++maze << " cannot be travelled" << endl;
	}
	return 0;
}
