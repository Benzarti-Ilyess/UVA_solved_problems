#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    float h,m;
    float angle=0.0,anglehour,anglemin;
    while(scanf("%f:%f",&h,&m)==2,(h||m))
    {
        anglehour=30.0*h+(m/60)*30.0;
        anglemin=6.0*m;
        if(abs(anglehour-anglemin)<=180)
            angle=abs(anglehour-anglemin);
        else
            angle=360.0-abs(anglehour-anglemin);
        printf("%.3f\n",angle);
    }
    return 0;
}
