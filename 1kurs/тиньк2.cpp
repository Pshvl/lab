#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vec[i] = x;
	}
	cout <<endl;
	for (int i = 0; i < n-1; i++)
	{
		if (vec[i] < vec[i + 1])
			vec[i + 1] = vec[i];
	}

	for (int i = 0; i < n; i++)
		cout << vec[i]<<" ";

	return 0;
}

