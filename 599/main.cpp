#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
class UnionFind {                                              // OOP style
private:
  vi p, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
vi rank;
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
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int tc;
string line,vertices;
scanf("%d",&tc);
getline(cin,line);
while(tc--)
{ UnionFind ufds(26);
set<int> s;
int c=0;
while(getline(cin,line)&& line[0]!='*')
{
int node1=line[1]-'A';
int node2=line[3]-'A';
ufds.unionSet(node1,node2);
}
getline(cin,vertices);
int virgule=0;
while(find(vertices.begin(),vertices.end(),',')!=vertices.end())
{
vertices.erase(find(vertices.begin(),vertices.end(),','));
}
for(int i=0;i<vertices.length();i++)
{
int node=vertices[i]-'A';
if(ufds.rank[node]!=0)
s.insert(ufds.findSet(node));
else if(ufds.rank[node]==0 && ufds.findSet(node)==node)
c++;
}
cout<<"There are "<<s.size()<<" tree(s) and "<<c<<" acorn(s)."<<endl;
}

    return 0;
}
