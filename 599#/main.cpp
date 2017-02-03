#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cctype>
#include<bitset>
using namespace std;
typedef vector<int>   vi;
int main()
{
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
int tc;
string line,vertices;
scanf("%d",&tc);
getline(cin,line);
while(tc--)
{ vector<vi> AdjList;
int c=0;
bitset<26> b;
AdjList.assign(26,vi());
while(getline(cin,line)&& line[0]!='*')
{ c++;
int node1=line[1]-'A';
int node2=line[3]-'A';
AdjList[node1].push_back(node2);
AdjList[node2].push_back(node1);
}
getline(cin,vertices);
int virgule=0;
while(find(vertices.begin(),vertices.end(),',')!=vertices.end())
{
vertices.erase(find(vertices.begin(),vertices.end(),','));
}
for(int i=0;i<vertices.length();i++)
{
for(int j=0;j<vertices.length();j++)
{
if(i!=j)
{
if(!AdjList[i][j])
b.set(i);
}
}
    }




/*int ac=0,acc=0;
for(int i=vertices[0]-'A';i<vertices[vertices.length()-1]-'A';i++)
{for(int j=vertices[0]-'A';j<vertices[vertices.length()-1]-'A';j++)
{ if(i!=j)
{
if(AdjList[i][j]==0)
{ac++;}

}

}
if(ac==vertices.length())
b.set(i);

ac=0;
}*/


cout<<"There are "<<vertices.size()-c-b.count()<<" tree(s) and "<<b.count()<<" acorn(s)."<<endl;
}
    return 0;
}
