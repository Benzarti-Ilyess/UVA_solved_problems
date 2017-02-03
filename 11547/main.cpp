#include <iostream>

using namespace std;

int main()
{
int t,n,x;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
x=(((((n*567)/9)+7492)*235)/47)-498;
x=(x/10)%10;
printf("%d\n",abs(x));



}
    return 0;
}
