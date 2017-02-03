#include <iostream>
#include <cstdio>
using namespace std;

int main()
{ int n,x,c=1;
//freopen("test.txt","r",stdin);
while(scanf("%d",&n),n)
{ int eb=0,noesgt=0,noeagt=0;
while(n--)
{
scanf("%d",&x);
if(x)
noesgt++;
else
noeagt++;

}
printf("Case %d: %d\n",c++,noesgt-noeagt);



}
    return 0;
}
