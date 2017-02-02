#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
string line,oldline;
while( getline(cin,line) && line!="#")
{
if(next_permutation(line.begin(),line.end()))
cout<<line<<endl;
else
cout<<"No Successor"<<endl;




}
    return 0;
}
