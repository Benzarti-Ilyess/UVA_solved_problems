#include <iostream>

using namespace std;

int main()
{ int t,a,b,c,co=1;
scanf("%d",&t);
while(t--)
{
scanf("%d %d %d",&a,&b,&c);
if((a >b && a < c) ||(a > c && a < b))
{
printf("Case %d: %d\n",co++,a);
}
else if((b>a && b<c)||(b > c && b <a))
 {printf("Case %d: %d\n",co++,b);}
 else
 {
 printf("Case %d: %d\n",co++,c);
 }


}
    return 0;
}
