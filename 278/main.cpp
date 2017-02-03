#include <iostream>
#include <string>
using namespace std;

int main()
{
int tc,m,n;
char c;
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
cin>>tc;
cin.ignore();
while(tc--)
{ int nb=0;
cin>>c>>m>>n;
cin.ignore();
if(c=='r')
nb=min(m,n);
else
if(c=='Q')
nb=min(m,n);
else if(c=='k')
nb=(((m + 1)/2) * ((n + 1)/2)) + (((m)/2) * ((n)/2));
else if(c=='K')
nb=(((m + 1)/2) * ((n + 1)/2));
cout<<nb<<endl;
}

    return 0;
}
