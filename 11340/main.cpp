#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
int tc,k,p,nbl;
char c,x;
string line;
scanf("%d",&tc);
while(tc--)
{ double price=0.0;
map<char,int> m;
scanf("%d",&k);
for(int i=0;i<k;i++)
{
cin>>c>>p;
m[c]=p;
}
scanf("%d",&nbl);
cin.ignore();
while(nbl--)
{
getline(cin,line);
for(int i=0;i<line.length();i++)
{
if(m[line[i]]!=0)
price+=m[line[i]];
}
}
price=price/100;
printf("%.2f$\n",price);





}

    return 0;
}
