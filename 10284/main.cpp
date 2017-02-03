#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
vector<string> v;
char c;
int i=1;
string row;
while(scanf("%c",&c)!=EOF)
{
if(c!='/')
row+=c;
else
{ v.push_back(row);
i++;
row="";}
if(i>8)
{
for(int i=0;i<8;i++)
cout<<v[i]<<" ";
cout<<endl;
}
}

    return 0;
}
