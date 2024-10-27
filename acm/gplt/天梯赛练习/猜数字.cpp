#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 10010;

int n;
string name[N];
double w[N];

int main()
{
    cin >> n;
    double sum = 0, ave = 0;
    for(int i = 0; i < n; i ++ )    cin >> name[i] >> w[i], sum += w[i];
    ave = sum / n / 2;
    // cout << sum << " " << ave << endl;
    int pos = -1, res = 0;
    double d = 0;
    for(int i = 0; i < n ; i ++ )
    {
        if(pos == -1)   
        {
            pos = i;
            d = fabs(w[i] - ave);
        }
        else
        {
            double t = fabs(w[i] - ave);
            if(t < d)
            {
                pos = i;
                d = t;
            }
        }
    }
    
    cout << (int)ave << " " << name[pos] << endl;
    return 0;
}