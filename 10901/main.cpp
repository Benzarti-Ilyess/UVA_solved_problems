#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
int tc,n,m,t,x;
string positionc,positionbridge;
scanf("%d",&tc);
while(tc--)
{ queue<pair<int,string>> q;
scanf("%d %d %d",&n,&t,&m);
while(m--)
{scanf("%d",&x);
cin>>positionc;
q.push(make_pair(x,positionc));



}
int time=0;
int prev=-1;
positionbridge="left";
while(!q.empty())
{
if(q.front().first<=time || q.front().first==0 )
{
if(q.front().second==positionbridge)
{
time+=t;
cout<<time<<endl;
if(positionbridge=="left")
positionbridge="right";
else
positionbridge="left";
}
else
{time+=2*t;
cout<<time<<endl;
}
else if(q.front().first!=0)
{
time+=q.front().first-time;
if(q.front().second==positionbridge)
{
time+=t;
cout<<t<<endl;
if(positionbridge=="left")
positionbridge="right";
else
positionbridge="left";
}
else
{time+=2*t;
cout<<time<<endl;
}




}
}
else
cout<<time<<endl;
prev=q.front().first;

q.pop();


}
/*while(!q.empty())
{
cout <<q.front().first<<" "<<q.front().second<<endl;
q.pop();


}*/
}
    return 0;
}
