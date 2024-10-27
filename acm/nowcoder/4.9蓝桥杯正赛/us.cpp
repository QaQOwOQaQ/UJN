#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char c;
    
    c = -1;
    printf("有符号数:%d -> 无符号数:%d\n", c, (unsigned char)c);
    c = -128;	
	printf("有符号数:%d -> 无符号数:%d\n", c, (unsigned char)c);
	cout << "--------------------------------------------------\n";
    c = 127;
    printf("有符号数:%d -> 无符号数:%d\n", c, (unsigned char)c);
    c = 64;
    printf("有符号数:%d -> 无符号数:%d\n", c, (unsigned char)c);
    c = 0;
    printf("有符号数:%d -> 无符号数:%d\n", c, (unsigned char)c);
   
   
   
   
    /*
    int i = -1;
    printf("char = %d", i);
    
    unsigned int i = -1;
    printf("unsigned int = %d", i);
    
    unsigned long long c = -1;
    printf("unsigned long long = %d", ll);
    
    long long c = -1;
    printf("long long = %d", ll);
    */
    return 0;
}
