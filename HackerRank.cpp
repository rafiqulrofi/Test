#include<iostream>
#include<set>
using namespace std;

int a[100000];
set<int> m;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int sat = a[0];
	m.insert(sat);
	for (int i = 1; i < n; i++)
	{
		sat += a[i];
		m.insert(sat);
	}

	for (set<int>::iterator it = m.begin(); it != m.end();++it)
	{
		if (sat % (*it) == 0)
		{
			bool flag = true;
			for (int j = 1; j <= sat / (*it); j++)
			{
				set<int>::iterator tt = m.find((*it) * j);
				if (tt == m.end())
				{
					flag = false;
					break;
				}
			}
			if (flag)
				cout << *it << " ";
		}
	}
	return 0;
}
