#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{int x,n,d;
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
while(scanf("%d",&n)!=EOF)
{ vector<int> v,verif;
  vector<int>::iterator j;
  bool jolly=true;
for(int i=0;i<n;i++)
{
scanf("%d",&x);
v.push_back(x);
}
for(int i=1;i<n;i++)
{
d=abs(v[i-1]-v[i]);
verif.push_back(d);
}
sort(verif.begin(),verif.end());
for(int i=0;i<verif.size();i++)
{
if(verif[i]!=i+1)
{
jolly=false;
break;
}
}
if(jolly)
cout<<"Jolly"<<endl;
else
cout<<"Not jolly"<<endl;



}
    return 0;
}
