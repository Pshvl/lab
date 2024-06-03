#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int fact(int x)
{
	int factorial = 1;

	int i = 1;
	while (i <= x) 
	{
		factorial *= i;
		i++;
	}
	return factorial;
}

int main()
{
	int n, s = 0, count;
	cin >> n;
	s = 2 * n;
	if (s % 3 == 0)
		count = fact(s / 3);
	else
		count = 0;
	cout << count;
	return 0;
}

