#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <locale>
#include <cstring>
#include <map>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
char word[21];
string words,wordmodif;
vector <string> v,vmodif;
map <string,int> m;
while(scanf("%s",word) && strcmp(word,"#"))
{
words=word;
v.push_back(words);
}
sort(v.begin(),v.end());
vmodif=v;
for(int i=0;i<vmodif.size();i++)
{
for(int j=0;j<vmodif[i].length();j++)
{
if(isupper(vmodif[i][j]))
vmodif[i][j]+='a'-'A';
}}
for(int i=0;i<vmodif.size();i++)
{
sort(vmodif[i].begin(),vmodif[i].end());
}
for(int i=0;i<vmodif.size();i++)
{
m[vmodif[i]]++;
}
for(int i=0;i<vmodif.size();i++)
{
if(m[vmodif[i]]==1)
cout<<v[i]<<endl;


}

    return 0;
}
