#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,max=0,cmax=0;
    cin >> n;
  
    for (int i = 1; i <= n; ++i) //числа в диапозоне
    {
        int count = 0;

        for (int j = 1; j <= sqrt(i); ++j) //делители
        {
           
            if (i % j == 0)
            {
                if (i != j)
                    count = count + 2;
                else 
                    count = count + 1;
               
            }
        }
       
        if (count >= cmax) 
        {
            cmax = count;
            max = i;
        }

    }
    cout << max << endl << cmax;
    return 0;
}
