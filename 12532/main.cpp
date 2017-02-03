
//fenwick tree
#include <iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
#define LSOne(S) (S & (-S))
class FenwickTree
{
private:
    vi ft;

public:
    FenwickTree() {}
    // initialization: n + 1 zeroes, ignore index 0
    FenwickTree(int n)
    {
        ft.assign(n + 1, 0);
    }

    int rsq(int b)                                       // returns RSQ(1, b)
    {
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b)                                // returns RSQ(a, b)
    {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v)                      // note: n = ft.size() - 1
    {
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};

int main()
{
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
    int n,k,x,number1,number2;
    char command;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        vector<int> v(n,0);
        FenwickTree ftneg(n),ftzero(n);
        for(int i=0; i<n; i++)
        {
            scanf("%d ",&v[i]);
            if(v[i]<0)
                ftneg.adjust(i+1,1);
            else if(v[i]==0)
                ftzero.adjust(i+1,1);
        }
        while(k--)
        {
            scanf("%c %d %d\n",&command,&number1,&number2);
            if(command=='C')
            {
                if(v[number1-1]==0 && number2!=0)
                {
                    ftzero.adjust(number1,-1);
                    if(number2<0)
                        ftneg.adjust(number1,1);
                }
                else if(v[number1-1]<0 && number2 >=0)
                {
                    ftneg.adjust(number1,-1);
                    if(!number2)
                        ftzero.adjust(number1,1);
                }
                else if(v[number1-1]>0 && number2<=0)
                {
                    if(number2)
                        ftneg.adjust(number1,1);
                    else
                        ftzero.adjust(number1,1);

                }
                v[number1-1]=number2;

            }



            else if(command=='P')
            {
                if(ftzero.rsq(number1,number2))
                    printf("0");
                else if(ftneg.rsq(number1,number2)%2==0)
                    printf("+");
                else
                    printf("-");

            }


        }
        printf("\n");





    }
    return 0;
}
