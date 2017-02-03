#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
string ligne;
map<char,char> m;
m['A']='A';
m['E']='3';
m['H']='H';
m['I']='I';
m['J']='L';
m['L']='J';
m['M']='M';
m['O']='O';
m['S']='2';
m['T']='T';
m['U']='U';
m['V']='V';
m['W']='W';
m['X']='X';
m['Y']='Y';
m['Z']='5';
m['1']='1';
m['2']='S';
m['3']='E';
m['5']='Z';
m['8']='8';
while(getline(cin,ligne))
{ bool palindrome=true;
    bool mirrored=true;
{for(int i=0;i<ligne.length()/2;i++)
{
if(ligne[i]!=ligne[ligne.length()-1-i])
    {palindrome=false;
    break;}
    }
if(ligne.length()==1 && m[ligne[0]]!=ligne[0])
{
mirrored=false;
}
if((ligne.length()%2)!=0)
{
if(m[ligne[(ligne.length()/2)]]!=ligne[(ligne.length()/2)])
{
mirrored=false;
}
}

    for(int i=0;i<ligne.length()/2;i++)
{

if(ligne[i]!=m[ligne[ligne.length()-1-i]])
   { mirrored=false;
    break;}
    }
if(palindrome && !mirrored)
cout<<ligne<<" -- is a regular palindrome."<<endl;
else if(!palindrome && !mirrored)
cout<<ligne<<" -- is not a palindrome."<<endl;
else if(palindrome && mirrored)
cout<<ligne<<" -- is a mirrored palindrome."<<endl;
else if(!palindrome && mirrored)
cout<<ligne<<" -- is a mirrored string."<<endl;
}
cout<<endl;
}
    return 0;
}
