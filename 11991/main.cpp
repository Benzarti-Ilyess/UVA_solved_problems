#include <iostream>
#include<vector>
#define Max 1000000
using namespace std;
typedef vector<int> vi;
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    int n,m,x,k,V;

    while(scanf("%d %d",&n,&m)!=EOF)
    {     vector<vi> AdjList(Max);


        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            AdjList[x].push_back(i+1);
        }

        while(m--)
        {
            scanf("%d %d",&k,&V);
            if(AdjList[V].size()>=k)
            printf("%d\n",AdjList[V][k-1]);
            else
            printf("0\n");

        }



    }




    return 0;
}
