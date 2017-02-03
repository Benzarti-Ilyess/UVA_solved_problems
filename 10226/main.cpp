#include <iostream>
#include <map>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int tc;
scanf("%d",&tc);
string line;
float average;
cin.ignore();
getline(cin,line);
while(tc--)
{
map<string,int>::iterator it;
map<string,int> m;
int total=0;
while(getline(cin,line)&& line!="")
{

m[line]++;
total++;

}

for(it=m.begin();it!=m.end();it++)
{
average=((it->second)*100)/(float)total;
cout<<it->first;
printf(" %.4f\n",average);
}
if(tc)
cout<<endl;
}
    return 0;
}
