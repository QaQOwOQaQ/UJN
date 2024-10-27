//行尾不能输出多余空格
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int main()
{
    cin >> n;
    while(n -- )
    {
        int sex;
        double m, kg;
        bool f1 = false, f2 = false;
        cin >> sex >> m >> kg;
        if(sex == 1)
        {
            if(m < 130) cout << "duo chi yu! ";
            else if(m > 130)    cout << "ni li hai! ";
            else cout << "wan mei! ";
            if(kg < 27) cout << "duo chi rou!";
            else if(kg > 27)    cout << "shao chi rou!";
            else cout << "wan mei!";
        }
        else
        {
            if(m < 129) cout << "duo chi yu! ";
            else if(m > 129)    cout << "ni li hai! ";
            else cout << "wan mei! ";
            if(kg < 25) cout << "duo chi rou!";
            else if(kg > 25)    cout << "shao chi rou!";
            else cout << "wan mei!";
        }
        cout << endl;
    }
    
    
    return 0;
}