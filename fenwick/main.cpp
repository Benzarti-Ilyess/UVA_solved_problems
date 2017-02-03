#include <iostream>
#include<vector>
#define LSOne(i) (i&(-i))
using namespace std;
typedef vector<int> vi;
class fenwicktree
{
private: vi ft;
public: fenwicktree(int n) {ft.assign(n+1,0);}
int rsq(int b)
{
int sum=0;for(;b;b+=LSOne(b)) sum+=ft[b];
return sum;
}
int rsq(int a,int b)
{
return(b)-(a==1 ? 0 :rsq(a-1));
}
void adjust(int k,int v)
{

for(;k<(int)ft.size();k+=LSOne(k))
ft[k]+=v;
}





};
int main()
{
int f[]={2,4,5,5,6,6,6,7,7,8,9};
fenwicktree ft(10);
for(int i=0;i<11;i++)
{
ft.adjust(f[i],1);
for(int i=0;i<11;i++)
cout<<"ft[]"
}
    return 0;
}
