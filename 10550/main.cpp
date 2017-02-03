#include <stdio.h>
int main()
{
    int a,b,c,d,temp,deg;
  //  freopen("test.txt","r",stdin);
    while(scanf("%d %d %d %d",&a,&b,&c,&d)== 4,(a||b ||c ||d))
    {
     deg=1080;
     temp=a-b;
     if(temp<0)temp=temp+40;
     deg+=temp*9;
     temp=c-b;
     if(temp<0)temp=temp+40;
     deg+=temp*9;
     temp=c-d;
     if(temp<0)temp=temp+40;
     deg+=temp*9;
     printf("%d\n",deg);
    }



    return 0;
}
