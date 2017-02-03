#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;



// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main()
{
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
int tc,n,m,a,b,c;
scanf("%d",&tc);
while(tc--)
{ int cost1=0,cost2=0;
vector<int> v;
vector <int> pass;
vector<pair<int,pair<int,int>>> edgelist;
scanf("%d %d",&n,&m);
UnionFind ufds(n+1);
for(int i=0;i<m;i++)
{
scanf("%d %d %d",&a,&b,&c);
edgelist.push_back(make_pair(c,make_pair(a,b)));
}
sort(edgelist.begin(),edgelist.end());
for(int i=0;i<edgelist.size();i++)
{
if(!ufds.isSameSet(edgelist[i].second.first,edgelist[i].second.second))
{
pass.push_back(i);
ufds.unionSet(edgelist[i].second.first,edgelist[i].second.second);
cost1+=edgelist[i].first;

}


}
vector <int> x;
for(int k=0;k<m;k++)
{
if(find(pass.begin(),pass.end(),k)==pass.end())
continue;
int temp=edgelist[k].first;
edgelist[k].first=999999;
sort(edgelist.begin(),edgelist.end());
UnionFind ufds1(n+1);
for(int i=0;i<edgelist.size();i++)
{
if(!ufds1.isSameSet(edgelist[i].second.first,edgelist[i].second.second))
{ufds1.unionSet(edgelist[i].second.first,edgelist[i].second.second);
cost2+=edgelist[i].first;
}


}
x.push_back(cost2);
cost2=0;
edgelist[m-1].first=temp;
sort(edgelist.begin(),edgelist.end());
}
sort(x.begin(),x.end());
cost2=x[0];
printf("%d %d\n",cost1,cost2);



}

    return 0;
}
