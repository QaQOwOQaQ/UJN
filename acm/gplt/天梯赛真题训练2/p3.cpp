#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a, b, ain, bin;

int main()
{
    cin >> a >> b >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        int sum = x1 + y1;
        if(x2 == y2)    continue;
        else if(x2 == sum)  a -- , ain ++ ;
        else if(y2 == sum)  b -- , bin ++ ;
        if(a < 0 || b < 0)    
        {
            if(a < 0)  cout << 'A' << endl << bin << endl;
            else    cout << 'B' << endl << ain << endl;
            break;
        }
    }
    return 0;
}