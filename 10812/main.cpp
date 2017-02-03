#include <iostream>

using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
long long tc,s,d,s1,s2;
cin>>tc;
while(tc--)
{
cin>>s>>d;
s1=abs(s+d)/2;
s2=abs(s-s1);
if((s1+s2==s) && (abs(s1-s2)==d))
cout<<max(s1,s2)<<" "<<min(s1,s2)<<endl;
else
cout<<"impossible"<<endl;






}

return 0;
}
