#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int idx[11], arr[11], k;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    string s;   cin >> s;
    set<int> S;
    for(int i = 0; i < 11; i ++ )   S.insert(s[i] -'0');
    for(auto x : S) arr[k ++ ] = x;
    sort(arr, arr + k, cmp);
    for(int i = 0; i < 11; i ++ )
    {
        for(int j = 0; j < k; j ++ )
        {
            if(s[i] - '0' == arr[j])
            {
                idx[i] = j;
                break;
            }
        }
    }
    
    cout << "int[] arr = new int[]{";
    for(int i = 0; i < k; i ++ ) 
    {
        cout << arr[i];
        if(i != k - 1)  cout << ',';
        else    cout << "};" << endl;
    }
    cout << "int[] index = new int[]{";
    for(int i = 0; i < 11; i ++ ) 
    {
        cout << idx[i];
        if(i != 10)  cout << ',';
        else    cout << "};" << endl;
    }
  
    return 0;
}