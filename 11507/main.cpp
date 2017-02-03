#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

int main()
{ int l;
char s[3];
freopen("test.txt","r",stdin);
while(scanf("%d",&l),l)
{
string prevp="+x";
for(int j=0;j<l-1;j++)
{scanf("%s",s);
if(s[0]=='+')
{
if(s[1]=='y')
{
if(prevp=="+x")
{
prevp="+y";
}
else if(prevp=="-x")
{
prevp="-y";
}
else if(prevp=="+y")
{
prevp="-x";
}
else if(prevp=="-y")
{
prevp="+x";
}
else if(prevp=="-z")
{
prevp="-z";
}
else if(prevp=="+z")
{
prevp="+z";
}


}
else if (s[1]=='z')
{
if(prevp=="+x")
{
prevp="+z";
}
else if(prevp=="-x")
{
prevp="-z";
}
else if(prevp=="+y")
{
prevp="+y";
}
else if(prevp=="-y")
{
prevp="-y";
}
else if(prevp=="-z")
{
prevp="+x";
}
else if(prevp=="+z")
{
prevp="-x";
}
}


}
else if(s[0]=='-')
{
if(s[1]=='y')
{
if(prevp=="+x")
{
prevp="-y";
}
else if(prevp=="-x")
{

prevp="+y";
}
else if(prevp=="+y")
{

prevp="+x";
}
else if(prevp=="-y")
{

prevp="-x";
}
else if(prevp=="-z")
{

prevp="-z";
}
else if(prevp=="+z")
{

prevp="+z";
}









}
else if (s[1]=='z')
{
if(prevp=="+x")
{
prevp="-z";
}
else if(prevp=="-x")
{
prevp="+z";
}
else if(prevp=="+y")
{
prevp="+y";
}
else if(prevp=="-y")
{
prevp="-y";
}
else if(prevp=="-z")
{
prevp="-x";
}
else if(prevp=="+z")
{
prevp="+x";
}

}

}
}
cout<<prevp<<endl;

}

    return 0;
}
