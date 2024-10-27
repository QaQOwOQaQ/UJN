#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    if(hh < 12 || (hh == 12 && !mm))
        printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
    if(mm)  hh ++ ;
    for(int i = 0; i < hh - 12; i ++ )
        cout << "Dang";
    cout << endl;
    
    return 0;
}