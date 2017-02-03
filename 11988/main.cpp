#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
string line;
list<char> l;
list<char>::iterator it;
it=l.begin();
while(getline(cin,line))
{
for(int i=0;i<line.length();i++)
{
if(line[i]=='[')
it=l.begin();
else if (line[i]==']')
it=l.end();
else
l.insert(it,line[i]);
}
for(it=l.begin();it!=l.end();it++)
printf("%c",*it);
printf("\n");
l.clear();


}






    return 0;
}
