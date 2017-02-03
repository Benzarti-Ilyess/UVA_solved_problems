#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
long numberofdays,k,bill;
while(scanf("%ld",&numberofdays),numberofdays)
{
long cost=0;
multiset<int> m;
multiset<int>::iterator ith,itl;
while(numberofdays--)
{
scanf("%ld",&k);
while(k--)
{
scanf("%ld",&bill);
m.insert(bill);
}
ith=m.end();
ith--;
itl=m.begin();
cost+=*ith-*itl;
m.erase(ith);
m.erase(itl);
}
printf("%ld\n",cost);


}
    return 0;
}
