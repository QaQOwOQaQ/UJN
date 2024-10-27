#include <iostream>
using namespace std;

double s, step = 2;

int main()
{
    cin >> s;
    for(int i = 1; ; i ++ )
    {
        s -= step;
        if(s <= 0)  
        {
            cout << i << endl;
            break;
        }
        step *= 0.98;
    }
    return 0;
}