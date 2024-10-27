#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void out(int x)
{
    for(int i = 0; i < x; i ++ )    cout << "Dang";
    cout << endl;
}

int main()
{
    int hh, mm;
    bool has_dang = true;
    scanf("%d:%d", &hh, &mm);
    if(hh >= 0 && hh <= 11) has_dang = false;
    if(hh == 12 && mm == 0) has_dang = false;
    if(!has_dang)   printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
    else
    {
        int x = hh - 12;
        if(mm != 0) x ++ ; 
        out(x);
    }
    
    
    return 0;
}