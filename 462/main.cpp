#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{ char s[3];
//freopen("test.txt","r",stdin);
//freopen("out.txt","w",stdout);
   int c=1;
   int king[4],queen[4],jack[4],a[4],other[4];
   int stopped[4];
   int sumcard[4];
memset(king,0,sizeof king);
memset(queen,0,sizeof king);
memset(jack,0,sizeof king);
memset(a,0,sizeof king);
memset(other,0,sizeof king);
memset(sumcard,0,sizeof king);
int sum=0;
int maxcost=0;
int trump=0;
string bid;
   while(scanf("%s",s)!=EOF)
   {
   if(s[0]=='K')
   {
            if (s[1]=='S')
            king[0]++;
            else if(s[1]=='H')
            king[1]++;
            else if(s[1]=='D')
            king[2]++;
            else if(s[1]=='C')
            king[3]++;
            sum+=3;
   }

   else if(s[0]=='Q')
   {        if (s[1]=='S')
            queen[0]++;
            else if(s[1]=='H')
            queen[1]++;
            else if(s[1]=='D')
            queen[2]++;
            else if(s[1]=='C')
            queen[3]++;
            sum+=2;
   }
   else if(s[0]=='J')
   {        if (s[1]=='S')
            jack[0]++;
            else if(s[1]=='H')
            jack[1]++;
            else if(s[1]=='D')
            jack[2]++;
            else if(s[1]=='C')
            jack[3]++;
            sum+=1;
   }
   else if(s[0]=='A')
   {        if (s[1]=='S')
            a[0]++;
            else if(s[1]=='H')
            a[1]++;
            else if(s[1]=='D')
            a[2]++;
            else if(s[1]=='C')
            a[3]++;
            sum+=4;
    }
   else
    {      if (s[1]=='S')
           other[0]++;
           else if(s[1]=='H')
           other[1]++;
           else if(s[1]=='D')
           other[2]++;
           else if(s[1]=='C')
           other[3]++;
   }

if (c==13)
{
for(int i=0;i<4;i++)
{sumcard[i]=a[i]+king[i]+queen[i]+jack[i]+other[i];
}
for(int i=1;i<4;i++)
{
if(sumcard[i]>sumcard[maxcost])
maxcost=i;
}
//2 Subtract a point for any king of a suit in which the hand holds no other cards
for(int i=0;i<4;i++)
{//A suit is stopped if it contains an ace, or if it contains a king and at least one other card, or if it
//contains a queen and at least two other cards.
if(a[i] || (king[i] && (jack[i]+queen[i]+other[i]>=1)) ||(queen[i]&& (jack[i]+king[i]+other[i]>=2)) )
stopped[i]=1;
else
stopped[i]=0;
//2. Subtract a point for any king of a suit in which the hand holds no other cards.
if(king[i]!=0 && !queen[i] && !jack[i] && !a[i] && !other[i])
sum-=1;
//3. Subtract a point for any queen in a suit in which the hand holds only zero or one other cards
if(queen[i]!=0 &&((king[i]+jack[i]+a[i]+other[i])<=1))
sum-=1;
//4. Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
if(jack[i]!=0 &&((king[i]+queen[i]+a[i]+other[i])<=2))
sum-=1;}
if(sum >=16 && stopped[0] && stopped[1] && stopped[2] && stopped[3])
{trump=1;
}
for(int i=0;i<4;i++)
{//5. Add a point for each suit in which the hand contains exactly two cards
if((king[i]+queen[i]+a[i]+other[i]+jack[i])==2)
sum+=1;
//6. Add two points for each suit in which the hand contains exactly one card.
if((king[i]+queen[i]+a[i]+other[i]+jack[i])==1)
sum+=2;
//7. Add two points for each suit in which the hand contains no cards
if((king[i]+queen[i]+a[i]+other[i]+jack[i])==0)
sum+=2;
}
if(sum <14 && !trump)
printf("PASS\n");
else if(sum >= 14 && !trump)
{
if(maxcost==0)
printf("BID S\n");
else if(maxcost==1)
printf("BID H\n");
else if(maxcost==2)
printf("BID D\n");
else
printf("BID C\n");
}
else
printf("BID NO-TRUMP\n");
c=0;
sum=0;
maxcost=0;
memset(king,0,sizeof king);
memset(queen,0,sizeof king);
memset(jack,0,sizeof king);
memset(a,0,sizeof king);
memset(other,0,sizeof king);
memset(sumcard,0,sizeof king);
trump=0;
}
c++;
   }

    return 0;
}
