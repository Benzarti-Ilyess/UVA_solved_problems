#include <iostream>
#include <string>
#include<cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef vector<int> vi;
int cti(char a)
{


    return a-'A';
}
struct brain
{
    int adjmat[26][26];
    vector<int> awakenn;
};
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
    int sleptareas;

    while(cin>>sleptareas)
    {
int adjmat[26][26];
for(int i=0;i<26;i++)
for(int j=0;j<26;j++)
adjmat[i][j]=0;
   UnionFind ufds(sleptareas);
    map<char,int> m;
    set<int> s;
    vector<int> woken;
    string connection;
        int numberofconnections;
    cin>>numberofconnections;
        string awaken;
        cin>>awaken;
        int c=1;
        m[awaken[0]]=c;
        s.insert(c);
        woken.push_back(c);
        c++;
         m[awaken[1]]=c;
         s.insert(c);
         woken.push_back(c);
        c++;
         m[awaken[2]]=c;
         s.insert(c);
         woken.push_back(c);
        c++;
        ufds.unionSet( m[awaken[0]], m[awaken[1]]);
        ufds.unionSet( m[awaken[1]], m[awaken[2]]);
        int x=numberofconnections;
        while(numberofconnections--)
        {
            cin>>connection;
            if(!m[connection[0]])
            {m[connection[0]]=c;
            s.insert(c);
            c++;

            }
            if(!m[connection[1]])
            {m[connection[1]]=c;
            s.insert(c);
            c++;
            }
        adjmat[m[connection[0]]][m[connection[1]]]=1;
        adjmat[m[connection[1]]][m[connection[0]]]=1;
        }
        int cell=0;
        for(int i=3;i<sleptareas;i++)
        {
        for(int j=0;j<woken.size();j++)
        {if(adjmat[i][woken[j]]==1)
        cell++;
        if(cell==3)
        woken.push_back(i);
        cell=0;
        }

        }
        for(int i=0;i<woken.size()+1;i++)
        cout<<woken[i]<<" ";
        cout<<endl;


/*for(int i=1;i<s.size()+1;i++)
{
for(int j=1;j<s.size()+1;j++)
{cout<<adjmat[i][j]<<" ";
 }
 cout<<"\n";
 }*/
    }
    return 0;
}
