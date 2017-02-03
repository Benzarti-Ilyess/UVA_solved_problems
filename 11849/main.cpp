#include <iostream>
#include <set>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
long m,n,cd,bothown;
while(scanf("%ld %ld",&n,&m),(n||m))
{ set<long> s;
for(int i=0;i<n;i++)
{
scanf("%ld",&cd);
s.insert(cd);
}
for(int i=0;i<m;i++)
{
scanf("%d",&cd);
s.insert(cd);
}
bothown=m+n-s.size();
printf("%ld\n",bothown);



}
    return 0;
}
