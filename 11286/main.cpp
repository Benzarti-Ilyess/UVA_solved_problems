#include <iostream>
#include <map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
int n;
int course[5];


while(scanf("%d",&n),n)
{int maxi=-1,repetiton=0;
map<string,int> m;
map<string,int>::iterator it;
for(int i=0;i<n;i++)
{scanf("%d %d %d %d %d",&course[0],&course[1],&course[2],&course[3],&course[4]);
sort(course,course+5);
char s[25];
sprintf(s,"%d%d%d%d%d",course[0],course[1],course[2],course[3],course[4]);
m[s]++;
}
for(it=m.begin();it!=m.end();it++)
{
if(it->second>maxi)
{
maxi=it->second;
repetiton=1;
}
else if(it->second==maxi)
repetiton++;
}
printf("%d\n",maxi*repetiton);
}


return 0;
}
