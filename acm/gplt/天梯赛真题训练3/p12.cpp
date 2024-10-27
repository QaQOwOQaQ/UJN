#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n, k;
char sex;
int id, fid, mid;
struct people{
    char sex;
    int fid, mid;   //father_id;mother_id
    people() : sex('M'), fid(-1), mid(-1) {}
    people(char ch, int a, int b) : sex(ch), fid(a), mid(b) {}
    //有无参的构造函数就必须有有参的构造函数
}family[N];

bool check(int a, int b, int cnt)
{
    if(a == -1 || b == -1)  return true;
    if((family[a].fid != -1 && family[a].fid == family[b].fid) 
    || (family[a].mid != -1 && family[a].mid == family[b].mid))
        return false;
    cnt ++ ;
    if(cnt >= 5) return true;
    
    return (check(family[a].fid, family[b].fid, cnt) 
        && check(family[a].fid, family[b].mid, cnt) 
        && check(family[a].mid, family[b].fid, cnt) 
        && check(family[a].mid, family[b].mid, cnt));
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> id >> sex >> fid >> mid;
        family[id] = {sex, fid, mid};
        //必须设置他的父母的id
        if(family[id].fid != -1)   family[family[id].fid].sex = 'M';
        if(family[id].mid != -1)   family[family[id].mid].sex = 'F';
    }
    
    cin >> k;
    while(k -- )
    {
        int a, b;
        cin >> a >> b;
        if(family[a].sex == family[b].sex)  puts("Never Mind");
        else
        {
            bool flag = check(a, b, 1);
            cout << (flag ? "Yes" : "No") << endl;
        }
    }
    
    return 0;
}