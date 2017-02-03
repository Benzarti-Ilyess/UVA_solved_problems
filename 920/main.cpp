#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct point_i { int x, y;
point_i() { x = y = 0; }
point_i(int _x, int _y) : x(_x), y(_y) {} };
bool cmp(point_i a,point_i b)
{
return a.x<b.x;

}



int main()
{
    freopen("test.txt","r",stdin);
    freopen("answer.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    while(tc--)
    { int n;
        double distance;
        vector<point_i> v;
    scanf("%d",&n);
    while(n--)
    { int x,y;
    scanf("%d %d",&x,&y);
    v.push_back(point_i(x,y));


}
sort(v.begin(),v.end(),cmp);
for(int i=1;i<v.size();i++)
{
if(v[i].y<v[i+2].y)
{
v.erase(v.begin()+i);

}

}
for(int i=0;i<v.size();i++)
{
cout<<v[i].x<<" "<<v[i].y<<endl;
}






    }
    return 0;
}
