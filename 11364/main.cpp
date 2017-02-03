#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{ int t,l=99,h=0,n,x;
scanf("%d",&t);
while(t--)
{ l=99;
h=0;
scanf("%d",&n);
while(n--)
{scanf("%d",&x);
l=min(l,x);
h=max(h,x);
}
printf("%d\n",2*(h-l));
}
    return 0;
}
