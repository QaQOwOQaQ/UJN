#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int main()
{
    for(long long i = 1; i <= 4000; i += 5)
    {
        long long x = i;
        if(x % 5 == 1)
        {
            x -= 1;
            x = x / 5 * 4;
            if(x % 5 == 2)
            {
                x -= 2;
                x = x / 5 * 4;
                if(x % 5 == 3)
                {
                    x -= 3;
                    x = x / 5 * 4;
                    if(x % 5 == 4)
                    {
                        x -= 4;
                        x = x / 5 * 4;
                        if(x % 5 == 0 && x)
                        {
                            cout << i << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}