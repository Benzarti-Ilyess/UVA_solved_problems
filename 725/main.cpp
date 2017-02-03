#include <iostream>
#include <map>
using namespace std;
void divise(int abcde,int &e ,int &d,int &c, int & b,int & a)
{
    e=abcde%10;
    d=(abcde%100)/10;
    c=(abcde%1000)/100;
    b=(abcde%10000)/1000;
    a=(abcde%100000)/10000;
}
int main()
{ //freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
    map<int,int> m;
    int n;
int c=0;
    while(scanf("%d",&n),n)
    { if(c)
    printf("\n");
    c++;
    bool found=false;
        int a,b,c,d,e,f,g,h,i,j,fghij;
        for(int abcde=1234*n; abcde <=98765; abcde++)
        {
      fghij=abcde/n;
        if(n * fghij==abcde)
              {
              divise(abcde,e,d,c,b,a);
              divise(fghij,j,i,h,g,f);
                m[j]++;
                m[i]++;
                m[h]++;
                m[g]++;
                m[f]++;
                m[e]++;
                m[d]++;
                m[c]++;
                m[b]++;
                m[a]++;
if(m[0]==1 && m[1]==1 && m[2]==1 && m[3]==1  && m[4]==1  && m[5]==1  && m[6]==1  && m[7]==1  && m[8]==1 && m[9]==1  )
                {

            printf("%05d / %05d = %d\n",abcde,fghij,n);
            found=true;

                }
                m.clear();
            }

        }
        if(!found)
        printf("There are no solutions for %d.\n",n);
        }



        return 0;
    }
