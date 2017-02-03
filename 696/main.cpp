#include <iostream>

using namespace std;

int main()
{ int m,n;
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
    while(scanf("%d %d",&m,&n),(m||n))
    {
    int nb=0,k=0,c=0,d=0;
    if(n==0||m==0)
    {nb=0;
      goto ilyess;}
    if(m==1||n==1)
    nb=n*m;
    else if(n==2||m==2)
    {
            if(m==2)
                k=n;
            else
                k=m;
            c = (k%4==0)?k/4:(k/4)+1;
            d = ((k-1)%4==0)?(k-1)/4:((k-1)/4)+1;
            nb= 2*(c+d);
            }
            else
    nb=(((m + 1)/2) * ((n + 1)/2)) + (((m)/2) * ((n)/2));
   ilyess: printf("%d knights may be placed on a %d row %d column board.\n",nb,m,n);







    }
    return 0;
}
