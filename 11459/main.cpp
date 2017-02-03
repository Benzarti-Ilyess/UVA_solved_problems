#include <iostream>
#include <vector>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
    int tc,a,b,c,bottom,top,nrod;

    scanf("%d",&tc);
    while(tc--)
    {
        int p=0;
        int nb=0;
        int q,r;
        bool found=false,trouve=false;
        vector<int> bottom_top;
        vector<int> pos;
        scanf("%d %d %d",&a,&b,&c);
        for(int i=0; i<b; i++)
        {
            scanf("%d %d",&bottom,&top);
            bottom_top.push_back(bottom);
            bottom_top.push_back(top);

        }
        if(c>a)
        {
            q=c/a;
            r=c%a;
            for(int i=0; i<a; i++)
                pos.push_back(1);
            while(q--)
            {
                for(int i=0; i<a; i++)
                {
                    scanf("%d",&nrod);
                    if(pos[i]<100 && !trouve)
                    {
                        pos[i]+=nrod;
                        for(int j=0; j<bottom_top.size(); j+=2)
                        {
                            if(pos[i]==bottom_top[j] && !trouve)
                            {
                                pos[i]+=bottom_top[j+1]-bottom_top[j];
                                break;
                            }
                        }
                    }
                    if(pos[i]>=100 && !trouve)
                    {
                        pos[i]=100;
                        trouve=true;
                    }
                }
            }
            for(int i=0; i<r; i++)
            {
                scanf("%d",&nrod);
                if(pos[i]<100 && !trouve)
                    pos[i]+=nrod;
                if(pos[i]>=100 && !trouve)
                {
                    pos[i]=100;
                    trouve=true;
                }
            }
            for(int i=0; i<a; i++)
            {
                printf("Position of player %d is %d.\n",i+1,pos[i]);
            }
        }
        else
        {
            for(int i=1; i<=c; i++)
            {

                scanf("%d",&nrod);
                p=1;
                if(!trouve)
                    p+=nrod;
                for(int j=0; j<bottom_top.size(); j+=2)
                {
                    if(p==bottom_top[j] && !trouve)
                    {
                        p+=bottom_top[j+1]-bottom_top[j];
                        break;
                    }
                }
                if(p>=100 && !trouve)
                {
                    p=100;
                    trouve=true;
                }
                printf("Position of player %d is %d.\n",i,p);
                nb=i;
            }
            for(int k=nb+1; k<=a; k++)
                printf("Position of player %d is 1.\n",k);
        }
        }
    return 0;
}
