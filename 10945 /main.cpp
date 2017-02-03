#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
string ligne;

while(getline(cin,ligne) && ligne!="DONE")
{string lignemodif;
bool palaindrome=true;
for(int i=0;i<ligne.length();i++)
{
if(ligne[i]!=' ' && ligne[i]!='.' && ligne[i]!=',' && ligne[i]!='!' && ligne[i]!='?')
{
if(isupper(ligne[i]))
{
lignemodif+=ligne[i]+ 'a'-'A';
}
else
lignemodif+=ligne[i];
}

}
for(int i=0;i<lignemodif.length()/2;i++)
{
if(lignemodif[i]!=lignemodif[lignemodif.length()-1-i])
{palaindrome=false;
break;
}
}
if(palaindrome)
cout<<"You won't be eaten!"<<endl;
else
cout<<"Uh oh.."<<endl;

}
    return 0;
}
