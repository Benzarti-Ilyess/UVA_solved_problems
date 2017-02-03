#include <iostream>
#include <string>
using namespace std;

int main()
{ char c;
string game;
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
int score=0;
int bonus=0;
while(scanf("%c",&c) && c!='G')
{
if(c!='\n' && c!=' ')
{
game+=c;
}




else if(c=='\n')
{
for(int i=2;i<game.length()+2;i+=2)
{
if(game[i-2]!='X' && (game[i-1]!='/' || game[i-1]!='X'))
{
score+=game[i-2]+game[i-1]-'0'-'0';
}

else if(game[i-2]=='X')
{
score+=10;
if(game[i-1]!='X')
score+=game[i-1]-'0';
else if(game[i-1]=='X')
{
score+=10;}
if(game[i]!='X' && game[i]!='/')
score+=game[i]-'0';
else
score+=10;
i--;
}

}



cout<<score<<endl;
game="";
}



}


    return 0;
}
