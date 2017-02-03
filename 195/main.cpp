#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare (char a, char b)
{
    bool minisculaA = true, minisculaB = true;
    if (a >= 'A' && a <= 'Z')
        minisculaA = false;
    if (b >= 'A' && b <= 'Z')
        minisculaB = false;

    //Both are upper or lower case
    if (minisculaA && minisculaB)
        return a < b;
    if (!minisculaA && !minisculaB)
        return a < b;

    //a it's a lowercase
    if (minisculaA)
    {
        a -= ('a'-'A');
        return a < b;
    }
    else
    {
        b -= ('a'-'A');
        return a <= b;
    }
}
int main()
{
   //freopen("test.txt","r",stdin);
   // freopen("answer.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    cin.ignore();
    while(tc--)
    {
        string mot;
        getline(cin,mot);
        sort(mot.begin(),mot.end(),compare);
        do
        {
            cout<<mot<<endl;
        }
        while(next_permutation(mot.begin(),mot.end(),compare));

    }
return 0;
}
