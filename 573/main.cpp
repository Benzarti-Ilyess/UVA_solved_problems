#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{ float h,u,d,f;
    while(scanf("%f %f %f %f",&h,&u,&d,&f),h)
    { int c=0;
    float dc,hac,has,i;
    hac=0.0;
    has=0.0;
    i=0.0;
    dc=u;
    while(hac <=h && has >=0)
    {

    hac=i+dc;
    has=hac-d;
    i=has;
    if(dc >0)
    dc-=(u*f)/100;
c++;
    }
    if(hac >=h)
    printf("success on day %d\n",c);
else if(has <=0 )
printf("failure on day %d\n",c);

    }
    return 0;
}
