#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main()
{
long t;
long c=1;
string s;
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
  while(scanf("%ld",&t)!=EOF)
{ vector <string> vdeck,vhand,vstayed;
int y=0;
int x=0;
string card;
int delete_from_size=0;
for(int i=0;i<52;i++)
{
//scanf("%s",s);
cin>>s;
vdeck.push_back(s);
}
for(int i=0;i<25;i++)
{vhand.push_back(vdeck[27+i]);
}
for(int i=0;i<27;i++)
vstayed.push_back(vdeck[i]);
for(int i=0;i<3;i++)
{card=vstayed[vstayed.size()-1];
x=card[0]-48;
if(x>9)
x=10;
y+=x;
delete_from_size=1+(10-x);
for(int i=0;i<delete_from_size;i++)
vstayed.pop_back();
}
for(int i=0;i<vhand.size();i++)
vstayed.push_back(vhand[i]);
if(c>1)
cout<<endl;
cout<<"Case "<<c++<<": "<<vstayed[y-1];
}

    return 0;
}
