# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <algorithm>
# include <iostream>

using namespace std;

const int MAX_N = 6e5;
const int MAX_L = 6e3;

const int BASE = 31;

int n, q, m;
char s[MAX_N];
char t[MAX_L];

unsigned long long hsh1;
unsigned long long hsh2;

unsigned long long pp[MAX_L];

int main ()
{
	//freopen ("clown.in", "r", stdin);
	//freopen ("clown.out", "w", stdout);
	int i, j, cnt;

	pp[0] = 1;
	for (i = 1; i < MAX_L; i ++)
		pp[i] = pp[i - 1] * BASE;//printf("for pow %d = %llu\n", i, pp[i]);

	scanf ("%s", s);
	n = strlen (s);
	scanf ("%d", &q);

	for (j = 0; j < q; j ++)
	{
		hsh1 = hsh2 = 0;
		cnt = 0;
		scanf ("%s", t);
		m = strlen (t);

		for (i = 0; i < m; i ++)
		{
			hsh1 = hsh1 * BASE + int (t[i] - 'a' + 1);
			hsh2 = hsh2 * BASE + int (s[i] - 'a' + 1);
		}
		if (hsh1 == hsh2)
			cnt ++;

		for (i = m; i < n; i ++)
		{
			hsh2 -= pp[m - 1] * int (s[i - m] - 'a' + 1);
			hsh2 *= BASE;
			hsh2 += int (s[i] - 'a' + 1);
			if (hsh2 == hsh1)
				cnt ++;
		}
		printf ("%d\n", cnt);
	}
	return 0;
}

