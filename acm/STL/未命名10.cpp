#include <iostream>
#include <set>
#include <sstream>
using namespace std;
 int main()
 {
     string str,ch;
     set <string> si;
 
     while( cin>>str)
     {
 
	for(int i=0;i<str.length();i++)
	{
		if(!isalpha(str[i]))
		//	str[i]=tolower(str[i]);
	//	else
			str[i]=' ';
	}
         stringstream temp(str);   //分割成一个个单词
         while( temp>>ch )
            si.insert( ch );
     }
 
     set<string>::iterator S = si.begin();
     while( S != si.end() )
     {
         cout<<*S<<endl;
         S++;
     }
     return 0;
 }
