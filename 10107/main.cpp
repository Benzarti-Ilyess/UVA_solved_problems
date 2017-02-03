#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
 //freopen("test.txt","r",stdin);
 //freopen("answer.txt","w",stdout);
 int x;
 vector<int> v;
 while(scanf("%d",&x)!=EOF)
 {
 v.push_back(x);
 sort(v.begin(),v.end());
 /*for(int i=0;i<v.size();i++)
 cout<<v[i]<<" ";
 cout<<endl;*/

if(v.size()%2!=0)
 cout<<v[v.size()/2]<<endl;
 else
 {x=v[v.size()/2]+v[(v.size()/2) -1];
 cout<<x/2<<endl;
}


 }
    return 0;
}
