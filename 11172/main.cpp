#include <iostream>

using namespace std;

int main()
{
int tc;
int a,b;
scanf("%d",&tc);
while(tc--)
{
scanf("%d %d",&a,&b);
if(a > b)
{
printf(">\n");
}
if(a < b)
{
printf("<\n");
}
if(a==b)
printf("=\n");
}
    return 0;
}
