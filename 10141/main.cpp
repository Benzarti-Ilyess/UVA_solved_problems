#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{ int n,p;
double d;
string x;
int c=1;
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
while(scanf("%d %d",&n,&p),(n||p))
{ string req;
int precompilance=-1;
int compilancenow=0;
double pricenow=0.0;
double prevprice=10000000000.0;
string rfp;
getline(cin,x);
for(int i=0;i<n;i++)
{

getline(cin,req);
}
string prop;
for(int i=0;i<p;i++)
{
getline(cin,prop);
scanf("%lf %d",&d,&compilancenow);
pricenow=d;
string namereq;
getline(cin,x);
//compilancenow=(r/(double)n);
if(compilancenow > precompilance)
{rfp=prop;
precompilance=compilancenow;
prevprice=pricenow;}
else if((compilancenow==precompilance) && (pricenow < prevprice))
{
rfp=prop;
precompilance=compilancenow;
prevprice=pricenow;
}
/*else if((compilancenow==precompilance) && (pricenow==prevprice ))
{
if(rfp=="")
rfp=prop;

}*/
for(int k=0;k<compilancenow;k++)
{
getline(cin,namereq);


}
precompilance=compilancenow;
prevprice=pricenow;
}
printf("RFP #%d\n",c++);
cout <<rfp<<endl;
printf("\n");


}
    return 0;
}
