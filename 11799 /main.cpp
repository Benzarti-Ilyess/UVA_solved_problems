#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
int t,n,c;
scanf("%d",&t);
int k=1;
while(t--)
{ int cc=-1;
scanf("%d",&n);
while(n--)
{
scanf("%d",&c);
cc=max(cc,c);


}
printf("Case %d: %d\n",k++,cc);


}
    return 0;
}
