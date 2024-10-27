#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void out(int x)
{
    for(int i = 0; i < x; i ++ )
        cout << "Dang";
}

int main()
{
    int h, m;
    scanf("%d:%d", &h, &m);
    
    if(h < 12 || (h == 12 && m == 0))
        printf("Only %02d:%02d.  Too early to Dang.", h, m);
    else
    {
        if(m)   h ++ ;
        out(h - 12);
    }
    
    return 0;
}