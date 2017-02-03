#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    string ligne;
    cin.ignore();
    int c=1;
    while(tc--)
    {
        string lignemodif="",way1="",way2="",way3="",way4="";
        int k=0,x=0;
        cout<<"Case #"<<c++<<":"<<endl;
        getline(cin,ligne);
        for(int i=0; i<ligne.length(); i++)
        {
            if(isalpha(ligne[i]))
            {
                lignemodif+=ligne[i];
            }
        }
        for(int i=1; i<=100; i++)
        {
            if(i*i==lignemodif.length())
            {
                k=i;
                break;
            }
        }
        if(k)
        {
            vector <vector<char> > v(k, vector<char>(k, '0'));
            for(int i=0; i<k; i++)
            {
                for(int j=0; j<k; j++)
                {
                    v[i][j]=lignemodif[x++];
                }
            }
             /*for(int i=0; i<k; i++)
            {
                for(int j=0; j<k; j++)
                {
                    cout<<v[i][j];
                }
                cout<<endl;
            }*/


            way1=lignemodif;
            for(int j=0; j<k; j++)
            {
                for(int i=0; i<k; i++)
                {
                    way2+=v[i][j];
                }
            }

            for(int i=k-1; i>=0; i--)
            {
                for(int j=k-1; j>=0; j--)
                {
                    way3+=v[i][j];
                }
            }
            for(int j=k-1; j>=0; j--)
            {
                for(int i=k-1; i>=0; i--)
                {
                    way4+=v[i][j];

                }

            }
if(way1==way2 && way1==way3 && way1==way4)
cout<<k<<endl;
else
 cout<<"No magic :("<<endl;







        }
        else
            cout<<"No magic :("<<endl;

    }
    return 0;
}
