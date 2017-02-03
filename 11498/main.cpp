#include <iostream>

using namespace std;

int main()
{ //freopen("test.txt","r",stdin);
int t,dx,dy,x,y;
while(scanf("%d",&t),t)
{
scanf("%d %d",&dx,&dy);
while(t--)
{
scanf("%d %d",&x,&y);
if(x==dx || y== dy)
{
printf("divisa\n");
}
else if(x>dx && y>dy)
{ printf("NE\n");}
else if(x<dx && y>dy)
{
printf("NO\n");
}
else if(x <dx && y <dy)
{
printf("SO\n");
}
else
{printf("SE\n");}

}



}
    return 0;
}
