#include <iostream>
#include <vector>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int n,m;
int co=1;
while(scanf("%d %d",&n,&m),(m||n))
{char c;
vector<vector<char>> v(n,vector<char>(m, 0));
cin.ignore();
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
scanf("%c",&c);
if(c=='*')
v[i][j]='*';
else
v[i][j]='0';
}
cin.ignore();
}
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(v[i][j]!='*')
{
if(i-1>=0 && j-1>=0)
{
if(v[i-1][j-1]=='*')
v[i][j]++;
}
if(i-1>=0)
{
if(v[i-1][j]=='*')
v[i][j]++;
}
if(i-1>=0 && j+1<m)
{
if(v[i-1][j+1]=='*')
v[i][j]++;
}
if(j-1>=0)
{
if(v[i][j-1]=='*')
v[i][j]++;
}
if(j+1<m)
{if(v[i][j+1]=='*')
v[i][j]++;
}
if(i+1<n && j-1 >=0)
{
if(v[i+1][j-1]=='*')
v[i][j]++;}

if(i+1<n)
{if(v[i+1][j]=='*')
v[i][j]++;}
if(i+1<n && j+1<m)
{
if(v[i+1][j+1]=='*')
v[i][j]++;
}
}
}}
if(co>1)
cout<<endl;
printf("Field #%d:\n",co++);
for(int i=0;i<n;i++)
{for(int j=0;j<m;j++)
{
cout<<v[i][j];
}
cout<<endl;

}

}
return 0;
}

